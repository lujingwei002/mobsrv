
INCLUDE_DIRS=-I$(ENGINE_PATH)/3rd/lua/src -I$(ENGINE_PATH)/3rd/common -I$(ENGINE_PATH)/3rd/tolua++ -I$(ENGINE_PATH)/3rd/protobuf/src -I./ -I../src

LIB_DIRS=-L$(ENGINE_PATH)/3rd/lua/src -L$(ENGINE_PATH)/3rd/common -L$(ENGINE_PATH)/3rd/tolua++ -L$(ENGINE_PATH)/lib ../lib/proto.so ../lib/dbproto.so

CFLAGS=-fPIC -shared -O2 -Wall 

SUBDIR = item 
SOURCE = $(wildcard \
		 *.cc \
		 item/*.cc) 

SO=globalsrv.so

${SO}:$(SOURCE)
	g++ -o ${SO} ${CFLAGS} $(SOURCE) ${INCLUDE_DIRS} ${LIB_DIRS} -llua -ltolua -lcommon
tolua:
	$(ENGINE_PATH)/3rd/tolua++/tolua++ -n globalsrv -o interface.cc interface.pkg
test:
	$(ENGINE_PATH)/bin/luaexe test.lua
clean:
	rm -rf ${SO}
install:
	cp -rf $(SO) ../lib
