#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <time.h>
#include <random>
#include <iostream>
#include "Mole.h"
#include "UI.h"

using namespace std;


int main()
{
    srand(time(NULL));
    float x=0,y=0,tempX,tempY;
    float mX=10,mY=10,dX,dY;
    int coord;
    int counter=0,mcounter=0;
    int ScreenWidth=800,ScreenHeight=600;
    bool quit=false ,draw=false,hit=false,start=false,gameover=false;
    Mole mole;
    UI ui;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT event2;
    ALLEGRO_EVENT_QUEUE *eventqueue=NULL;
    ALLEGRO_EVENT_QUEUE *eventqueue2=NULL;
    ALLEGRO_TIMER *moletimer;
    ALLEGRO_TIMER *starttimer;

    if(!al_init())
    {
        al_show_native_message_box(NULL,NULL,NULL,"Could not intialize Al 5",NULL,0);
        return -1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(ScreenWidth,ScreenHeight);
    al_set_window_position(display,200,100);
    al_set_window_title(display,"wack-a-mole");

    if(!display)
    {
        al_show_native_message_box(display,"Title","Settings","was not successful",NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
    al_install_mouse();
    al_init_primitives_addon();

    moletimer= al_create_timer(1.0/1.5);
    eventqueue = al_create_event_queue();
    starttimer= al_create_timer(1.0/60.0);
    eventqueue2 = al_create_event_queue();

    al_register_event_source(eventqueue, al_get_display_event_source(display));
    al_register_event_source(eventqueue, al_get_timer_event_source(moletimer));
    al_register_event_source(eventqueue,al_get_mouse_event_source());
    al_register_event_source(eventqueue2, al_get_display_event_source(display));
    al_register_event_source(eventqueue2, al_get_timer_event_source(starttimer));
    al_register_event_source(eventqueue2,al_get_mouse_event_source());

    ui.loadfont();

    while(start==false&&quit==false) //start screen
    {
        al_wait_for_event(eventqueue2, &event2);
        ui.startScreen();

        if(event2.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            quit = true;
            break;
        }

        else if(event2.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)   //left mouse button to start
        {
            if(event2.mouse.button &1){
                    start=true;
                    mcounter=-1;
            }
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

    }
    al_destroy_timer(starttimer);
    al_destroy_event_queue(eventqueue2);
    ui.destroyText();

    ui.loadfont();
    ui.createvectors();
    ui.creategrid();
    mole.loadimage();


    al_start_timer(moletimer);


    while(quit==false){
        al_wait_for_event(eventqueue, &event);


        if(event.type==ALLEGRO_EVENT_TIMER){    //draws grid and mole
                coord=rand()%64;
                x=ui.getX(coord);
                y=ui.getY(coord);
                draw=true;
                if(draw==true){
                    draw=false;
                    hit=false;
                    al_clear_to_color(al_map_rgb(0,0,0));
                    ui.drawgrid();
                    //ui.drawtext();
                    mole.drawMole(x,y);
                    al_flip_display();
                }
        }
        //al_get_next_event(eventqueue,&event);
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)   //press x on window to exit game
        {
            quit = true;
            break;
        }
        else if(mcounter==5) //gaem over screen after 5 misses
        {
            while(gameover==true){
                al_wait_for_event(eventqueue, &event);

                if(event.mouse.button &1){
                    mcounter=-1;
                    counter=0;
                    gameover=false;
                }
                else if(event.mouse.button &2){
                    quit=true;
                    break;
                }

                ui.gameOver();
                al_flip_display();
                al_clear_to_color(al_map_rgb(0,0,0));
            }
            ui.destroyText();
            ui.loadfont();
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_AXES&&gameover==false){ //mouse movement
            mX=event.mouse.x;
            mY=event.mouse.y;

            }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN&&gameover==false) //detects hit or miss user needs to use left mouse key
        {
            if(event.mouse.button &1){
                dX=event.mouse.x;
                dY=event.mouse.y;
                if((dX>=x&&dX<=x+56)&&x!=tempX){
                    if((dY>=y&&dY<=y+60)&&(x!=tempX)){
                        counter++;
                        hit=true;
                        tempX=x;
                        tempY=y;
                        cout<<counter << endl;
                    }
                }
                else if(hit==false&&tempX!=x){
                    if(tempY!=y){
                        mcounter++;
                        cout << "miss " << mcounter << endl;
                    }
                    if(mcounter==5)
                        gameover=true;
                }
            }
        }
        if(gameover==false){

            al_draw_rectangle(mX,mY,mX+10,mY+10,al_map_rgb(10,200,50),3);
            ui.drawgrid();
            //ui.drawtext();
            mole.drawMole(x,y);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
        }



    }

    mole.destroyMole();
    ui.destroyText();
    ui.~UI();
    mole.~Mole();
    al_destroy_display(display);
    al_destroy_timer(moletimer);
    al_destroy_event_queue(eventqueue);
    return 0;


}
