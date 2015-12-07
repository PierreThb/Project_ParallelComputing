main: main_S_2P.c
	gcc main_S_2P.c -o main_serial `pkg-config --cflags --libs gtk+-2.0` -lm

#main: main.c thread_mean_calc.c thread_mean_calc.o
#	gcc main.c thread_mean_calc.o -lpthread -o main

#thread_mean_calc.o: thread_mean_calc.c
#	gcc -c thread_mean_calc.c

#gcc test.c -o base `pkg-config --cflags --libs gtk+-2.0`
