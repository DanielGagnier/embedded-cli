PLATFORM ?= HOST

TARGET = embedded-cli
COMMON_SOURCES = src/main.c src/cli.c

CFLAGS = -Wall -Werror -std=c99 -g -Iinclude

ifeq ($(PLATFORM),HOST)
    CC = gcc
    CFLAGS = -Wall -Werror -std=c99 -g -Iinclude
    SOURCES = $(COMMON_SOURCES) src/led_host.c
    LDFLAGS =

else ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
    LINKER_FILE = platform/msp432/msp432p401r.lds

    CFLAGS = -Wall -Werror -std=c99 -g \
        -mcpu=$(CPU) -mthumb -march=$(ARCH) \
        -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
        --specs=$(SPECS) \
        -Iinclude \
        -Iplatform/msp432/include/msp432 \
        -Iplatform/msp432/include/CMSIS

    SOURCES = $(COMMON_SOURCES) \
        src/led_msp432.c \
        platform/msp432/src/interrupts_msp432p401r_gcc.c \
        platform/msp432/src/system_msp432p401r.c

    LDFLAGS = -T $(LINKER_FILE) \
        -Wl,-Map=$(TARGET).map
else
    $(error Unsupported PLATFORM: $(PLATFORM))
endif

all: $(TARGET)

ifeq ($(PLATFORM),HOST)
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDFLAGS)
else
$(TARGET): $(SOURCES) platform/msp432/src/startup_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(SOURCES) \
        platform/msp432/src/startup_msp432p401r_gcc.c \
        -o $@ $(LDFLAGS)
endif

clean:
	rm -f $(TARGET) $(TARGET).map

.PHONY: all clean
