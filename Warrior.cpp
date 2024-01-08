#include "Warrior.h"

//Constructor, setting up base stats
Warrior::Warrior()
{
    sethealth(35);
    setfame(15);
    setmoney(15);
    sethealthmax(60);
    setfamemax(40);
    setmoneymax(40);
    setattack(6);
}

//Deconstructor
Warrior::~Warrior()
{

}

//Printing stats
void Warrior::printstats()
{
    cout << "Character:" << getname() << "          Monster points " << getmonsterpoints() << "/100" <<endl;
    cout << "Health:" << gethealth() << "/" << gethealthmax() << endl;
    cout << "Fame:" << getfame() << "/" << getfamemax() << endl;
    cout << "Money:" << getmoney()  << "/" << getmoneymax() << endl << endl;

}

//Showing options and printing stats
void Warrior::optionbar()
{
    cout << "Day " << getday() << endl;
    printstats();
    cout << "What would you like to do today?" << endl;
    cout << "1. Hunt for food" << endl;
    cout << "2. Fight monsters" << endl;
    cout << "3. Search for treasure" << endl;
    cout << "4. Buy weapon upgrade for 4 gold" << endl << endl;
}

//Hunting a deer to gain health
void Warrior::hunt()
{
    int healthgain = 13;
    sethealth(gethealth() + healthgain);

    cout << "You caught a yummy deer, you have gained " << healthgain << " health." << endl << endl;

    //Displaying warrior sprite
    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;

    const int height = 500;
    const int width = 700;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;

    if (!al_init_image_addon())
    {
        cout << "error" << endl;
    }

    image = al_load_bitmap("fantasyAssets/WarriorFood.png");

    if(!image)
    {
        cout << "error" << endl;
    }

    imagewidth = al_get_bitmap_width(image);
    imageheight = al_get_bitmap_height(image);

    al_draw_scaled_bitmap(image, 0, 0, imagewidth, imageheight, 50, 50, imagewidth / 2, imageheight / 2, 0)  ;

    al_flip_display();

    al_rest(2);

    al_destroy_display(display);
    al_destroy_bitmap(image);

}

//Fighting the weakeest type of monster for fame and gold
void Warrior::fight()
{

    int famegain = 9;
    setfame(getfame() + famegain);

    battle(20, 2, "Tiger", 2, 9, 8);


}

//Looking for treasure for money
void Warrior::treasure()
{
    int treasuregain = 9;
    setmoney(getmoney() + treasuregain);

    cout << "You went searching for treasure and found " << treasuregain << " gold coins" << endl << endl;

    //Displaying Warrior sprite
    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;

    const int height = 500;
    const int width = 700;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;

    if (!al_init_image_addon())
    {
        cout << "error" << endl;
    }

    image = al_load_bitmap("fantasyAssets/WarriorTreasure.png");

    if(!image)
    {
        cout << "error" << endl;
    }

    imagewidth = al_get_bitmap_width(image);
    imageheight = al_get_bitmap_height(image);

    al_draw_scaled_bitmap(image, 0, 0, imagewidth, imageheight, 50, 50, imagewidth / 2, imageheight / 2, 0)  ;

    al_flip_display();

    al_rest(2);

    al_destroy_display(display);
    al_destroy_bitmap(image);
}

//Gaining attack through an event or a purchase
void Warrior::biggerattack()
{
    int attackgain;
    attackgain = random(1, 4);
    setattack(getattack() + attackgain);

    cout << "You got a new sword and gained " << attackgain << " attack points" << endl << "attack damage:" << getattack() << "/" << getattackmax() <<endl << endl;


}

//Randomly choosing an event each day
void Warrior::event()
{
    int randnum;
    randnum = random(80, 90);

    if(randnum <= 20)
    {
        biggerhealth();
    }
    else if (randnum > 20 && randnum <= 40)
    {
        biggerfame();
    }
    else if (randnum > 40 && randnum <= 60)
    {
        biggermoney();
    }
    else if (randnum > 60 && randnum <= 80)
    {
        biggerattack();
    }
    else if(randnum > 80 && randnum <= 90)
    {
        bigmonster();
    }
    else if (randnum > 90 && randnum <= 95)
    {
        boss();
    }
    else if (randnum > 95 && randnum <= 99)
    {
        bigboss();
    }
    else if (randnum > 20 && randnum <= 40)
    {
        biggestboss();
    }
}




