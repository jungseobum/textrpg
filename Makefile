CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c
TARGET = rpg

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)