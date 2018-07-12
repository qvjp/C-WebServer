BUILD = ../build
BIN = ../bin
CC = gcc
CFLAGS = -O2 -I . -Wall
LIB = -lpthread

OBJ := \
	web.o \
	csapp.o

OBJ := $(addprefix $(BUILD)/, $(OBJ))
all: $(BUILD)/web cgi-bin

$(BUILD)/web: $(OBJ)
	@mkdir -p $(BIN)
	$(CC) -o $(BIN)/web $^ $(LIB)

$(BUILD)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

cgi-bin:
	$(MAKE) -C ./cgi-bin

.PHONY: all cgi-bin