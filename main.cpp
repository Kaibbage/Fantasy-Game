//Kai Sundararaj
//May 20, 2021
//ICS4U
//Mrs. Cullum
//This program is a fantasy game. You can choose from 2 classes. Your goal is to survive and defeat enough monsters to earn 100 monster points
//You have 3 major stats that decrease by 3 each day, if any of them drop below 0 you lose. If you lose a fight to a monster, you also lose the game
//There are actions you can take every day, and random events that occur each day. More detail about the game is described in the introducting game block of couts

#include <iostream>
#include "Warrior.h"
#include "Hunter.h"
#include <windows.h>


using namespace std;

int main()
{

    //Initializing some variables for choosing and seeing if the player won
    bool win = false;
    int charChoose = 0;
    int optionNum = 0;

    //Introducing game
    cout << "Hello adventurer. " << endl;
    cout << "You are in a game where you must stay alive and defeat enough monsters to earn 100 monster points to beat the game." << endl;
    cout << "There are 3 major stats, health, fame, and money. " << endl;
    cout << "You will lose 3 of each major stat at the end of every day." << endl;
    cout << "There is another stat called attack, which determines how much damage you do to monsters." << endl;
    cout << "Each day, you can choose 1 of 4 options. Hunting for food will heal you." << endl;
    cout << "Fighting a monster will give you a small amount of monster points after a battle," << endl;
    cout << "give you fame and money, and make you lose some health." << endl;
    cout << "Searching for treasure will give you money, and buying a weapon upgrade will increase your attack." << endl;
    cout << "Every day there will be a random event, it could be good or bad, it might even be some sort of boss monster. " << endl;
    cout << "Stronger monsters give more points, and weaker monsters give less." << endl;
    cout << "There are 2 classes to choose from at the start of your journey. Warrior and Hunter." << endl;
    cout << "Warriors have higher base health, more base attack, and higher healing." << endl;
    cout << "Hunters have more well rounded base stats, and a 30% dodge chance in fights." << endl;
    cout << "Good luck!" << endl << endl;

    //Asking the player what character they want to be
    cout << "What would you like to play as?" << endl << "1. Warrior" << endl << "2. Hunter" << endl;
    cin >> charChoose;

    //Displaying pictures of warrior and hunter sprites
    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;

    const int height = 600;
    const int width = 800;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;
    ALLEGRO_BITMAP *image2 = nullptr;

    if (!al_init_image_addon())
    {
        cout << "error" << endl;
    }

    image = al_load_bitmap("fantasyAssets/WarriorSpriteBasic.png");
    image2 = al_load_bitmap("fantasyAssets/HunterSpriteBasic.png");

    if(!image)
    {
        cout << "error" << endl;
    }

    imagewidth = al_get_bitmap_width(image);
    imageheight = al_get_bitmap_height(image);

    al_draw_scaled_bitmap(image, 0, 0, imagewidth, imageheight, 0, 0, imagewidth / 2, imageheight / 2, 0);
    al_draw_scaled_bitmap(image2, 0, 0, imagewidth, imageheight, 400, 40, imagewidth / 2, imageheight / 2, 0);

    al_flip_display();

    al_rest(4);

    al_destroy_display(display);
    al_destroy_bitmap(image);
    al_destroy_bitmap(image2);





    if(charChoose == 1)
    {
        //Initializing the character
        Warrior Jim;
        Jim.setname(charChoose);

        cout << "You have chosen:" << Jim.getname() << endl << endl;;

        //Playing game
        while(Jim.getfame() > 0 && Jim.gethealth() > 0 && Jim.getmoney() > 0)
        {
            //Showing base options and executing them
            Jim.optionbar();
            cin >> optionNum;

            if(optionNum == 1)
            {
                Jim.hunt();
            }
            else if(optionNum == 2)
            {
                Jim.fight();
            }
            else if(optionNum == 3)
            {
                Jim.treasure();
            }
            else if(optionNum == 4)
            {
                Jim.biggerattack();
                Jim.setmoney(Jim.getmoney() - 4);
            }


            //Doing event
            cout << "Later that day, ";
            Jim.event();

            //Ending the loop if the player wins
            if(Jim.getmonsterpoints() >= 100)
            {
                win = true;
                break;
            }


            //Moving on to the next day and having the player lose 3 of each major stat
            Jim.daypass();
        }
        //Displaying a different message if the player wins or loses
        if(win == true)
        {
            cout << "Congratulations " << Jim.getname() << "you have beaten the game by earning " << Jim.getmonsterpoints() << " monsterpoints!" << endl;
        }
        else if(win == false)
        {
            cout << "You have died, better luck next time." << endl;
        }

    }
    else if(charChoose == 2)
    {
        Hunter Jim;
        Jim.setname(charChoose);

        cout << "You have chosen:"<< Jim.getname() << endl;

        while(Jim.getfame() > 0 && Jim.gethealth() > 0 && Jim.getmoney() > 0)
        {
            Jim.optionbar();
            cin >> optionNum;

            if(optionNum == 1)
            {
                Jim.hunt();
            }
            else if(optionNum == 2)
            {
                Jim.fight();
            }
            else if(optionNum == 3)
            {
                Jim.treasure();
            }
            else if(optionNum == 4)
            {
                Jim.biggerattack();
                Jim.setmoney(Jim.getmoney() - 4);
            }

            cout << "Later that day, ";
            Jim.event();

            if(Jim.getmonsterpoints() >= 100)
            {
                win = true;
                break;
            }
            Jim.daypass();

        }
        if(win == true)
        {
            cout << "Congratulations " << Jim.getname() << "you have beaten the game by earning " << Jim.getmonsterpoints() << " monsterpoints!" << endl;
        }
        else if(win == false)
        {
            cout << "You have died, better luck next time." << endl;
        }

    }


    else
    {
        cout << "Error";
    }




}
