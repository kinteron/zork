#ifndef ENEMY_H
#define ENEMY_H
#include "includes.h"

class Enemy
{
    string description;
    int health;
    float attack;

public:
    Enemy(string description = "foe", float health = 1, int attack = 999);
    string shortDescription() const;
    float getHealth() const;
    void setHealth(float value);
    int getAttack() const;
    void setAttack(int value);
};

#endif // ENEMY_H
