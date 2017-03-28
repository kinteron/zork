#include "enemy.h"
#include "includes.h"

Enemy::Enemy(string description, int health, float attack)
{
    this->description = description;
    this->health = health;
    this->attack = attack;
}

Enemy::~Enemy(){
//    delete description; //is a pointer
    //primitives don't have to be deleted
}

int Enemy::getHealth() const
{
    return health;
}

void Enemy::setHealth(int value)
{
    health = value;
}

float Enemy::getAttack() const
{
    return attack;
}

void Enemy::setAttack(float value)
{
    attack = value;
}

string Enemy::shortDescription() const
{
    return description;
}

string Enemy::longDescription() const{
    return shortDescription() + "\nHP " + to_string(getHealth()) + "\nATK " + to_string(getAttack());
}
