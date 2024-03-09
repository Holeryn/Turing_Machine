SRC_FILES = main.c tape.c PROGRAM.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = gcc

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o tm
