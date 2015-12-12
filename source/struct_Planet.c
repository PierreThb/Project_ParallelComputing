#include "../header/struct_Planet.h"

planet* initializeP(float masse, float posX, float posY, float vX, float vY) {
    planet *P = (planet*)malloc(sizeof(planet));
    /* initialize PLanet */
    P->masse = masse;
    P->pos_x = posX;
    P->pos_y = posY;
    P->velocity_x = vX;
    P->velocity_y = vY;
    
    return P;
}
