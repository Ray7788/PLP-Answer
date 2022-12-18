all: prog

prog: module1.o module2.o main.o
	gcc module1.o module2.o main.o -o prog

main.o: main.c module1.h module2.h
	gcc -c main.c -o main.o

module1.o: module1.c module1.h
	gcc -c module1.c -o module1.o

module2.o: module2.c module2.h
	gcc -c module2.c -o module2.o

clean:
	rm -rf *.o prog