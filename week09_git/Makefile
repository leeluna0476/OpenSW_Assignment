PROJ_DIR=$(shell pwd)
BIN_DIR=$(PROJ_DIR)/bin
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
INC_DIR=$(PROJ_DIR)/include

NAME=$(BIN_DIR)/myapp
SRCS=$(wildcard $(SRC_DIR)/*.c)
MAIN_OBJ=$(OBJ_DIR)/myapp.o
OBJS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))
LIB_OBJS=$(subst $(MAIN_OBJ),,$(OBJS))

LIB_NAME=myops
LIB_LINK=$(LIB_DIR)/lib$(LIB_NAME).so
LIB_MID=$(LIB_LINK).1
LIB_REAL=$(LIB_MID).0

.PHONY: all clean

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(LIB_LINK)
	$(CC) $< -l$(LIB_NAME) -L$(LIB_DIR) -lm -o $@

$(LIB_LINK): $(LIB_MID)
	ln -s $< $@

$(LIB_MID): $(LIB_REAL)
	ln -s $< $@

$(LIB_REAL): $(LIB_OBJS)
	$(CC) -fPIC -shared -Wl,-soname=$(LIB_MID) $(LIB_OBJS) -o $@ -lc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -fPIC -c -I$(INC_DIR) $< -o $@

clean:
	$(RM) $(OBJS) $(LIB_LINK) $(LIB_MID) $(LIB_REAL) $(NAME)
