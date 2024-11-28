CC=gcc
CFLAGS=-I
DEPS = calculator.h

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

calculator: calculator.c operations.c
	$(CC) -o calculator calculator.c operations.c

clean:
		rm -f calculator
