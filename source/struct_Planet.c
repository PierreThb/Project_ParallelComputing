#include "../header/struct_Planet.h"

struct Planet{
    float masse;
    float pos_x;
    float pos_y;
    float velocity_x;
    float velocity_y;
}Planet;

Planet initializeP(Planet P,float masse, float posX, float posY, float vX, float vY) {
    /* initialize PLanet */
    P.masse = masse;
    P.pos_x = posX;
    P.pos_y = posY;
    P.velocity_x = vX;
    P.velocity_y = vY;
}
