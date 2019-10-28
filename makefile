all: functions.o main.o
	gcc -o program functions.o main.o

functions.o: functions.c headers.h
	gcc -c functions.c

main.o: main.c headers.h functions.c
	gcc -c main.c

run:
	./program	