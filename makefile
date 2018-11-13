all: signals.o
	gcc -o signals signals.o

signals.o: signals.c
	gcc -c signals.c

clean:
	rm signals signals.o

run:
	./signals
