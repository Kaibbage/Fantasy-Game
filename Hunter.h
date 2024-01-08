#include "Character.h"
#include <iostream>
#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


class Hunter:public Character
{

public:

    //Constructor and deconstructor
    Hunter();
    ~Hunter();

    //Initializing methods
    void printstats();
    void optionbar();
    void fight();
    void hunt();
    void treasure();

    void event();
    void biggermoney();
    void biggerhealth();
    void biggerfame();
    void biggerattack();

    void bigmonster();
    void boss();
    void bigboss();
    void biggestboss();

    void battle(int healthMon, int attackMon, string monsType, int mpoints, int famegain, int moneygain);





};

