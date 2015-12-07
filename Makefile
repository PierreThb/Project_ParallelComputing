main: source/main_S_2P.c source/forces_calc.c forces_calc.o
	gcc source/main_S_2P.c forces_calc.o -o main_serial `pkg-config --cflags --libs gtk+-3.0` -lm
	
forces_calc.o: source/forces_calc.c 
	gcc -c source/forces_calc.c