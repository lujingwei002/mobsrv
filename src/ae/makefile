CC=g++
INCLUDE_DIRS=-I${ENGINE_PATH}/3rd/lua/src -I${ENGINE_PATH}/3rd/common
LIB_DIRS=-L${ENGINE_PATH}/3rd/lua/src/ -L${ENGINE_PATH}/3rd/common
CFLAGS=-fPIC -shared -O1 -Wall 
SO=ae.so

${SO}:lae.cc lport.cc lrecvbuf.cc lsendbuf.cc ltimer.cc
	g++ -o ${SO} ${CFLAGS} lae.cc lport.cc ae.cc lrecvbuf.cc lsendbuf.cc ltimer.cc ${INCLUDE_DIRS} ${LIB_DIRS} -llua -lcommon

clean:
	rm -rf ${SO}

install:
	cp -r ${SO} ../../lib
