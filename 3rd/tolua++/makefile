
ENGINE_PATH=../..
CC=gcc
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src
SRC=tolua.c toluabind.c tolua_event.c tolua_is.c tolua_map.c tolua_push.c tolua_to.c 


all:tolua++ libtolua.so

tolua++:${SRC}
	gcc -O2 -Wall -o tolua++ -llua ${SRC} ${LIB_DIRS} ${INCLUDE_DIRS}

libtolua.so:${SRC}
	gcc -O2 -Wall -o libtolua.so -fPIC -shared ${SRC} -llua ${INCLUDE_DIRS} ${LIB_DIRS}

test:
	./tolua++ -n gamesrv -o testfile/interface.cc testfile/interface.pkg 

clean:
	rm -rf tolua++ libtolua.so
