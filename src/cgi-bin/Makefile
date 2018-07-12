BUILD = ../../build
BIN = ../../bin/cgi-bin
CC = gcc
CFLAGS = -O2 -I .. -Wall

BIN_PROGRAMS := \
	adder \
	login

all: $(addprefix $(BUILD)/cgi-bin/, $(BIN_PROGRAMS)) install-bin

install-bin: $(addprefix $(BUILD)/cgi-bin/, $(BIN_PROGRAMS))
	@mkdir -p $(BIN)
	cp -f $^ $(BIN)


$(BUILD)/cgi-bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all install-bin