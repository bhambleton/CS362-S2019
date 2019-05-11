CFLAGS= -Wall -coverage -std=c99

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)
	./testme

all: testme

clean:
	rm -f *.gcov *.gcda *.gcno testme
