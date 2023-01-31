//
// Created by program_machine on 2023/1/30.
//

#pragma once
#include "Game.h"

class Revolver{
public:
    int bulletNum;
    // A revolver has six slots for bullets, after one shot, it will turn to the next slot
    // Using an array to represent magazine
    int magazine[6];
    int index; // range 0~5, the gun will use this slot when someone pull the trigger
    int addIndex; // range 0~5, for
    Revolver();

    void AddBullet();
    // It will return 1 or 0, 1 means the gun shoot a bullet so one man will die
    bool Shoot();
    void setIndex(int);
};

class Gambler{
public:
    int Id;
    int status; // status == 1 means he is alive or status == 0
    Revolver revolver;
    Gambler();
    void RollMagazine();
    bool PullTrigger();
    void AddBullet();
};

// I have an idea that player can give the number of gambler to attend Roulette, then after each round programme will count the survivors.
class Roulette : public Game {
public:
    int gamblerNum = 0;
    int Round = 1;
    Gambler *gambler;
    void SetGamblerNum(int);
    void play() override;
};