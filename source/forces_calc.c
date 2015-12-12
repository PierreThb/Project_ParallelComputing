#include "../header/forces_calc.h"

extern float forcesX[N][N]; //array which contained all forces on X direction betwin planets
extern float forcesY[N][N]; //array which contained all forces on Y direction betwin planets
extern float posX[N], posY[N]; //arrays which contained all X and Y positions
extern const float masses[N];

void forces_calc() {
    int i, j, n = N, g = G;
    float forceijX, forceijY, x_diff, y_diff, dist, dist_cubed, temp;

    /* Compute forces */
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            x_diff = posX[i] - posX[j];
            y_diff = posY[i] - posY[j];
            dist = sqrt(x_diff * x_diff + y_diff * y_diff);
            dist_cubed = dist * dist*dist;

            forceijX = ((-g * masses[i] * masses[j]) / dist_cubed) * x_diff; 	
            forceijY = ((-g * masses[i] * masses[j]) / dist_cubed) * y_diff; 

            forcesX[i][j] += forceijX;
            forcesY[i][j] += forceijY;
            forcesX[j][i] -= forceijX;
            forcesY[j][i] -= forceijY;
        }     
    }
};

float position_cacl(float pos, float vel, float deltat) {
    float val = pos + (vel * deltat);
    return val;
};

float velocity_calc(float totalForces, float masse, float deltat, float vel) {
    float val = ((totalForces / masse) * deltat) + vel;
    return val;
};

float total_forcesX(int index) {
    if (index == 0) {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        return val;
    } else if (index == 1) {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        return val;
    } else if (index == 2) {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        return val;
    } else {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        return val;
    }
};

float total_forcesY(int index) {
    if (index == 0) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        return val;
    } else if (index == 1) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        return val;
    } else if (index == 2) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        return val;
    } else {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        return val;
    }
};

void compute_all_new_velX(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;
    float total_force;

    total_force = total_forcesX(0);
    temp = velocity_calc(total_force, p1->masse, deltat, p1->velocity_x);
    p1->velocity_x = temp;

    total_force = total_forcesX(1);
    temp = velocity_calc(total_force, p2->masse, deltat, p2->velocity_x);
    p2->velocity_x = temp;
    
    total_force = total_forcesX(2);
    temp = velocity_calc(total_force, p3->masse, deltat, p3->velocity_x);
    p3->velocity_x = temp;
    
    total_force = total_forcesX(3);
    temp = velocity_calc(total_force, p4->masse, deltat, p4->velocity_x);
    p4->velocity_x = temp;

};

void compute_all_new_velY(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;
    float total_force;

    total_force = total_forcesY(0); // totalforce for planet Q
    temp = velocity_calc(total_force, p1->masse, deltat, p1->velocity_y);
    p1->velocity_y = temp;

    total_force = total_forcesY(1); //totalforce for planet K
    temp = velocity_calc(total_force, p2->masse, deltat, p2->velocity_y);
    p2->velocity_y = temp;

    total_force = total_forcesY(2);//totalforce for planet A
    temp = velocity_calc(total_force, p3->masse, deltat, p3->velocity_y);
    p3->velocity_y = temp;

    total_force = total_forcesY(3);//totalforce for planet B
    temp = velocity_calc(total_force, p4->masse, deltat, p4->velocity_y);
    p4->velocity_y = temp;

};

void compute_all_new_posX(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;

    temp = position_cacl(p1->pos_x, p1->velocity_x, deltat);
    p1->pos_x = temp;
    temp = position_cacl(p2->pos_x, p2->velocity_x, deltat);
    p2->pos_x = temp;
    temp = position_cacl(p3->pos_x, p3->velocity_x, deltat);
    p3->pos_x = temp;
    temp = position_cacl(p4->pos_x, p4->velocity_x, deltat);
    p4->pos_x = temp;
};

void compute_all_new_posY(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;

    temp = position_cacl(p1->pos_y, p1->velocity_y, deltat);
    p1->pos_y = temp;
    temp = position_cacl(p2->pos_y, p2->velocity_y, deltat);
    p2->pos_y = temp;
    temp = position_cacl(p3->pos_y, p3->velocity_y, deltat);
    p3->pos_y = temp;
    temp = position_cacl(p4->pos_y, p4->velocity_y, deltat);
    p4->pos_y = temp;
};

