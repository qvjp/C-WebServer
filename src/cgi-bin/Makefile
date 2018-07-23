BUILD = ../../build
BIN = ../../bin/cgi-bin
CC = gcc
CFLAGS = -O2 -I .. -Wall
CFLAGS += -L/usr/local/mysql/lib -lmysqlclient -lssl -lcrypto
CFLAGS += -I/usr/local/mysql/include
BIN_PROGRAMS := \
	adder \
	login \
	createPaper \
	changePassword

all: $(addprefix $(BUILD)/cgi-bin/, $(BIN_PROGRAMS)) install-bin

install-bin: $(addprefix $(BUILD)/cgi-bin/, $(BIN_PROGRAMS))
	@mkdir -p $(BIN)
	cp -f $^ $(BIN)


$(BUILD)/cgi-bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all install-bin