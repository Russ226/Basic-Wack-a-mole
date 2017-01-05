#ifndef MOLE_H
#define MOLE_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
class Mole
{
    public:
        void drawMole(float x, float y); //drwaws immage on screen
        void loadimage(); //loads image
        virtual ~Mole();
        void destroyMole();//destroy bitmap
        //float moleHeight();
        //float moleWidth();
    protected:
    private:
        ALLEGRO_BITMAP *mole;

};

#endif // MOLE_H
