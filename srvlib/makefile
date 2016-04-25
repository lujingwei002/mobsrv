
INCLUDE_DIRS=-I$(ENGINE_PATH)/3rd/lua/src -I$(ENGINE_PATH)/3rd/tolua++ -I$(ENGINE_PATH)/3rd/protobuf/src  -I$(ENGINE_PATH)/3rd/hiredis -I.

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

SUBDIR = item 
SOURCE = $(wildcard \
		 file/*.cc\
		 json/*.cc\
		 system/*.cc\
		 string/*.cc\
		 socket/*.cc\
		 srvmain/*.cc\
		 bit/*.cc\
		 redis/*.cc\
		 mysql/*.cc\
		 date/*.cc\
		 ar/*.cc\
		 ae/*.cc\
		 log/*.cc\
		 lualib/*.cc\
		 strport/*.cc\
		 srvport/*.cc\
		 *.cc\
		 ) 
OBJ = $(patsubst %.cc,%.o,$(SOURCE))

SO=libsrv.so

%.o:%.cc
	g++ -fPIC -c $< -o $@ $(MYSQL_INCLUDE) $(INCLUDE_DIRS)

${SO}:$(OBJ)
	g++ -o ${SO} ${CFLAGS} $(OBJ) ${LIB_DIRS} $(LIB) $(MYSQL_LIB) -llua -ltolua -lprotobuf

clean:
	rm -rf $(OBJ)
	rm -rf ${SO}

install:
	cp -rf $(SO) ../lib
