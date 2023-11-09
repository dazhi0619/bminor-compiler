options=-std=gnu1x -g
objects=bminor.o encoder.o parser.o scanner.o ast_constr.o ast_print.o symbol.o hash_table.o

bminor: $(objects)
	gcc $(options) $(objects) -o bminor

bminor.o: bminor.c
	gcc $(options) -c bminor.c -o bminor.o

encoder.o: encoder.c
	gcc $(options) -c encoder.c -o encoder.o

scanner.o: scanner.flex
	flex -o scanner.c scanner.flex
	gcc $(options) -c scanner.c -o scanner.o

parser.o: parser.bison symbol.o
	bison --defines=include/token.h --output=parser.c parser.bison
	gcc $(options) -c parser.c -o parser.o

ast_constr.o: ast_constr.c
	gcc $(options) -c ast_constr.c -o ast_constr.o

ast_print.o: ast_print.c
	gcc $(options) -c ast_print.c -o ast_print.o

hash_table.o: hash_table.c
	gcc $(options) -c hash_table.c -o hash_table.o

symbol.o: symbol.c hash_table.o
	gcc $(options) -c symbol.c -o symbol.o

clean:
	rm -rf *.o bminor
	rm -rf test/*/*.out*
	rm parser.c scanner.c
	rm include/token.h

test: bminor
	./runtest.sh
