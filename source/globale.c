#define N 2

float x_diff, y_diff, dist, dist_cubed, temp;
float forcesX[N][N]; //array which contained all forces on X direction betwin planets
float forcesY[N][N]; //array which contained all forces on Y direction betwin planets
float posX[N], posY[N]; //arrays which contained all X and Y positions
const float masses[N];
