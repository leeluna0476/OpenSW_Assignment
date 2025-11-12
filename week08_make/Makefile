PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
OBJ_DIR=$(PROJ_DIR)/obj
BIN_DIR=$(PROJ_DIR)/bin
LIB_DIR=$(PROJ_DIR)/lib

#CC=gcc
AR=ar

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.c=.o))

LIB_DIR=$(PROJ_DIR)/lib
LIB_BASIC_NAME=mybasic
LIB_BASIC=$(LIB_DIR)/lib$(LIB_BASIC_NAME).a

LIB_ADVANCED_NAME=myadvanced
LIB_ADVANCED=$(LIB_DIR)/lib$(LIB_ADVANCED_NAME).a

.PHONY: all basic_ops advanced_ops clean

all: $(BIN_DIR)/myapp

basic_ops: $(LIB_BASIC)

advanced_ops: $(LIB_ADVANCED)

$(BIN_DIR)/myapp: $(OBJ) $(LIB_BASIC) $(LIB_ADVANCED)
	$(CC) $< -l$(LIB_BASIC_NAME) -l$(LIB_ADVANCED_NAME) -L$(LIB_DIR) -o $@

$(LIB_BASIC):
	$(MAKE) -C basic_ops

$(LIB_ADVANCED):
	$(MAKE) -C advanced_ops

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -I$(INC_DIR) -o $@

clean:
	$(MAKE) clean -C basic_ops
	$(MAKE) clean -C advanced_ops
	rm -rf $(OBJ) $(BIN_DIR)/myapp
