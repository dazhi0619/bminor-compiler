options=-std=gnu1x
objects=bminor.o encoder.o parser.o scanner.o

bminor: $(objects)
	gcc $(options) $(objects) -o bminor

bminor.o: bminor.c
	gcc $(options) -c bminor.c -o bminor.o

encoder.o: encoder.c
	gcc $(options) -c encoder.c -o encoder.o

scanner.o: scanner.flex
	flex -o scanner.c scanner.flex
	gcc $(options) -c scanner.c -o scanner.o

parser.o: parser.bison
	bison --defines=include/token.h --output=parser.c parser.bison
	gcc $(options) -c parser.c -o parser.o

clean:
	rm -rf *.o bminor
	rm -rf test/*/*.out
	rm parser.c scanner.c
	rm include/token.h

test: bminor
	./runtest.sh
