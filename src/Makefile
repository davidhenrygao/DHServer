PLAT=linux
CXX=g++
CXXFLAGS=-g -O0 -Wall -I$(PROJ_INC_PATH) -I$(LUA_SRC_PATH)
LDFLAGS=-ldl

RM=rm -f

#lua
LUA_STATIC_LIB=liblua.a
LUA_LIB_PATH=./3rd/lua-5.3.3
LUA_SRC_PATH=./3rd/lua-5.3.3/src
LUA_LIB=$(LUA_SRC_PATH)/$(LUA_STATIC_LIB)

#project
PROJ_TARGET=DHServer
PROJ_OBJECTS=server/main.o \
			 utils/ConfigLoaderFactory.o utils/LuaConfigLoader.o utils/LuaUtils.o utils/facilities.o
PROJ_INC_PATH=./include

all: $(PLAT)

$(PLAT): $(PROJ_TARGET)

$(PROJ_TARGET): $(PROJ_OBJECTS) $(LUA_LIB)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

$(LUA_LIB):
	cd $(LUA_LIB_PATH) && $(MAKE) $(PLAT)

.PHONY: all $(PLAT) $(PROJ_TARGET) clean

clean:
	$(RM) $(PROJ_TARGET) $(PROJ_OBJECTS)
	cd $(LUA_LIB_PATH) && $(MAKE) clean
