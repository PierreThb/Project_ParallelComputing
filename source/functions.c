#include "../header/forces_calc.h"

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
        addForce(arrayX, 0.0, q, q);
        addForce(arrayY, 0.0, q, q);
        if (q == 0) {
            addForce(arrayX, 0.0, q + 1, q);
            addForce(arrayX, 0.0, q, q + 1);
            addForce(arrayY, 0.0, q + 1, q);
            addForce(arrayY, 0.0, q, q + 1);
            //            forcesX[q + 1][q] = 0;
            //            forcesX[q][q + 1] = 0;
            //            forcesY[q + 1][q] = 0;
            //            forcesY[q][q + 1] = 0;
        }
    }
};
