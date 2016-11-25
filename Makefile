PLAT:=linux
CXX:=g++
CXXFLAGS=-g -O0 -Wall -I$(PROJ_INC_PATH) -I$(LUA_INC_PATH) -L$(PROJ_LIB_PATH)
LDFLAGS:=-ldl
AR= ar rcu
RANLIB= ranlib

RM:=rm -f

#lua
LUA_LIB:=liblua.a
LUA_SRC_PATH:=./3rd/lua-5.3.3/src
LUA_INC_PATH:=./3rd/lua-5.3.3/src

#dh lib
DH_LIB:=libdh.a

#project
PROJ_INC_PATH:=./inc
PROJ_LIB_PATH:=./lib
PROJ_TARGET:=DHServer
PROJ_SRC:=
PROJ_OBJS:=
PROJ_LIBS:=
PROJ_LIB_SRC:=
PROJ_LIB_OBJS:=

SUB_MAKEFILE_DIR:= src lib-src

#This must be first target.
all: $(PLAT)

-include $(patsubst %, %/include.mk, $(SUB_MAKEFILE_DIR))
#PROJ_OBJS := $(patsubst %.cc, %.o, $(PROJ_SRC))
PROJ_OBJS := $(PROJ_SRC:.cc=.o)
PROJ_LIB_OBJS := $(PROJ_LIB_SRC:.cc=.o)
PROJ_LIBS+=$(PROJ_LIB_PATH)/$(DH_LIB) $(PROJ_LIB_PATH)/$(LUA_LIB)

DEPENDS:= $(PROJ_OBJS:.o=.d)
LIB_DEPENDS:= $(PROJ_LIB_OBJS:.o=.d)
-include $(DEPENDS) $(LIB_DEPENDS)

$(PLAT): $(PROJ_TARGET)

$(PROJ_TARGET): $(PROJ_OBJS) $(PROJ_LIBS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

$(PROJ_LIB_PATH)/$(LUA_LIB):
	cd $(LUA_SRC_PATH) && $(MAKE) $(PLAT)
	cp $(LUA_SRC_PATH)/$(LUA_LIB) $@

%.d: %.cc
	./depend.sh `dirname $*` $(CXXFLAGS) $^ > $@

.PHONY: all $(PLAT) clean cleanall

clean:
	$(RM) $(PROJ_TARGET) $(PROJ_OBJS) $(PROJ_LIB_OBJS); \
	cd $(LUA_SRC_PATH) && $(MAKE) clean

cleanall:
	$(RM) $(PROJ_TARGET) $(PROJ_OBJS) $(PROJ_LIB_OBJS); \
	$(RM) $(DEPENDS) $(LIB_DEPENDS); \
	$(RM) $(PROJ_LIBS); \
	cd $(LUA_SRC_PATH) && $(MAKE) clean

