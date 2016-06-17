
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -g -Iinclude


diary:
	gcc $(CFLAGS) src/main.c src/linkedList.c -o bin/runMe

test: 
	gcc $(CFLAGS) src/main.c src/linkedList.c  -o bin/runMe

clean:
	@ rm *.o
