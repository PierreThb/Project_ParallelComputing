main: main.c
	gcc main.c -o test -lm

#main: main.c thread_mean_calc.c thread_mean_calc.o
#	gcc main.c thread_mean_calc.o -lpthread -o main

#thread_mean_calc.o: thread_mean_calc.c
#	gcc -c thread_mean_calc.c
