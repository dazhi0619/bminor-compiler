options=-g
objects=bminor.o encoder.o
bminor: $(objects)
	gcc $(options) $(objects) -o bminor

bminor.o: bminor.c
	gcc $(options) -c bminor.c -o bminor.o

encoder.o: encoder.c
	gcc $(options) -c encoder.c -o encoder.o

clean:
	rm -rf *.o bminor
	rm -rf test/*/*.out

test: bminor
	./runtest.sh
