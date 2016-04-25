CC=g++
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I${ENGINE_PATH}/3rd/redis/src -I${ENGINE_PATH}/3rd/hiredis
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src/ -L${ENGINE_PATH}/3rd/hiredis
CFLAGS=-fPIC -shared -O2 -Wall 
SO=redis.so

${SO}:lredis.cc
	g++ -o ${SO} ${CFLAGS} lredis.cc ${ENGINE_PATH}/3rd/hiredis/libhiredis.a ${INCLUDE_DIRS} ${LIB_DIRS} -llua 

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib

test:
	../../bin/luaexe test.lua
