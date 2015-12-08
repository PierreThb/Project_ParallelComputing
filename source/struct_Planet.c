#include "../header/struct_Planet.h"

struct Planet {
    float masse;
    float pos_x;
    float pos_y;
    float velocity_x;
    float velocity_y;
} Planet;

Planet initializeP(Planet P,float masse, float posX, float posY, float vX, float vY) {
    /* initialize PLanet */
    P.masse = masse; //5.2
    P.pos_x = posX; //5.3
    P.pos_y = posY;//12.2
    P.velocity_x = vX;//0
    P.velocity_y = vY;//5
}
