CUR_DIR:=lib-src
MODULES:=configuration utils
MODULE_PATH:=$(foreach v, $(MODULES), $(CUR_DIR)/$(v))
SRC:=$(foreach v, $(MODULE_PATH), $(wildcard $(v)/*.cc))
LIB_NAME:=libdh.a
#OBJS:=$(SRC:.cc=.o)

PROJ_LIBS+=$(PROJ_LIB_PATH)/$(LIB_NAME)
CXXFLAGS+=-I$(CUR_DIR)/include
PROJ_LIB_SRC+=$(SRC)

#.PHONY: all
#
#all:
#	@echo $(MODULES)
#	@echo $(MODULE_PATH)
#	@echo $(SRC)

$(PROJ_LIB_PATH)/$(LIB_NAME): $(SRC:.cc=.o)
	$(AR) $@ $^
	$(RANLIB) $@
