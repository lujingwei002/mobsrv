#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

/* 
 * rptr rlen rskip 配合使用，用于写socket
 * rptr = SendBuf.rptr()
 * rlen = SendBuf.datalen()
 * sent = send sockfd rptr rlen
 * SendBuf.rskip(sent)
 *
 * flush 和 alloc配合使用, 用于写buff
 * buf = SendBuf.alloc(sockfd, size)
 * write buf
 * SendBuf.flush(sockfd, buf, len)
 *
 */
 
#ifndef NULL
#define NULL 0
#endif

typedef struct BBuf_Block{
	struct BBuf_Block *next;
	int buf_size;  //buf的大小 
    int buf_len;   //buf已经使用的大小 
	int rptr;      //读指针
    int unuse;     //字节对齐
	char buf[0];
}BBuf_Block;

typedef struct BBuf{
	BBuf_Block *block_head;
	BBuf_Block *block_tail;
}BBuf;

#define MAX_SOCKET 65536
#define MAX_TABLE 32

static BBuf bbufs[MAX_SOCKET];
static BBuf_Block *block_table[MAX_TABLE];
#define fd2bbuf(sockfd) (&bbufs[sockfd])

#define assert_sockfd(sockfd) if(sockfd <= 0 || sockfd >= MAX_SOCKET){\
                        printf("sockfd(%d) is invalid", sockfd);\
                        return 0;\
                     }
static int hash(unsigned int size){
	unsigned int index = 0;
	while(((unsigned int)(1<<index)) < size){
        index++;
	}
	return index;
}

static void bbuf_free_block(BBuf_Block *block){
    //printf("free block :%d/%d\n", block->buf_len, block->buf_size);
	int idx = hash(block->buf_size + sizeof(BBuf_Block));
	if(block_table[idx] == NULL){
		block->next = NULL;
		block_table[idx] = block;
	}else{
		block->next = block_table[idx];
		block_table[idx] = block;
	}
}

int lstat(lua_State *L){
	int i;
	int sum = 0;
    printf("==========SEND BBUF==========\n");
	for(i = 0; i < MAX_TABLE; i++){
		int count = 0;
		BBuf_Block *head = block_table[i];
		while(head){
			count++;
			head = head->next;
		}
		sum += (1<<i)*count;
        if(count > 0){
		    printf("%d => %d\n", i, count);
        }
	}
    sum = sum / 1024;
	printf("total mem :%dk\n", sum);
    return 0;
}

int sendbuf_create(int sockfd)
{
	bbufs[sockfd].block_head = NULL;
	bbufs[sockfd].block_tail = NULL;
    return 0;
}

static int lcreate(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    sendbuf_create(sockfd);
    return 0;
}

int sendbuf_free(int sockfd){
	BBuf *self = fd2bbuf(sockfd);
    BBuf_Block *block = self->block_head;
    while(block != NULL){
        BBuf_Block* next = block->next;
        bbuf_free_block(block);
        block = next;
    }
    return 0;
}

static int lfree(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    sendbuf_free(sockfd);
    return 0;
}

char* sendbuf_get_read_ptr(int sockfd){
	BBuf *self = fd2bbuf(sockfd);
	if(self->block_head == NULL){
		return NULL;
	}
	char *ptr = self->block_head->buf + self->block_head->rptr;
    return ptr;
}


static int lget_read_ptr(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    char *ptr = sendbuf_get_read_ptr(sockfd);
    if (ptr == NULL) {
        return 0;
    }
    lua_pushlightuserdata(L, ptr);
    return 1;
}

int sendbuf_datalen(int sockfd){
	BBuf *self = fd2bbuf(sockfd);
	if(!self->block_head){
		return 0;
	}
	int len = self->block_head->buf_len - self->block_head->rptr;
    return len;
}

static int ldatalen(lua_State *L){
    int sockfd;
    sockfd = (int)lua_tointeger(L, 1);
    int len = sendbuf_datalen(sockfd);
    lua_pushinteger(L, len);
    return 1;
}

