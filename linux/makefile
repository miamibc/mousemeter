CC=gcc
CFLAGS=-I.

all: mousemeter mousemeterd
	@echo "Build complete"
	@echo "Run ./mousemeter to start in console, or ./mousemeterd to start daemon"

mousemeterd:
	$(CC) mousemeterd.c -o mousemeterd

mousemeter:
	$(CC) mousemeter.c -lX11 -lm -o mousemeter

clean:
	$(RM) mousemeterd mousemeterd.o
	$(RM) mousemeter mousemeter.o
