CC=gcc
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src
CFLAGS=-O2 -Wall 
EXE=luaexe

${EXE}:luaexe.c
	gcc -o ${EXE} ${CFLAGS} luaexe.c ${INCLUDE_DIRS} ${LIB_DIRS} -llua

clean:
	rm -rf ${EXE}

install:
	cp -r ${EXE} ${ENGINE_PATH}/bin

test:
	./luaexe test.lua

