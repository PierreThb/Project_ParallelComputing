#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
//#include "../header/struct_Planet.h"
#include "../header/forces_calc.h"
#include "../header/functionsGTK.h"
#include "../header/functions.h"

#define N 4
#define G 1
#define DELTA 0.1
#define NBLABEL 16

float forcesX[N][N]; //array which contained all forces on X direction between planets
float forcesY[N][N]; //array which contained all forces on Y direction between planets
float posX[N], posY[N]; //arrays which contained all X and Y positions
float masses[N];
char str[10], str2[10], str3[10], str4[10], str5[10], str6[10], str7[10], str8[10];
char str9[10], str10[10], str11[10], str12[10], str13[10], str14[10], str15[10], str16[10];
planet *Q;
planet *K;
planet *A;
planet *B;
GtkWidget **tabLabel;
GtkBuilder *builder;
char **name;

void printest(planet* P) {
    printf("m=%f, x=%f, y=%f, vx=%f, vy=%f\n", P->masse, P->pos_x, P->pos_y, P->velocity_x, P->velocity_y);
};

void displayInfo(GtkWidget *widget, gpointer data) {
    /* Compute */

    forces_calc(forcesX, forcesY, posX, posY, masses); //function forces_calc in file forces_calc.c

    compute_all_new_posX(Q, K, A, B); //function in file forces_calc.c    
    compute_all_new_posY(Q, K, A, B); //function in file forces_calc.c
    compute_all_new_velX(Q, K, A, B); //function in file forces_calc.c
    compute_all_new_velY(Q, K, A, B); //function in file forces_calc.c
    //    printest(Q);
    /* Get informations of planets to display in the window */
    /* Planet Q */
    initStr(str, str2, str3, str4, Q); //function initStr in file functions.c
    /* Planet K */
    initStr(str5, str6, str7, str8, K);
    /* Planet A */
    initStr(str9, str10, str11, str12, A);
    /* Planet B */
    initStr(str13, str14, str15, str16, B);

    /* Display all informations in the label of the window */
    setLabel(tabLabel[0], str); //function setLabel in file functionsGTK.c
    setLabel(tabLabel[1], str2);
    setLabel(tabLabel[2], str3);
    setLabel(tabLabel[3], str4);
    setLabel(tabLabel[4], str5);
    setLabel(tabLabel[5], str6);
    setLabel(tabLabel[6], str7);
    setLabel(tabLabel[7], str8);
    setLabel(tabLabel[8], str9);
    setLabel(tabLabel[9], str10);
    setLabel(tabLabel[10], str11);
    setLabel(tabLabel[11], str12);
    setLabel(tabLabel[12], str13);
    setLabel(tabLabel[13], str14);
    setLabel(tabLabel[14], str15);
    setLabel(tabLabel[15], str16);
};

int main(int argc, char **argv) {
    int i = 0;
    /* Declarations */
    Q = initializeP(5.2, 5.3, 2.1, 1, 5.0);
    K = initializeP(5.3, 7.2, 4.5, 1, 6.0);
    A = initializeP(5.4, 8.3, 12.2, 1, 5.5);
    B = initializeP(5.5, 4.5, 8.6, 1, 5.4);
    tabLabel = malloc(sizeof (GtkWidget)*16); //Array of GtkWidget LAbel for the window
    name = (char*[]){"res_posXQ", "res_posYQ", "res_velXQ", "res_velYQ", "res_posXK", "res_posYK", "res_velXK", "res_velYK", "res_posXA", "res_posYA", "res_velXA", "res_velYA", "res_posXB", "res_posYB", "res_velXB", "res_velYB"}; //array which contain the name of different element of the window

    /* put position of all planets in the array*/
    /* positions on X */
    addPos(posX, Q->pos_x, 0); //function addPos in file functions.c
    addPos(posX, K->pos_x, 1);
    addPos(posX, A->pos_x, 2);
    addPos(posX, B->pos_x, 3);
    /* positions on Y */
    addPos(posY, Q->pos_y, 0);
    addPos(posY, K->pos_y, 1);
    addPos(posY, A->pos_y, 2);
    addPos(posY, B->pos_y, 3);

    /* put masse of all planets in the arrey */
    addMass(masses, Q->masse, 0); //function addMass in file functions.c
    addMass(masses, K->masse, 1);
    addMass(masses, A->masse, 2);
    addMass(masses, B->masse, 3);

    /* to initialize all forces at 0 */
    initForce(forcesX, forcesY); //function initForce in file functions.c

    /* Get informations of planets to display in the window */
    /* Planet Q */
    initStr(str, str2, str3, str4, Q); //function initStr in file functions.c
    /* Planet K */
    initStr(str5, str6, str7, str8, K);
    /* Planet A */
    initStr(str9, str10, str11, str12, A);
    /* Planet B */
    initStr(str13, str14, str15, str16, B);

    /***  GTK ELEMENTS ***/


    GtkWidget *window;
    GError *error = NULL;

    /* Init GTK+ */
    gtk_init(&argc, &argv);

    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if (!gtk_builder_add_from_file(builder, "./source/glade/nbodyP.glade", &error)) {
        g_warning("%s", error->message);
        g_free(error);
        return ( 1);
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    /* end of loop to destroy the window */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *pQuitBtn = buildButtonQuit(builder); //function buildButtonQuit in file functionsGTK.c
    GtkWidget *pRunBtn = buildButtonRun(builder); //function buildButtonRun in file functionsGTK.c

    g_signal_connect(G_OBJECT(pRunBtn), "clicked", G_CALLBACK(displayInfo), NULL);

    /* Display all informations in the label of the window */
    tabLabel[0] = initLabel(builder, str, name[0]); //function initLabel in file functionsGTK.c
    tabLabel[1] = initLabel(builder, str2, name[1]);
    tabLabel[2] = initLabel(builder, str3, name[2]);
    tabLabel[3] = initLabel(builder, str4, name[3]);
    tabLabel[4] = initLabel(builder, str5, name[4]);
    tabLabel[5] = initLabel(builder, str6, name[5]);
    tabLabel[6] = initLabel(builder, str7, name[6]);
    tabLabel[7] = initLabel(builder, str8, name[7]);
    tabLabel[8] = initLabel(builder, str9, name[8]);
    tabLabel[9] = initLabel(builder, str10, name[9]);
    tabLabel[10] = initLabel(builder, str11, name[10]);
    tabLabel[11] = initLabel(builder, str12, name[11]);
    tabLabel[12] = initLabel(builder, str13, name[12]);
    tabLabel[13] = initLabel(builder, str14, name[13]);
    tabLabel[14] = initLabel(builder, str15, name[14]);
    tabLabel[15] = initLabel(builder, str16, name[15]);

    /* Connect signals */
    gtk_builder_connect_signals(builder, NULL);

    /* Destroy builder, since we don't need it anymore */
    g_object_unref(G_OBJECT(builder));

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show(window);

    /* Start main loop */
    gtk_main();

    /***   END GTK  ***/






}


