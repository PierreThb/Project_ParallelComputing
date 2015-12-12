all: main_serial

main_serial: main_S_2P.o forces_calc.o functions.o struct_Planet.o functionsGTK.o
	gcc main_S_2P.o forces_calc.o functions.o struct_Planet.o functionsGTK.o -o main_serial `pkg-config --cflags --libs gtk+-3.0` -lm -std=c11
	
functionsGTK.o: source/functionsGTK.c
	gcc -o functionsGTK.o -c source/functionsGTK.c `pkg-config --cflags --libs gtk+-3.0` -std=c11
	
forces_calc.o: source/forces_calc.c 
	gcc -o forces_calc.o -c source/forces_calc.c -std=c11
	
functions.o: source/functions.c
	gcc -o functions.o -c source/functions.c `pkg-config --cflags --libs gtk+-3.0` -std=c11
	
struct_Planet.o: source/struct_Planet.c
	gcc -o struct_Planet.o -c source/struct_Planet.c -std=c11
	
main_S_2P.o: source/main_S_2P.c
	gcc -o main_S_2P.o -c source/main_S_2P.c `pkg-config --cflags --libs gtk+-3.0` -std=c11
	
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf main_serial