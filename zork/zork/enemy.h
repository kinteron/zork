#ifndef ENEMY_H
#define ENEMY_H
#include "includes.h"

class Enemy
{
    string description;
    int health;
    float attack;

public:
    Enemy(string description = "foe", int health = 1, float attack = 999);
    ~Enemy();
    string shortDescription() const;
    int getHealth() const;
    void setHealth(int value);
    float getAttack() const;
    void setAttack(float value);
    string longDescription() const;

};

#endif // ENEMY_H
