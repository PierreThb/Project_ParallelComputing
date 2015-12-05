#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct_Planet.h"

int main(int argc, char *argv[])
{
int q,k;
int n=2;
Planet Q,K; //declare 2 struct Planet
float forcesX[n][n]; //array which contained all forces on X direction betwin planets
float forcesY[n][n]; //array which contained all forces on Y direction betwin planets
float posX[n], posY[n]; //arrays which contained all X and Y positions
float masses[n];
float x_diff, y_diff, dist, dist_cubed = 0;
float G = 1;
float forceqkX, forceqkY;

//initialize PLanet
Q.masse=5.2; Q.pos_x=5.3; Q.pos_y=12.2; Q.velocity_x=0.0;Q.velocity_y=5.0;
K.masse=5.3; K.pos_x=7.2; K.pos_y=12.2; Q.velocity_x=0.0;K.velocity_y=6.0;

//initialize posotion of all planets
posX[0]=Q.pos_x; posX[1]=K.pos_x;
posY[0]=Q.pos_y; posY[1]=K.pos_y;

masses[0]=Q.masse; masses[1]=K.masse;

for(q=0;q<n;q++) //to initialize all forces at 0
{
	forcesX[q][q]=0;
	forcesY[q][q]=0;
	if(q == 0){
		forcesX[q+1][q]=0;
		forcesX[q][q+1]=0;
		forcesY[q+1][q]=0;
		forcesY[q][q+1]=0;
	}
}

for(q=0;q<n;q++)
{	
	for(k=q+1;k<n;k++)
	{
		x_diff = posX[q]-posX[k]; // = -1.9
		y_diff = posY[q]-posY[k]; // = 0
		dist = sqrt(x_diff*x_diff + y_diff*y_diff); //= 1.9
		dist_cubed = dist*dist*dist; // = 6.859
										
		forceqkX = ((-G * masses[q] * masses[k]) / dist_cubed) * x_diff; // = 7.634		
		forceqkY = -G * masses[q] * masses[k] / dist_cubed * y_diff; // = 0

		forcesX[k][q] += forceqkX;
		forcesY[k][q] += forceqkY;
		forcesX[q][k] -= forceqkX;
		forcesY[q][k] -= forceqkY;
		
	}			
}

return 0;

}
