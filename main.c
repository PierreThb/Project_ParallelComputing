#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct_Planet.h"

int main(int argc, char *argv[])
{

Planet Q,K,J;
int number_planet = 3;
float forces[number_planet][number_planet+1];
float pos[number_planet][2];
float x_diff, y_diff, dist, dist_cubed = 0;


Q.masse=5; Q.pos_x=5.3; Q.pos_y=12.2; Q.velocity=112;
K.masse=8; K.pos_x=7.2; K.pos_y=5.6; Q.velocity=135;
J.masse=3; J.pos_x=10.3; J.pos_y=8.1; Q.velocity=88;

pos[0][0] = Q.pos_x; pos[0][1]=Q.pos_y;
pos[1][0]= K.pos_x; pos[1][1]=K.pos_y;
pos[2][0]= J.pos_x; pos[2][1] = J.pos_y;

//printf(pos[0][0]);

for(int i=0;i<number_planet;i++)
{
	forces[i][i]=0;
}

for(int i=0;i<number_planet;i+)
{
	for(int j=1;j<number_planet;j++)
	{
		//x_diff = ;
		//y_diff = ;
		dist = sqrt(x_diff*x_diff + y_diff*y_diff);
		dist_cubed = dist*dist*dist;
		
	}
	
}

return 0;

}
