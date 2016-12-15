#Makefile for LAB_3

LAB_3: main.o CUI.o func.o test.o
	gcc -o LAB_3 main.o CUI.o func.o test.o -lprogbase -std=c99 -Werror -pedantic-errors

main.o: main.c
	gcc -c main.c

CUI.o: CUI.c
	gcc -c CUI.c

func.o: func.c
	gcc -c func.c

test.o: test.c
	gcc -c test.c

clean:
	rm -f *.o LAB_3
