CC=g++
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I${ENGINE_PATH}/3rd/common -I${ENGINE_PATH}/3rd/protobuf/src
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src -L${ENGINE_PATH}/3rd/common ${ENGINE_PATH}/lib/libprotobuf.a
CFLAGS=-fPIC -shared -O2 -Wall 
SO=pblua.so

${SO}:pblua.cc
	${CC} -o ${SO} ${CFLAGS} pblua.cc ${INCLUDE_DIRS} ${LIB_DIRS} -llua -lcommon

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib

test:
	../../bin/luaexe test.lua
