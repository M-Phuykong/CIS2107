# Basic makefile

all: OBJ LIB
	gcc -o strtester strtester.c -L . -lstr2107

OBJ:
	gcc -c *.c

LIB:
	ar rcs libstr2107.a *.o

clean:
	rm -f *.o *.a strtester