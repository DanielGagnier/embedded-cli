CC = gcc
CFLAGS = -Wall -Werror -std=c99 -g -Iinclude

TARGET = embedded-cli
SOURCES = src/main.c src/cli.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
