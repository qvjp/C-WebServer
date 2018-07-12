BUILD = ./build
BIN = ./bin
all: web

web:
	$(MAKE) -C src

clean:
	rm -rf $(BUILD) $(BIN)

run:
	(cd bin; ./web 8001)

.PHONY: all
