#include <iostream>
using namespace std;

class Personagem
{
    double health_points;
    int mana_points = 100;
    double attack;

public:
    virtual void setHp(double hp)
    {
        health_points = hp;
    }

    virtual void setAttack(double at)
    {
        attack = at;
    }
};

class Mago : public Personagem
{

    public:

};

class Guerreiro : public Personagem
{
};

class Arqueiro : public Personagem
{
};

int main()
{
}