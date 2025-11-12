LIB_DIR=../lib
LIB_NAME=mybasic
LIB=$(LIB_DIR)/lib$(LIB_NAME).a

SRCS_DIR=./src
SRCS=$(wildcard $(SRCS_DIR)/*.c)

OBJS_DIR=./obj
OBJS=$(subst $(SRCS_DIR),$(OBJS_DIR), $(SRCS:.c=.o))

INC_DIR=../include

CC=gcc
AR=ar

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rv $(LIB) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(OBJS_DIR)
	$(CC) -c $< -I$(INC_DIR) -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS) $(LIB)
