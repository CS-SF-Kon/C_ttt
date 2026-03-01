CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = new
OBJS = new.o game.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

new.o: new.c game.h
	$(CC) $(CFLAGS) -c new.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)