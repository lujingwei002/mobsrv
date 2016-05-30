
INCLUDE_DIRS=-I$(ENGINE_PATH)/3rd/lua/src -I$(ENGINE_PATH)/3rd/tolua++ -I$(ENGINE_PATH)/3rd/protobuf/src  -I$(ENGINE_PATH)/3rd/hiredis -I$(ENGINE_PATH)/3rd/mysql/include -I. -I$(ENGINE_PATH)/srvlib


LIBS=$(ENGINE_PATH)/srvlib/libsrv.a $(ENGINE_PATH)/lib/libhiredis.a $(ENGINE_PATH)/lib/libprotobuf.a $(ENGINE_PATH)/lib/tolua++.a $(ENGINE_PATH)/lib/liblua.a $(ENGINE_PATH)/lib/libmysqlclient.a

DY_LIBS = -lm -ldl -lreadline -lhistory -lncurses -lpthread

CFLAGS=-O2 -Wall 

SOURCE = $(wildcard \
		 websocket/*.cc\
		 *.cc\
		 ) 

OBJ = $(patsubst %.cc,%.o,$(SOURCE))

EXE=gatesrv

%.o:%.cc
	g++ $(CFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

$(EXE):$(OBJ)
	g++ -o $(EXE) $(OBJ) $(LIBS) $(DY_LIBS)

tolua:
	$(ENGINE_PATH)/3rd/tolua++/tolua++ -n gatesrv -o interface.cc interface.pkg

clean:
	rm -rf $(OBJ)
	rm -rf $(EXE)

