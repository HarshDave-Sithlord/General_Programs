CC=gcc
CFLAGS=-I.
DEPS = common.h queue.h
OBJ = main.o queue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm ./*.o