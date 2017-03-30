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
//    delete [] description;
    description = "";
    attack = 0;
    health = 0.f;
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
    return attack*GAME_FACTOR;
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
    return "HP " + to_string(getHealth()) + "\nATK " + to_string(getAttack());
}
