#ifndef UI_H
#define UI_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

class UI
{
    public:
       void creategrid(); //creates 8x8 grid
       void drawgrid();//draws 8x8 grid
       void createvectors(); // creates coordninates for 8x8 grid
       float getX(int a); // returns an x coordainate from list
       float getY(int a); // returns an y coordainate from list
       void loadfont();
       void drawtext();
       void destroyText();//destroy allegro pointer
       void startScreen();
       void gameOver(); //game over screen
       virtual ~UI();



    protected:
    private:
        float vectors[64][2];
        float grid[9][2];
        ALLEGRO_FONT *score;

};

#endif // UI_H
