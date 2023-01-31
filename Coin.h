//
// Created by Changzy on 2023/1/30.
//
#pragma once

#include "Game.h"

class Coin: public Game{
public:
    int side = 0;
    Coin();
    void play() override;
};