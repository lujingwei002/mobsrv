CC=g++
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src 
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src
CFLAGS=-fPIC -shared -O2 -Wall 
SO=actordb.so

all:actordb.so

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib

build:
	./lstrc actordb.scp actordb.h

actordb.so:actordb.h actordb.cc
	g++ -o $@ ${CFLAGS} actordb.cc ${INCLUDE_DIRS} ${LIB_DIRS} -llua -std=c++0x

test:
	../../bin/luaexe test.lua
