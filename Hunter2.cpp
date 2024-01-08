#include "Hunter.h"

//Random event to increase or decrease health
void Hunter::biggerhealth(){
    int healthgain;
    int optnum;
    int goodorbad;

    cout << "you see a free buffet, do you want to" << endl << "1. Eat up" << endl << "2. Walk by" << endl;
    cin >> optnum;

    goodorbad = random(1, 2);
    healthgain = random(1, 10);

    if(optnum == 1){
        if(goodorbad == 1){
            sethealth(gethealth() + healthgain);
            sethealthmax(gethealthmax() + healthgain);
            cout << "You enjoyed a hearty meal and gained " << healthgain << " max health and health" << endl << endl;
        }
        else if(goodorbad == 2){
            sethealth(gethealth() - healthgain);

            cout << "You got food poisoning and lost " << healthgain << " health" << endl << endl;
        }

    }

    else if(optnum == 2){
        cout << "You walk away with a growling stomach" << endl << endl;
    }



}

//Random event to increase or decrease fame
void Hunter::biggerfame()
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

//Random event to increase or decrease money
void Hunter::biggermoney()
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

//Fight for big monster
void Hunter::bigmonster()
{
    battle(50, 3, "Big Bear", 5, 15, 12);
}

//Fight for boss monster
void Hunter::boss()
{
    battle(75, 4, "Dinosaur", 20, 20, 16);
}

//Fight for big boss monster
void Hunter::bigboss()
{
    battle(100, 5, "Ancient Demon", 40, 30, 20);
}

//Fight for biggest boss monster
void Hunter::biggestboss()
{
    battle(200, 9, "Legendary dragon", 100, 100, 100);
}


