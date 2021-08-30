NAME=cull

CC=gcc
FLAGS=-Wall -Wno-unused
DEBUG_FLAGS=-g3 -Wextra -Walloc-zero -Wformat-overflow -Wformat-truncation -Wnonnull -Wvla
SRC=$(wildcard src/*.c) $(wildcard src/*/*.c)
LIB=
INC=-I./include -I./src
BIN=bin/

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(LIB) $(SRC) $(INC) -o $(BIN)$(NAME)

run:
	./$(BIN)$(NAME)

debug:
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(LIB) $(SRC) $(INC) -o $(BIN)/debug/$(NAME)

rund:
	./$(BIN)/debug/$(NAME)

drun: debug rund

optimize:
	$(CC) $(FLAGS) -O3 $(LIB) $(SRC) $(INC) -o $(BIN)$(NAME)

orun: optimize run