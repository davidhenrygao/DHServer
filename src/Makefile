PLAT=linux
CXX=g++
CXXFLAGS=-g -O0 -Wall -I$(PROJ_INC_PATH) -I$(LUA_SRC_PATH)
LDFLAGS=-ldl

RM=rm -f

#project
PROJ_ROOT_DIR=..
PROJ_TARGET=$(PROJ_ROOT_DIR)/DHServer
PROJ_OBJECTS=server/main.o \
			 utils/ConfigLoaderFactory.o utils/LuaConfigLoader.o utils/LuaUtils.o utils/facilities.o
PROJ_INC_PATH=./include
PROJ_LIB_DIR=$(PROJ_ROOT_DIR)/lib

#lua
LUA_STATIC_LIB=liblua.a
LUA_LIB_PATH=./3rd/lua-5.3.3/src
LUA_SRC_PATH=./3rd/lua-5.3.3/src
LUA_LIB=$(PROJ_LIB_DIR)/$(LUA_STATIC_LIB)

all: $(PLAT)

$(PLAT): $(PROJ_TARGET)

$(PROJ_TARGET): $(PROJ_OBJECTS) $(LUA_LIB)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

$(LUA_LIB):
	cd $(LUA_LIB_PATH) && $(MAKE) $(PLAT)
	cp $(LUA_LIB_PATH)/$(LUA_STATIC_LIB) $(LUA_LIB)

.PHONY: all $(PLAT) clean

clean:
	$(RM) $(PROJ_TARGET) $(PROJ_OBJECTS); \
	cd $(LUA_LIB_PATH) && $(MAKE) clean
