typedef struct Planet planet;
//struct Planet;
struct Planet{
    float masse;
    float pos_x;
    float pos_y;
    float velocity_x;
    float velocity_y;
}Planet;

planet* initializeP(float masse, float posX, float posY, float vX, float vY);
