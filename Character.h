#include <string>
#include <iostream>
#pragma once

using namespace std;

class Character
{
public:

    //Initializing onstructor and deconstructor
    Character();
    ~Character();


    //Initializing methods
    int gethealth() const;
    int getfame() const;
    int getmoney() const;
    int getattack() const;
    int gethealthmax() const;
    int getfamemax() const;
    int getmoneymax()const;
    int getattackmax()const;
    int getmonsterpoints() const;
    int getday() const;
    string getname() const;

    void daypass();
    void sethealth(int h) ;
    void setfame(int s);
    void setmoney(int m);
    void setname(string n);
    void setname(int n);
    void setattack(int a);
    void sethealthmax(int hm);
    void setfamemax(int fm);
    void setmoneymax(int mm);
    void setattackmax(int am);
    void setmonsterpoints(int mp);
    void setday(int d);

    int random(int minimum, int maximum);



private:

    //Initializing variables
    int health;
    int fame;
    int money;
    int attackdamage;

    int healthmax;
    int famemax;
    int moneymax;
    int attackmax = 100;

    int monsterpoints = 0;
    int day = 1;

    string cType;





};

