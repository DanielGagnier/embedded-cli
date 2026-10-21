PLATFORM ?= HOST

TARGET = embedded-cli
COMMON_SOURCES = src/main.c src/cli.c

CFLAGS = -Wall -Werror -std=c99 -g -Iinclude

ifeq ($(PLATFORM), HOST)
    CC = gcc
    SOURCES = $(COMMON_SOURCES) src/led_host.c
else ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    SOURCES = $(COMMON_SOURCES) src/led_msp432.c
    CFLAGS += -mcpu=cortex-m4 -mthumb
else
    $(error Unsupported PLATFORM: $(PLATFORM))
endif

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
