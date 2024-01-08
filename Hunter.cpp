#include "Hunter.h"

//Constructor, initializing stats
Hunter::Hunter(){
    setname("Hunter");
    sethealth(18);
    setfame(20);
    setmoney(20);
    sethealthmax(40);
    setfamemax (60);
    setmoneymax(50);
    setattack(4);
}

//Deconstructor
Hunter::~Hunter(){

}

//Printing stats
void Hunter::printstats(){
    cout << "Character:" << getname() << "          Monster points" << getmonsterpoints() << "/100" <<endl;
    cout << "Health:" << gethealth() << "/" << gethealthmax() << endl;
    cout << "Fame:" << getfame() << "/" << getfamemax() << endl;
    cout << "Money:" << getmoney()  << "/" << getmoneymax() << endl << endl;

}

//Showing options and stats
void Hunter::optionbar(){
    cout << "Day " << getday() << endl;
    printstats();

    cout << "What would you like to do today?" << endl;
    cout << "1. Hunt for food" << endl;
    cout << "2. Fight monsters" << endl;
    cout << "3. Search for treasure" << endl;
    cout << "4. Buy weapon upgrade for 4 gold" << endl << endl;
}

//Hunting a monster for food, gain less health than warrior
void Hunter::hunt(){
    int healthgain = 11;
    sethealth(gethealth() + healthgain);

    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;

    const int height = 500;
    const int width = 700;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;

    if (!al_init_image_addon()) {
        cout << "error" << endl;
	}

    image = al_load_bitmap("fantasyAssets/HunterFood.png");

    if(!image){
        cout << "error" << endl;
    }

    imagewidth = al_get_bitmap_width(image);
    imageheight = al_get_bitmap_height(image);

    al_draw_scaled_bitmap(image, 0, 0, imagewidth, imageheight, 50, 50, imagewidth / 2, imageheight / 2, 0)  ;

    al_flip_display();

	al_rest(2);

	al_destroy_display(display);
   	al_destroy_bitmap(image);

    cout << "You caught a yummy deer, you have gained " << healthgain << " health." << endl << endl;

}

//Fighting a weak monster
void Hunter::fight(){

    battle(20, 2, "Tiger", 2, 10, 8);



}

//Searching for treasure for gold coins, gains more gold than warrior
void Hunter::treasure(){
    int treasuregain = 11;
    setmoney(getmoney() + treasuregain);

    cout << "You went searching for treasure and found " << treasuregain << " gold coins" << endl << endl;

    al_init();
    al_init_primitives_addon();

    int imagewidth = 0;
    int imageheight = 0;

    const int height = 500;
    const int width = 700;

    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *image = nullptr;

    if (!al_init_image_addon()) {
        cout << "error" << endl;
	}

    image = al_load_bitmap("fantasyAssets/HunterTreasure.png");

    if(!image){
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

//Gaining attack through purchase or random event
void Hunter::biggerattack(){
    int attackgain;
    attackgain = random(1, 4);
    setattack(getattack() + attackgain);


    cout << "You got a new sword and gained " << attackgain << " attack points" << endl << "attack damage:" << getattack() << "/" << getattackmax() <<endl << endl;
}

//Random event each day
void Hunter::event(){
    int randnum;
    randnum = random(1, 100);

    if(randnum <= 20){
        biggerhealth();
    }
    else if (randnum > 20 && randnum <= 40){
        biggerfame();
    }
    else if (randnum > 40 && randnum <= 60){
        biggermoney();
    }
    else if (randnum > 60 && randnum <= 80){
        biggerattack();
    }
    else if(randnum > 80 && randnum <= 90){
        bigmonster();
    }
    else if (randnum > 90 && randnum <= 95){
        boss();
    }
    else if (randnum > 95 && randnum <= 99){
        bigboss();
    }
    else if (randnum > 20 && randnum <= 40){
        biggestboss();
    }


}





