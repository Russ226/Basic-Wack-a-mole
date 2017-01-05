#include "Mole.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
void Mole::drawMole(float x, float y)
{

    al_draw_bitmap(mole,x,y,0);

}

Mole::~Mole()
{
    delete mole;
}
void Mole::loadimage()
{
    al_init_image_addon();

    mole= al_load_bitmap("mole.png");

}
/*float Mole::moleHeight()
{
    float h;
    h=al_get_bitmap_height(mole);
    return h;

}
float Mole::moleWidth()
{
    float w;
    w=al_get_bitmap_height(mole);
    return w;
}*/
void Mole::destroyMole()
{
    al_destroy_bitmap(mole);
}
