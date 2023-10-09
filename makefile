PROJ_NAME=win

SRC_DIR=./src
C_SRC=$(wildcard $(SRC_DIR)/*.cpp)

OBJS=$(C_SRC:.c=.o)

CC=g++
CCFLAGS=-I$(SRC_DIR) -Wall -pedantic -g

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS) $(CCFLAGS)

clear:
	@ rm -rf *.o $(PROJ_NAME) .*.o ./src/*.o ./src/.*.o *~
	
run:
	@ ./$(PROJ_NAME)