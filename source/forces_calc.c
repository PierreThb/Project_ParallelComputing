#include "../header/forces_calc.h"

extern float forcesX[N][N]; //array which contained all forces on X direction betwin planets
extern float forcesY[N][N]; //array which contained all forces on Y direction betwin planets
extern float posX[N], posY[N]; //arrays which contained all X and Y positions
extern const float masses[N];

void forces_calc(float forcesX[N][N], float forcesY[N][N], float *posX, float *posY, float *masses) {
    int i, j, n = N, g = G;
    float forceijX, forceijY, x_diff, y_diff, dist, dist_cubed, temp;

    /* Compute forces */
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            //            printf("posXi=%f / posXj=%f / posYi=%f / posYj= %f / masse[i]=%f / masse[j]=%f\n", posX[i], posX[j], posY[i], posY[j], masses[i], masses[j]);
            x_diff = posX[i] - posX[j];
            //            printf("x_diff%d%d = %f\n", i, j, x_diff);
            y_diff = posY[i] - posY[j];
            //            printf("y_diff%d%d = %f\n", i, j, y_diff);
            dist = sqrt(x_diff * x_diff + y_diff * y_diff);
            dist_cubed = dist * dist*dist;

            forceijX = ((-g * masses[i] * masses[j]) / dist_cubed) * x_diff;
            //            printf("In function forces_calc, force%d%dX = %f\n", i, j, forceijX);
            forceijY = ((-g * masses[i] * masses[j]) / dist_cubed) * y_diff;
            //            printf("In function forces_calc, force%d%dY = %f\n\n", i, j, forceijY);

            forcesX[i][j] = forceijX;
            forcesY[i][j] = forceijY;
            forcesX[j][i] = (-forceijX);
            forcesY[j][i] = (-forceijY);
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
        //        printf("forcesX[0][0] + forcesX[0][1] + forcesX[0][2] + forcesX[0][3]  = %f + %f + %f + %f = %f\n", forcesX[index][0], forcesX[index][1], forcesX[index][2], forcesX[index][3], val);
        return val;
    } else if (index == 1) {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        //        printf("forcesX[1][0] + forcesX[1][1] + forcesX[1][2] + forcesX[1][3]  = %f + %f + %f + %f = %f\n", forcesX[index][0], forcesX[index][1], forcesX[index][2], forcesX[index][3], val);
        return val;
    } else if (index == 2) {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        //        printf("forcesX[2][0] + forcesX[2][1] + forcesX[2][2] + forcesX[2][3]  = %f + %f + %f + %f = %f\n", forcesX[index][0], forcesX[index][1], forcesX[index][2], forcesX[index][3], val);
        return val;
    } else {
        float val = forcesX[index][0] + forcesX[index][1] + forcesX[index][2] + forcesX[index][3];
        //        printf("forcesX[3][0] + forcesX[3][1] + forcesX[3][2] + forcesX[3][3]  = %f + %f + %f + %f = %f\n", forcesX[index][0], forcesX[index][1], forcesX[index][2], forcesX[index][3], val);
        return val;
    }
};

float total_forcesY(int index) {
    if (index == 0) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        //        printf("valtotYQ=%f\n", val);
        return val;
    } else if (index == 1) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        //        printf("valtotYK=%f\n", val);
        return val;
    } else if (index == 2) {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        //        printf("valtotYA=%f\n", val);
        return val;
    } else {
        float val = forcesY[index][0] + forcesY[index][1] + forcesY[index][2] + forcesY[index][3];
        //        printf("valtotYB=%f\n\n", val);
        return val;
    }
};

void compute_all_new_velX(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;
    float total_force;

    total_force = total_forcesX(0);
    //    printf("totalforceonQX=%f\n", total_force);
    temp = velocity_calc(total_force, p1->masse, deltat, p1->velocity_x);
    printf("newVelXQ=%f\n", temp);
    p1->velocity_x = temp;

    total_force = total_forcesX(1);
    //    printf("totalforceonKX=%f\n", total_force);
    temp = velocity_calc(total_force, p2->masse, deltat, p2->velocity_x);
    printf("newVelXK=%f\n", temp);
    p2->velocity_x = temp;

    total_force = total_forcesX(2);
    //    printf("totalforceonAX=%f\n", total_force);
    temp = velocity_calc(total_force, p3->masse, deltat, p3->velocity_x);
    printf("newVelXa=%f\n", temp);
    p3->velocity_x = temp;

    total_force = total_forcesX(3);
    //    printf("totalforceonBX=%f\n", total_force);
    temp = velocity_calc(total_force, p4->masse, deltat, p4->velocity_x);
    printf("newVelXB=%f\n\n", temp);
    p4->velocity_x = temp;

};

void compute_all_new_velY(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;
    float total_force;

    total_force = total_forcesY(0); // totalforce for planet Q
//    printf("totalforceonQY=%f\n", total_force);
    temp = velocity_calc(total_force, p1->masse, deltat, p1->velocity_y);
    printf("newVelYQ=%f\n", temp);
    p1->velocity_y = temp;

    total_force = total_forcesY(1); //totalforce for planet K
//    printf("totalforceonKY=%f\n", total_force);
    temp = velocity_calc(total_force, p2->masse, deltat, p2->velocity_y);
    printf("newVelYK=%f\n", temp);
    p2->velocity_y = temp;

    total_force = total_forcesY(2); //totalforce for planet A
//    printf("totalforceonAY=%f\n", total_force);
    temp = velocity_calc(total_force, p3->masse, deltat, p3->velocity_y);
    printf("newVelYA=%f\n", temp);
    p3->velocity_y = temp;

    total_force = total_forcesY(3); //totalforce for planet B
//    printf("totalforceonBY=%f\n\n", total_force);
    temp = velocity_calc(total_force, p4->masse, deltat, p4->velocity_y);
    printf("newVelYB=%f\n\n", temp);
    p4->velocity_y = temp;

};

void compute_all_new_posX(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;

    temp = position_cacl(p1->pos_x, p1->velocity_x, deltat);
    p1->pos_x = temp;
    printf("newvalXQ=%f\n", temp);
    temp = position_cacl(p2->pos_x, p2->velocity_x, deltat);
    p2->pos_x = temp;
    printf("newvalXK=%f\n", temp);
    temp = position_cacl(p3->pos_x, p3->velocity_x, deltat);
    p3->pos_x = temp;
    printf("newvalXA=%f\n", temp);
    temp = position_cacl(p4->pos_x, p4->velocity_x, deltat);
    p4->pos_x = temp;
    printf("newvalXB=%f\n\n", temp);
};

void compute_all_new_posY(planet* p1, planet* p2, planet* p3, planet* p4) {
    float temp;
    float deltat = DELTA;

    temp = position_cacl(p1->pos_y, p1->velocity_y, deltat);
    p1->pos_y = temp;
    printf("newvalYQ=%f\n", temp);
    temp = position_cacl(p2->pos_y, p2->velocity_y, deltat);
    p2->pos_y = temp;
    printf("newvalYQ=%f\n", temp);
    temp = position_cacl(p3->pos_y, p3->velocity_y, deltat);
    p3->pos_y = temp;
    printf("newvalYQ=%f\n", temp);
    temp = position_cacl(p4->pos_y, p4->velocity_y, deltat);
    p4->pos_y = temp;
    printf("newvalYQ=%f\n\n", temp);
};

