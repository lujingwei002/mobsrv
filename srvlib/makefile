
INCLUDE_DIRS=-I$(ENGINE_PATH)/3rd/lua/src -I$(ENGINE_PATH)/3rd/tolua++ -I$(ENGINE_PATH)/3rd/protobuf/src  -I$(ENGINE_PATH)/3rd/hiredis -I./

LIB_DIRS=-L$(ENGINE_PATH)/3rd/lua/src -L$(ENGINE_PATH)/3rd/tolua++ -L$(ENGINE_PATH)/lib 

LIB=$(ENGINE_PATH)/3rd/hiredis/libhiredis.a

CFLAGS=-fPIC -shared -O2 -Wall 

ifeq ($(shell getconf LONG_BIT), 64)
MYSQL_INCLUDE=-I$(ENGINE_PATH)/3rd/mysql/include
MYSQL_LIB=-L/$(ENGINE_PATH)/3rd/mysql/lib -lmysqlclient
endif

ifeq ($(shell uname), Darwin)
MYSQL_INCLUDE=-I$(ENGINE_PATH)/3rd/mysql-connector-c64-mac/include
MYSQL_LIB=-L$(ENGINE_PATH)/3rd/mysql-connector-c64-mac/lib -lmysqlclient
endif

SOURCE = $(wildcard \
		 file/*.cc\
		 json/*.cc\
		 system/*.cc\
		 string/*.cc\
		 srvapp/*.cc\
		 bit/*.cc\
		 redis/*.cc\
		 mysql/*.cc\
		 date/*.cc\
		 ar/*.cc\
		 net/*.cc\
		 log/*.cc\
		 pblua/*.cc\
		 lualib/*.cc\
		 port/*.cc\
		 *.cc\
		 ) 

OBJ = $(patsubst %.cc,%.o,$(SOURCE))

STATIC_LIB=libsrv.a

%.o:%.cc
	g++ -c $< -o $@ $(MYSQL_INCLUDE) $(INCLUDE_DIRS)

$(STATIC_LIB):$(OBJ)
	ar rcu $@ $(OBJ) 
	ranlib $@

all:$(STATIC_LIB)

clean:
	rm -rf $(OBJ)
	rm -rf $(STATIC_LIB)

install:
	cp -rf $(STATIC_LIB) ../lib

