TEST = custom

all: clean yanc run_test

run:
	./test

run_test:
	./yanc ejs/ejemplo_$(TEST)/$(TEST).alfa ejs/ejemplo_$(TEST)/out.asm
	nasm -g -o ejs/ejemplo_$(TEST)/out.o -f elf32 ejs/ejemplo_$(TEST)/out.asm
	gcc -Wall -g -m32 -o test ejs/ejemplo_$(TEST)/out.o alfalib.o
	./test

yanc: y.tab.o lex.yy.o yanc.o generacion.o sym_table.o hash_table.o
	gcc -o yanc y.tab.o lex.yy.o yanc.o generacion.o sym_table.o hash_table.o

yanc.o: yanc.c
	gcc -Wall -c -o yanc.o yanc.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

y.tab.o: y.tab.c
	gcc -c -o y.tab.o y.tab.c

y.tab.c: alfa.y
	bison -dyv alfa.y

y.tab.h: alfa.y
	bison -dyv alfa.y

lex.yy.c: alfa.l y.tab.h
	flex alfa.l

generacion.o: generacion.c generacion.h
	gcc -c -o generacion.o generacion.c

hash_table.o: hash_table.c hash_table.h
	gcc -c -o hash_table.o hash_table.c

sym_table.o: sym_table.c sym_table.h hash_table.o
	gcc -c -o sym_table.o sym_table.c

clean:
	rm -rf -rf test yanc [!a][!l][!f]*.o lex.yy.c y.tab.h y.tab.c y.output ejemplos_compilador/*/out.asm ejemplos_compilador/*/out.o
