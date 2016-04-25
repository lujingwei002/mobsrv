CC=g++
ifeq ($(shell getconf LONG_BIT), 64)
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I/usr/include/mysql -I${ENGINE_PATH}/3rd/common
LIB_DIRS=-L${ENGINE_PATH}3rd/lua/src/ -L/usr/lib64/mysql/ -L${ENGINE_PATH}/3rd/common
CFLAGS=-fPIC -shared -O2 -Wall 
SO=mysql.so
endif

ifeq ($(shell uname), Darwin)
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I${ENGINE_PATH}/3rd/common -I${ENGINE_PATH}/3rd/mysql-connector-c64-mac/include
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src -L${ENGINE_PATH}/3rd/common -L${ENGINE_PATH}/3rd/mysql-connector-c64-mac/lib
CFLAGS=-fPIC -shared -O2 -Wall 
SO=mysql.so
endif

${SO}:lmysql.cc
	g++ -o ${SO} ${CFLAGS} lmysql.cc ${INCLUDE_DIRS} ${LIB_DIRS} -llua -lmysqlclient -lcommon

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib

test:
	../../bin/luaexe test.lua
