#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

class Player
{
    double health;
    double attack;
    double crit_rate[5] = {0.2, 0.4, 0.6, 0.8, 1.0};
    bool crit_chance = false;

public:
    void setHealth(double newHealth)
    {
        if (health > 0.0)
        {
            health = newHealth;
        }
    }

    double getHealth()
    {
        return health;
    }

    double getAttack()
    {
        return attack;
    }

    double getCritRate()
    {
        srand(time(0));
        int rand_num = rand() % 4;
        return crit_rate[rand_num];
    }

    bool getCritChance()
    {
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(0, 1);
        crit_chance = dis(gen);
        if (crit_chance == true)
        {
            return getCritRate();
        }
        return false;
    }
};

class Monster
{
    double health;
    double attack;
};
