CC=g++
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I${ENGINE_PATH}/3rd/common
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src/ -L${ENGINE_PATH}/3rd/common
CFLAGS=-fPIC -shared -O2 -Wall 
SO=srvmain.so

${SO}:lsrvmain.cc
	g++ -o ${SO} ${CFLAGS} lsrvmain.cc ${INCLUDE_DIRS} ${LIB_DIRS} -llua -lcommon

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib


test:
	../../bin/luaexe test.lua
