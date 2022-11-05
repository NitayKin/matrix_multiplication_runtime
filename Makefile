CC = gcc
CFLAGS = -Wall -g -std=gnu11

INSTALL_PATH = /usr/local/bin
BIN = multiplier

OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) *.o -o $(BIN)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS)

install:
	install -m 755 $(BIN) $(INSTALL_PATH)/$(BIN)

uninstall:
	rm -f $(INSTALL_PATH)/$(BIN)

clean:
	rm -f $(BIN)
	rm -f src/*.o
	rm -f $(PY)

