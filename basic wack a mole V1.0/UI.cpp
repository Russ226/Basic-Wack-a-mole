#include "UI.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>



void UI::creategrid()
{
    double x,y;
    int counter=0;
    al_init_primitives_addon();
    while(counter<9)
    {

        x=800/12;
        x*=counter;
        //al_draw_line(x,0,x,480,al_map_rgb(155,100,60),3);
        grid[counter][0]=x;
        y=600/10;
        y*=counter;
        //al_draw_line(0,y,529,y,al_map_rgb(155,100,60),3);
        grid[counter][1]=y;
        counter++;

    }
}
void UI::createvectors()
{
    int counter=0;
    float x=0,y=0;

    while(counter<64)
    {
        if(counter<8){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==8){
                y+=60;
                x=0;
            }
        }

        else if(counter>=8&&counter<16){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==16){
                y+=60;
                x=0;
            }
        }

        else if(counter>=16&&counter<24){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==24){
                y+=60;
                x=0;
            }
        }
         else if(counter>=24&&counter<32){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==32){
                y+=60;
                x=0;
            }
        }
         else if(counter>=32&&counter<40){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==40){
                y+=60;
                x=0;
            }
        }
         else if(counter>=40&&counter<48){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==48){
                y+=60;
                x=0;
            }
        }
         else if(counter>=48&&counter<56){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==56){
                y+=60;
                x=0;
            }
        }
         else if(counter>=56&&counter<64){
            vectors[counter][0]=x;
            vectors[counter][1]=y;
            x+=66;
            counter++;
            if(counter==64){
                y+=60;
                x=0;
            }
        }
        else
            ;

    }
}
float UI::getX(int a)
{
    return vectors[a][0];
}
float UI::getY(int a)
{
    return vectors[a][1];
}
void UI::loadfont()
{
    al_init_font_addon();
    al_init_ttf_addon();
    score=al_load_ttf_font("8-BIT WONDER.ttf",15,0);

}
void UI::drawtext()
{


    al_draw_text(score,al_map_rgb(255,255,255),675,10,ALLEGRO_ALIGN_CENTER,"HIGH SCORES");
}

UI::~UI()
{
    delete score;
}
void UI::drawgrid()
{
    //al_init_primitives_addon();
    for(int i=0;i<9;i++){
            al_draw_line(grid[i][0],0,grid[i][0],480,al_map_rgb(155,100,60),3);
            al_draw_line(0,grid[i][1],529,grid[i][1],al_map_rgb(155,100,60),3);

    }

}
void UI::destroyText()
{
    al_destroy_font(score);
}
void UI::startScreen()
{
    al_draw_text(score,al_map_rgb(255,255,255),400,300,ALLEGRO_ALIGN_CENTER,"Press Left Mouse Button to Start");
}
void UI::gameOver()
{
    al_draw_text(score,al_map_rgb(255,255,255),400,100,ALLEGRO_ALIGN_CENTER,"Game Over");
    al_draw_text(score,al_map_rgb(255,255,255),400,300,ALLEGRO_ALIGN_CENTER,"Press Left Mouse Button to Startover");
    al_draw_text(score,al_map_rgb(255,255,255),400,200,ALLEGRO_ALIGN_CENTER,"Press Right Mouse Button to Quit");
}
