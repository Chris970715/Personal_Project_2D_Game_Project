#define _CRT_SECURE_NO_WARNINGS
// Your solution may ONLY use functions from the following
// included C and C++ library header files.

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


// You may add your own helper functions or symbolic constants here.
// The member functions below must ALL be correctly coded


class Player
{

protected:
    char* d;


    char name[30];
    float HP;
    float attack;
    float defence;
public:
    Player(char [], float, float, float);
    Player(const Player& source); // Deep copy constructor;
    ~Player(); // destructor
    friend class UserInput;
    friend class UserOutput;
};
class UserInput
{
    char* d;

    char up;
    char down;
    char right;
    char left;
public:
    friend class Player;
    friend class UserOutput;

};
class UserOutput
{


public:

    void theFirst(void);
    Player theUsersetup(void);


    friend class Player;
    friend class UserInput;
};

int main ()
{
    UserOutput printout;
    printout.theFirst();

    Player user1 = printout.theUsersetup();

    return 0;
}
Player::Player(char a[], float b, float c, float d)
{
    for (int i = 0; i < 30; i++)
    {

        if(a[i] != NULL)
        {
            name[i] = a[i];
        }
        else if (a[i] == NULL)
        {
            name[i] = NULL;


        }

    }

    HP = b;
    attack = c;
    defence = d;

}
void UserOutput::theFirst(void)
{
    cout<<"\n===============================================================================================";
    cout<<"\n M       M   00000   NN    N  SSSSSSSS  TTTTTTTTTT  EEEEEEEEE    RRRRRR                        ";
    cout<<"\n M M   M M  0     0  N N   N  S             TT      E            R     R                       ";
    cout<<"\n M   M   M  0     0  N  N  N  SSSSSSSS      TT      EEEEEEEEE    RRRRRR                        ";
    cout<<"\n M       M  0     0  N   N N         S      TT      E            R     R                       ";
    cout<<"\n M       M   00000   N    NN  SSSSSSSS      TT      EEEEEEEEE    R      R                      ";
    cout<<"\n===============================================================================================\n";
}
Player UserOutput::theUsersetup(void)
{
    char user_name1[30];
    char check = NULL;

    system("cls");
    cout << "Please type user name: " << endl;
    gets(user_name1);
    Player monster(user_name1, 100, 1 ,0.5);

    monster.d = new char[strlen(user_name1)];

    for (int i = 0; i < 30; i++)
    {

        if(user_name1[i] != check)
        {
            monster.d[i] = user_name1[i];
        }
        else if (user_name1[i] == check)
        {
            monster.d[i] = NULL;

            return monster;
        }

    }

}
Player::Player(const Player& source) // deep copy constructor
{

    d = new char[strlen(source.d)];

    for(int i = 0; i < 30; i++)
    {
        if(source.d[i] != NULL )
        {
            d[i] = source.d[i];
        }
    }

    HP = source.HP;
    attack = source.attack;
    defence = source.defence;


}
Player::~Player()
{
    delete []d;
}