#include "Warrior.h"

//Method for all battles, different monster stats are sent down according to each monster
void Warrior::battle(int healthMon, int attackMon, string monsType, int mpoints, int famegain, int moneygain)
{
    int attackType;
    int hit;
    int monHit;
    int orihealth = gethealth();

    cout << "You encountered a wild " << monsType << endl;

    //Displaying the sprite and the appropriate monster
    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;
    int monsterwidth = 0;
    int monsterheight = 0;

    const int height = 600;
    const int width = 850;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;
    ALLEGRO_BITMAP *monster = nullptr;

    if (!al_init_image_addon())
    {
        cout << "error" << endl;
    }

    if(healthMon == 20)
    {
        monster = al_load_bitmap("fantasyAssets/lion.png");
    }
    else if(healthMon == 50)
    {
        monster = al_load_bitmap("fantasyAssets/bear.jpg");
    }
    else if(healthMon == 75)
    {
        monster = al_load_bitmap("fantasyAssets/dinosaur.png");
    }
    else if(healthMon == 100)
    {
        monster = al_load_bitmap("fantasyAssets/demon.png");
    }
    else if(healthMon == 200)
    {
        monster = al_load_bitmap("fantasyAssets/dragon.png");
    }

    if(!monster)
    {
        cout << "error2" << endl;
    }

    image = al_load_bitmap("fantasyAssets/WarriorAttack.png");

    if(!image)
    {
        cout <<"error" << endl;
    }

    imagewidth = al_get_bitmap_width(image);
    imageheight = al_get_bitmap_height(image);

    monsterwidth = al_get_bitmap_width(monster);
    monsterheight = al_get_bitmap_height(monster);

    al_draw_scaled_bitmap(image, 0, 0, imagewidth, imageheight, 450, 20, imagewidth / 2, imageheight/2, 0);

    if(healthMon == 20)
    {
        al_draw_scaled_bitmap(monster, 0, 0, monsterwidth, monsterheight,50, 20, monsterwidth/2, monsterheight/2, 0);
    }
    else if(healthMon == 50)
    {
        al_draw_scaled_bitmap(monster, 0, 0, monsterwidth, monsterheight, 20, 100, monsterwidth * 1.8, monsterheight * 1.8, 0);
    }
    else if(healthMon == 75)
    {
        al_draw_scaled_bitmap(monster, 0, 0, monsterwidth, monsterheight, 50, 100, monsterwidth/1.5, monsterheight/1.5, 0);
    }
    else if(healthMon == 100)
    {
        al_draw_scaled_bitmap(monster, 0, 0, monsterwidth, monsterheight, 50, 0, monsterwidth/1.5, monsterheight/1.5, 0);
    }
    else if(healthMon == 200)
    {
        al_draw_scaled_bitmap(monster, 0, 0, monsterwidth, monsterheight,50, 20, monsterwidth/5, monsterheight/5, 0);
    }


    al_flip_display();

    al_rest(2);

    al_destroy_display(display);
    al_destroy_bitmap(image);
    al_destroy_bitmap(monster);

    //Loop for fight
    while(healthMon > 0 && gethealth() > 0)
    {
        cout << "Your health:" << gethealth() << "                   " << monsType << " health:" << healthMon << endl;
        cout << "Your attack:" << getattack() << "                   " << monsType <<" attack:" << attackMon << endl;
        cout << "Would you like to:" << endl << "1. Weak attack" << endl << "2. Medium attack" << endl << "3. Strong attack" << endl << endl;
        cin >> attackType;

        hit = random(1, 10);

        //Your attack
        if(attackType == 1)
        {
            if(hit < 10)
            {
                healthMon = healthMon - getattack();
                cout << "You hit the " << monsType << " and did " << getattack() << " damage"<< endl << endl;
            }
            else if(hit == 10)
            {
                cout << "You missed your attack" << endl << endl;
            }
        }
        else if(attackType == 2)
        {
            if(hit < 6)
            {
                healthMon = healthMon - (2 * getattack());
                cout << "You hit the " << monsType << " and did " << 2 * getattack() << " damage" << endl << endl;
            }
            else if(hit > 5)
            {
                cout << "You missed your attack" << endl << endl;
            }
        }
        else if(attackType == 3)
        {
            if(hit < 3)
            {
                healthMon = healthMon - (5 * getattack());
                cout << "You hit the " << monsType << " and did " << 5 * getattack() << " damage" << endl << endl;
            }
            else if(hit > 2)
            {
                cout << "You missed your attack" << endl << endl;
            }
        }


        //Monster attack
        monHit = random(0, attackMon);

        if(healthMon > 0)
        {
            sethealth(gethealth() - monHit);
            cout << "The " << monsType << " hit you for " << monHit << " damage" << endl << endl;
        }

        if(healthMon <= 0)
        {
            cout << "You have defeated the " << monsType << " you lost " << orihealth - gethealth() << " health in the process." << endl;
            cout << "You have gained " << famegain << " fame and " << moneygain << " gold coins" << endl << endl;
            setfame(getfame() + famegain);
            setmoney(getmoney() + moneygain);
        }
        else if (gethealth() <= 0)
        {
            return;
        }

    }

    setmonsterpoints(getmonsterpoints() + mpoints);

    cout << "You have " << getmonsterpoints() << "/100 monsterpoints" << endl << endl;
}


