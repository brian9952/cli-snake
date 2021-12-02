# define cpp compiler
CC = g++

# define compiler flags
CFLAGS = -g -Wall -lncurses

# build target executable
TARGET = cli-snake
MAIN = main

all: $(TARGET)

$(TARGET): $(MAIN).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN).cpp
