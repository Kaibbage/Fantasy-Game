#include "Warrior.h"

//Random event to gain or lose health
void Warrior::biggerhealth()
{
    int healthgain;
    int optnum;
    int goodorbad;

    cout << "you see a free buffet, do you want to" << endl << "1. Eat up" << endl << "2. Walk by" << endl;
    cin >> optnum;

    goodorbad = random(1, 2);
    healthgain = random(1, 10);

    if(optnum == 1)
    {
        if(goodorbad == 1)
        {
            sethealth(gethealth() + healthgain);
            sethealthmax(gethealthmax() + healthgain);
            cout << "You enjoyed a hearty meal and gained " << healthgain << " max health and health" << endl << endl;
        }
        else if(goodorbad == 2)
        {
            sethealth(gethealth() - healthgain);

            cout << "You got food poisoning and lost " << healthgain << " health" << endl << endl;
        }
    }
    else if(optnum == 2)
    {
        cout << "You walk away with a growling stomach" << endl << endl;
    }

}

//Random event to gain or lose fame
void Warrior::biggerfame()
{
    int famegain;
    int optnum;
    int goodorbad;

    cout << "you see someone about to fall off a tree, do you want to" << endl << "1. Try to save them" << endl << "2. Walk by and pretend you see nothing" << endl;
    cin >> optnum;

    goodorbad = random(1, 2);
    famegain = random(1, 10);


    if(optnum == 1)
    {
        if(goodorbad == 1)
        {
            setfame(getfame() + famegain);
            setfamemax(getfamemax() + famegain);
            cout << "You saved someone in trouble, you have gained " << famegain << " max fame and fame" << endl << endl;
        }
        else if(goodorbad == 2)
        {
            setfame(getfame() - famegain);
            cout << "You missed catching the person and became a laughtingstock. You lost " << famegain << " fame" << endl << endl;
        }
    }

    else if(optnum == 2)
    {
        cout << "You walk away with a heavy heart, feeling ashamed of your cowardice." << endl << endl;
    }
}


//Random event to gain or lose money
void Warrior::biggermoney()
{
    int moneygain;
    int optnum;
    int goodorbad;

    cout << "you see a wallet on the ground" << endl << "1. Pick it up and open it" << endl << "2. Walk by and leave it for the owner to find" << endl;
    cin >> optnum;

    goodorbad = random(1, 2);
    moneygain = random(1, 10);


    if(optnum == 1)
    {
        if(goodorbad == 1)
        {
            setmoney(getmoney() + moneygain);
            setmoneymax(getmoneymax() + moneygain);
            cout << "You found a wallet with " << moneygain << " gold coins and space for those gold coins" << endl << endl;
        }
        else if(goodorbad == 2)
        {
            setmoney(getmoney() - moneygain);
            cout << "The wallet jumps into your bag, steals some coins, and explodes. You lost " << moneygain << " gold coins" << endl << endl;
        }
    }

    else if(optnum == 2)
    {
        cout << "You walk away , not wanting to get in trouble." << endl << endl;
    }


}

//Random event to send you to a big monster fight
void Warrior::bigmonster()
{
    battle(50, 3, "Big Bear", 8, 15, 12);
}

//Random event to send you to a boss monster fight
void Warrior::boss()
{
    battle(75, 4, "Dinosaur", 20, 20, 16);
}

//Random event to send you to a big boss monster fight
void Warrior::bigboss()
{
    battle(100, 5, "Ancient Demon", 40, 30, 20);
}

//Random event to send you to the biggest monster fight
void Warrior::biggestboss()
{
    battle(200, 9, "Legendary Dragon", 100, 100, 100);
}

