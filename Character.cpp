#include "Character.h"
#include <time.h>
#include <stdlib.h>


//Constructor
Character::Character()
{
    health = 0;
    fame = 0;
    money = 0;

}

//Deconstructor
Character::~Character()
{
    health = 0;
    fame = 0;
    money = 0;
}

//Getters
int Character::gethealth() const
{
    return health;
}

int Character::getfame() const
{
    return fame;
}

int Character::getmoney() const
{
    return money;
}

int Character:: getattack() const
{
    return attackdamage;
}

int Character::gethealthmax() const
{
    return healthmax;
}

int Character::getfamemax() const
{
    return famemax;
}

int Character::getmoneymax()const
{
    return moneymax;
}

int Character::getattackmax()const
{
    return attackmax;
}

string Character::getname() const
{
    return cType;
}

int Character::getday() const
{
    return day;
}

int Character::getmonsterpoints() const
{
    return monsterpoints;
}

//Setters
void Character::sethealth(int h)
{
    health = h;

    //Not allowing the stat to go over max
    if(h > healthmax)
    {
        health = healthmax;
    }
}


void Character::setfame(int f)
{
    fame = f;

    if(f > famemax)
    {
        fame = famemax;
    }
}

void Character::setmoney(int m)
{
    money = m;

    if(m > moneymax)
    {
        money = moneymax;
    }
}

void Character::setname(string n)
{
    cType = n;
}

void Character::setname(int n)
{
    if(n == 1)
    {
        setname("Warrior");
    }
    else if(n == 2)
    {
        setname("Hunter");
    }
}


void Character::setattack(int a)
{
    attackdamage = a;
}

void Character::sethealthmax(int hm)
{
    healthmax = hm;
}
void Character::setfamemax(int fm)
{
    famemax = fm;
}
void Character::setmoneymax(int mm)
{
    moneymax = mm;
}
void Character::setattackmax(int am)
{
    attackmax = am;
}

void Character::setmonsterpoints(int mp)
{
    monsterpoints = mp;
}


//Ending day and changing stats
void Character::daypass()
{
    health = health - 3;
    fame = fame - 3;
    money = money - 3;
    day++;

}

void Character::setday(int d)
{
    day = d;
}


//Random function, for some reason if you have a second random number it's pseudo randomness moves faster
//When I made random1 it was clearly going up in sequence, random2 seemed more random to my eye
int Character::random(int minimum, int maximum)
{
    srand(time(0));
    int randnum;
    int randnum2;

    randnum = rand()%(maximum - minimum + 1) + minimum;
    randnum2 = rand()%(maximum - minimum + 1) + minimum;



    return randnum2;
}



