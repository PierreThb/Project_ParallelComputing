main: main.c
	gcc main_S_2P.c -o main_serial -lm

#main: main.c thread_mean_calc.c thread_mean_calc.o
#	gcc main.c thread_mean_calc.o -lpthread -o main

#thread_mean_calc.o: thread_mean_calc.c
#	gcc -c thread_mean_calc.c