int sendbuf_skip_read_ptr(int sockfd, int len){
	BBuf *self = fd2bbuf(sockfd);
    if(self->block_head == NULL){
        return 1;
    }
	self->block_head->rptr += len;
	if(self->block_head->rptr >= self->block_head->buf_len){
		BBuf_Block *block = self->block_head;
		self->block_head = self->block_head->next;
		if(self->block_head == NULL){
			self->block_tail = NULL;
		}
		bbuf_free_block(block);
	}
	return 0;
}

static int lskip_read_ptr(lua_State *L){
    int sockfd;
    int len;
    sockfd = (int)lua_tointeger(L, 1);
    len = (int)lua_tointeger(L, 2);
    if (sendbuf_skip_read_ptr(sockfd, len)) {
        return 0;
    }
    lua_pushboolean(L, 1);
	return 1;
}

int sendbuf_flush(int sockfd, char *buf, int buf_len){
	BBuf *self = fd2bbuf(sockfd);
    if(self->block_tail == NULL){
        printf("tail is null\n");
        return 1;
    }
    if(self->block_tail->buf_size - self->block_tail->buf_len < buf_len){
        printf("size is not enougth %d/%d\n", self->block_tail->buf_len, self->block_tail->buf_size);
        return 1;
    }
    self->block_tail->buf_len += buf_len;
    return 0;
}


static int lflush(lua_State *L){
    int sockfd;
    char *buf;
    int buf_len;
    sockfd = (int)lua_tointeger(L, 1);
    buf = (char *)lua_touserdata(L, 2);
    buf_len = (int)lua_tointeger(L, 3);
    if (sendbuf_flush(sockfd, buf, buf_len)) {
        return 0;
    }
    lua_pushboolean(L, 1);
    return 1;
}

char * sendbuf_alloc(int sockfd, int need_size){
	BBuf *self = fd2bbuf(sockfd);
    BBuf_Block *block = self->block_tail;
    if(block != NULL && block->buf_size - block->buf_len >= need_size){
        char *ptr = block->buf + block->buf_len;
        return ptr;
    }
    //申请一块新的
	int real_size = need_size + sizeof(BBuf_Block);
    //这里加上策略 TODO, buf的大小决定了, 系统调用write的次数和申请的次数
    if(real_size <= 4096){
        real_size = 4096;
    }
	int idx = hash(real_size);
	if(block_table[idx] == NULL){
        int malloc_size = 1<<idx;
        //printf("malloc size: %d/%d\n", need_size, malloc_size - sizeof(BBuf_Block));
		BBuf_Block *block = (BBuf_Block *)malloc(malloc_size);
		if(block == NULL){
            printf("malloc fail\n");
            return NULL;
		}
		block_table[idx] = block;
		block->next = NULL;
		block->buf_size = malloc_size - sizeof(BBuf_Block);
	}
    //申请失败
    if(block_table[idx] == NULL){
        printf("malloc fail\n");
        return NULL;
    }
	block = block_table[idx];
	block_table[idx] = block_table[idx]->next;

	block->next = NULL;
	block->rptr = 0;
    block->buf_len = 0;

    if(self->block_tail == NULL){
        self->block_tail = self->block_head = block;
        block->next = NULL;
    }else{
        self->block_tail->next = block;
        self->block_tail = block;
        block->next = NULL;
    }
    return block->buf;
}

static int lalloc(lua_State *L){
    int sockfd;
    int need_size;
    sockfd = (int)lua_tointeger(L, 1);
    need_size = (int)lua_tointeger(L, 2);
    char *buf = sendbuf_alloc(sockfd, need_size);
    if (buf == NULL) {
        return 0;
    }
    lua_pushlightuserdata(L, buf);
    return 1;
}

static int ltest(lua_State *L) {
    printf("test\n");
    return 0;
}

static luaL_Reg lua_lib[] ={
    {"test", ltest},
    {"create", lcreate},
    {"free", lfree},
    {"alloc", lalloc},
    {"flush", lflush},
    {"get_read_ptr", lget_read_ptr},
    {"datalen", ldatalen},
    {"skip_read_ptr", lskip_read_ptr},
    {NULL, NULL}
};

int luaopen_sendbuf(lua_State *L){
	luaL_register(L, "Sendbuf", lua_lib);
	return 1;
}
