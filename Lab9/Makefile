# Basic makefile

all: OBJ LIB
	gcc -g -o strtester strtester.c -L . -lstr2107

OBJ:
	gcc -g -c *.c

LIB:
	ar rcs libstr2107.a *.o

clean:
	rm -f *.o *.a *.exe strtester