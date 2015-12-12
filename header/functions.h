/* 
 * File:   functions.h
 * Author: pierre
 *
 * Created on 8 décembre 2015, 15:52
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H
#define N 4
#define G 1
#define DELTA 0.1

#include <gtk/gtk.h>
//#include "struct_Planet.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void addPos(float array[N], float val, int index);
    void addMass(float array[N], float val, int index);
    void addForce(float array[N][N], float val, int index1, int index2);
    void initForce(float arrayX[N][N], float arrayY[N][N]);

    void test(GtkWidget *widget, gpointer data);
    void initStr(char str[10], char str2[10], char str3[10], char str4[10], planet* P);



#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

