#include "../header/forces_calc.h"

extern float x_diff, y_diff, dist, dist_cubed, temp;
extern float forcesX[N][N]; //array which contained all forces on X direction betwin planets
extern float forcesY[N][N]; //array which contained all forces on Y direction betwin planets
extern float posX[N], posY[N]; //arrays which contained all X and Y positions
extern const float masses[N];

void forces_calc(Planet Q, Planet K) {
    int q, k, n = N, g = G;
    float deltaT = DELTA;
    float forceqkX, forceqkY, x_diff, y_diff, dist, dist_cubed;

    /* Compute forces */
    for (q = 0; q < n; q++) {
        for (k = q + 1; k < n; k++) {
            x_diff = posX[q] - posX[k]; // = -1.9
            y_diff = posY[q] - posY[k]; // = 0
            dist = sqrt(x_diff * x_diff + y_diff * y_diff); //= 1.9
            dist_cubed = dist * dist*dist; // = 6.859

            forceqkX = ((-g * masses[q] * masses[k]) / dist_cubed) * x_diff; // = 7.634		
            forceqkY = -g * masses[q] * masses[k] / dist_cubed * y_diff; // = 0

            forcesX[k][q] += forceqkX;
            forcesY[k][q] += forceqkY;
            forcesX[q][k] -= forceqkX;
            forcesY[q][k] -= forceqkY;

            /* Compute new X position  */
            temp = Q.pos_x + (Q.velocity_x * deltaT);
            Q.pos_x = temp;
            temp = temp = K.pos_x + (K.velocity_x * deltaT);
            K.pos_x = temp;

            /* Compute new X velocity */
            temp = ((forcesX[k][q] / masses[q]) * deltaT) + Q.velocity_x;
            Q.velocity_x = temp;
            temp = ((forcesX[q][k] / masses[k]) * deltaT) + K.velocity_x;
            K.velocity_x = temp;

            /* Compute new Y position  */
            temp = Q.pos_y + (Q.velocity_y * deltaT);
            Q.pos_y = temp;
            temp = temp = K.pos_y + (K.velocity_y * deltaT);
            K.pos_y = temp;

            /* Compute new Y velocity */
            temp = ((forcesY[k][q] / masses[q]) * deltaT) + Q.velocity_y;
            Q.velocity_y = temp;
            temp = ((forcesY[q][k] / masses[k]) * deltaT) + K.velocity_y;
            K.velocity_y = temp;

            printf("Arriver fin fonction\n");
        }
    }
}