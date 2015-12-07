#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
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

GtkWidget *window;
GtkWidget *pLabel[19];
GtkWidget *pVBox;
GtkWidget *pHBox, *pHBox2;

gtk_init(&argc, &argv);

window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "N-Body problem");
gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

/* end of loop to destroy the window */
g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

pLabel[0] = gtk_label_new("Planet Q");
pLabel[1] = gtk_label_new("Qx");
pLabel[2] = gtk_label_new("Qy");
pLabel[3] = gtk_label_new("Vx");
pLabel[4] = gtk_label_new("Vy");
pLabel[5] = gtk_label_new("Xq");
pLabel[6] = gtk_label_new("Yq");
pLabel[7] = gtk_label_new("Vqx");
pLabel[8] = gtk_label_new("Vqy");
pLabel[9] = gtk_label_new("Planet K");
pLabel[10] = gtk_label_new("Kx");
pLabel[11] = gtk_label_new("Ky");
pLabel[12] = gtk_label_new("Vx");
pLabel[13] = gtk_label_new("Vy");
pLabel[14] = gtk_label_new("Xk");
pLabel[15] = gtk_label_new("Yk");
pLabel[16] = gtk_label_new("Vkx");
pLabel[17] = gtk_label_new("Vky");
pLabel[18] = gtk_label_new("Display");

/* Création de la GtkBox verticale */
pVBox = gtk_vbox_new(TRUE, 0);
/* Ajout de la GtkVBox dans la fenetre */
gtk_container_add(GTK_CONTAINER(window), pVBox);
gtk_box_pack_start(GTK_BOX(pVBox), pLabel[18], TRUE, FALSE, 0);

/* Création de la box horizontale */
pHBox = gtk_hbox_new(TRUE, 0);
pHBox2 = gtk_hbox_new(TRUE, 0);
/* Ajout de la GtkHBox dans la GtkVBox */
gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
//ajout des labels
gtk_box_pack_start(GTK_BOX(pHBox), pLabel[0], TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(pHBox), pLabel[9], TRUE, FALSE, 0);

//ajout HBox2
gtk_box_pack_start(GTK_BOX(pHBox), pHBox2, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(pHBox), pLabel[1], TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(pHBox), pLabel[5], TRUE, FALSE, 0);

//initialize PLanet
Q.masse=5.2; Q.pos_x=5.3; Q.pos_y=12.2; Q.velocity_x=0.0;Q.velocity_y=5.0;
K.masse=5.3; K.pos_x=7.2; K.pos_y=12.2; Q.velocity_x=0.0;K.velocity_y=6.0;


/* On ajoute le label a l'intérieur de la fenêtre */
//gtk_container_add(GTK_CONTAINER(window), pLabel[0]);
/* Affichage de la fenêtré et de tout ce qu'il contient */
gtk_widget_show_all(window);

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


gtk_main();

return 0;

}
