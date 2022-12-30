CC=gcc
CFLAGS=-I.
DEPS = common.h queue.h stack.h test.h
OBJ = main.o queue.o stack.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm ./*.o