# Makefile for OS Simulation Project

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = os_simulation
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run
