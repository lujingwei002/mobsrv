
INCLUDE_DIRS=-I$(ENGINE_PATH)/3rd/lua/src -I$(ENGINE_PATH)/3rd/common -I$(ENGINE_PATH)/3rd/tolua++ -I$(ENGINE_PATH)/3rd/protobuf/src -I../
LIB_DIRS=-L$(ENGINE_PATH)/3rd/lua/src -L$(ENGINE_PATH)/3rd/common -L$(ENGINE_PATH)/3rd/tolua++ -L/usr/local/lib
CFLAGS=-fPIC -shared -O2 -Wall -lprotobuf
SO=conf.so
SRC=$(wildcard *.cc)

$(SO):$(SRC)
	echo '编译'
	g++ -o $(SO) $(CFLAGS) $(SRC) $(INCLUDE_DIRS) $(LIB_DIRS) -llua -ltolua 
confc:
	echo '执行confc'
	$(ENGINE_PATH)/bin/confc ../../conftemplate/*.lua -o . -n conf
test:test.cc item_pool_conf.cc
	g++ -o test $(SRC) $(INCLUDE_DIRS) $(LIB_DIRS) -llua -ltolua 
clean:
	rm -rf $(SO)
install:
	cp -rf $(SO) ../../lib

