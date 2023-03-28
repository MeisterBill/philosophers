CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -pthread
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = philo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
