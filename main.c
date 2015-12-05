#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct_Planet.h"

int main(int argc, char *argv[])
{
int i,j =0;
Planet Q,K,J; //declare 3 struct Planet
int number_planet = 3; // I try with 3 planet to begin
float forces[number_planet][number_planet]; //array which contained all forces betwin planets
float pos[number_planet][2]; //array which contained all positions of all planets
float x_diff, y_diff, dist, dist_cubed = 0;
float forceQK[3], forceQJ[3], forceKJ[3]; //each array contain 3 different forces, in order force on X, force on Y and then force between planet

//initialize PLanet
Q.masse=5; Q.pos_x=5.3; Q.pos_y=12.2; Q.velocity=112;
K.masse=8; K.pos_x=7.2; K.pos_y=5.6; Q.velocity=135;
J.masse=3; J.pos_x=10.3; J.pos_y=8.1; Q.velocity=88;

//initialize posotion of all planets
pos[0][0] = Q.pos_x; pos[0][1]=Q.pos_y;
pos[1][0]= K.pos_x; pos[1][1]=K.pos_y;
pos[2][0]= J.pos_x; pos[2][1] = J.pos_y;

//printf("pos 1/0 = %f \n",pos[1][0]);
//printf("numberplanet-1 = %d \n",number_planet-1);

for(i=0;i<number_planet;i++) //to initialize diagonal of the array at 0 0 0
{
	forces[i][i]=0;
	//printf("forces of %d/%d = %f \n",i,i,forces[i][i]);
}

for(i=0;i<number_planet-1;i++)//i max is at 1
{	
	for(j=0;j<number_planet-1;j++)//j max is at 1
	{
		if(i==0){ //QK
			printf("enter loop i==0 \n");
			x_diff = pos[i][i]-pos[j+1][i];
			printf("x = %f \n",x_diff); 
			y_diff = pos[i][i+1]-pos[j+1][i+1];
			printf("y = %f \n",y_diff);
			
			dist = sqrt(x_diff*x_diff + y_diff*y_diff); //(i==0)=> dist between QK / (i==1 && j==0)=> dist between QJ / else between KJ
			dist_cubed = dist*dist*dist;
			forceQK[0] = G*Q.masse*K.masse/dist_cubed * x_diff;
			forceQk[1] = G*Q.masse*K.masse/dist_cubed * y_diff;
			forceQK[2] = 
			
		}else if(i==1 && j==0){ //QJ
			printf("enter loop i==1 && j==0 \n");
			x_diff = pos[i][j]-pos[i+1][j];
			printf("x = %f \n",x_diff);
			y_diff = pos[i][i]-pos[i+1][i];
			printf("y = %f \n",y_diff);
		}else{ //KJ
			printf("enter loop else \n");
			x_diff = pos[i][j-1]-pos[i-1][j-1];
			printf("x = %f \n",x_diff);
			y_diff = pos[i][i]-pos[i-1][i];
			printf("y = %f \n",y_diff);
		}
		

		
	}			
}

return 0;

}
