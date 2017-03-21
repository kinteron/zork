#include "enemy.h"
#include "includes.h"

Enemy::Enemy(string description, float health, int attack)
{
    this->description = description;
    this->health = health;
    this->attack = attack;
    cout << description.c_str() << endl;
}

float Enemy::getHealth() const
{
    return health;
}

void Enemy::setHealth(float value)
{
    health = value;
}

int Enemy::getAttack() const
{
    return attack;
}

void Enemy::setAttack(int value)
{
    attack = value;
}

string Enemy::shortDescription() const
{
    return description;
}
