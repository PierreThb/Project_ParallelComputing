#include "../header/functions.h"

extern float forcesX[N][N]; //array which contained all forces on X direction betwin planets
extern float forcesY[N][N]; //array which contained all forces on Y direction betwin planets
extern float posX[N], posY[N]; //arrays which contained all X and Y positions
extern const float masses[N];

void addPos(float array[N], float val, int index) {
    array[index] = val;
};

void addMass(float array[N], float val, int index) {
    array[index] = val;
};

void addForce(float array[N][N], float val, int index1, int index2) {
    array[index1][index2] = val;
};

void initForce(float arrayX[N][N], float arrayY[N][N]) {
    int q;
    int n = N;

    for (q = 0; q < n; q++) {
        if (q == 0) {
            addForce(arrayX, 0.0, q, q);
            addForce(arrayX, 0.0, q, q + 1);
            addForce(arrayX, 0.0, q, q + 2);
            addForce(arrayX, 0.0, q, q + 3);
        } else if (q == 1) {
            addForce(arrayX, 0.0, q, q - 1);
            addForce(arrayX, 0.0, q, q);
            addForce(arrayX, 0.0, q, q + 1);
            addForce(arrayX, 0.0, q, q + 2);
        } else if (q == 2) {
            addForce(arrayX, 0.0, q, q - 2);
            addForce(arrayX, 0.0, q, q - 1);
            addForce(arrayX, 0.0, q, q);
            addForce(arrayX, 0.0, q, q + 1);
        } else {
            addForce(arrayX, 0.0, q, q - 3);
            addForce(arrayX, 0.0, q, q - -2);
            addForce(arrayX, 0.0, q, q - 1);
            addForce(arrayX, 0.0, q, q);
        }
    }

    for (q = 0; q < n; q++) {
        if (q == 0) {
            addForce(arrayY, 0.0, q, q);
            addForce(arrayY, 0.0, q, q + 1);
            addForce(arrayY, 0.0, q, q + 2);
            addForce(arrayY, 0.0, q, q + 3);
        } else if (q == 1) {
            addForce(arrayY, 0.0, q, q - 1);
            addForce(arrayY, 0.0, q, q);
            addForce(arrayY, 0.0, q, q + 1);
            addForce(arrayY, 0.0, q, q + 2);
        } else if (q == 2) {
            addForce(arrayY, 0.0, q, q - 2);
            addForce(arrayY, 0.0, q, q - 1);
            addForce(arrayY, 0.0, q, q);
            addForce(arrayY, 0.0, q, q + 1);
        } else {
            addForce(arrayY, 0.0, q, q - 3);
            addForce(arrayY, 0.0, q, q - 2);
            addForce(arrayY, 0.0, q, q - 1);
            addForce(arrayY, 0.0, q, q);
        }
    }
};

void test(GtkWidget *widget, gpointer data) {
    printf("Hello in console from function test\n");
};

void initStr(char str[10], char str2[10], char str3[10], char str4[10], planet* P) {
    sprintf(str, "%f", P->pos_x);
    sprintf(str2, "%f", P->pos_y);
    sprintf(str3, "%f", P->velocity_x);
    sprintf(str4, "%f", P->velocity_y);
};
