options=-std=c1x
objects=bminor.o encoder.o scanner.o

bminor: $(objects)
	gcc $(options) $(objects) -o bminor

bminor.o: bminor.c
	gcc $(options) -c bminor.c -o bminor.o

encoder.o: encoder.c
	gcc $(options) -c encoder.c -o encoder.o

scanner.o: scanner.flex
	flex -o scanner.c scanner.flex
	gcc $(options) -c scanner.c -o scanner.o

clean:
	rm -rf *.o bminor
	rm -rf test/*/*.out

test: bminor
	./runtest.sh
