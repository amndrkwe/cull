NAME=cull

CC=gcc
FLAGS=-Wall -Wextra -Wno-unused 
DEBUG_FLAGS=-g
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
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(LIB) $(SRC) $(INC) -o $(BIN)$(NAME)
