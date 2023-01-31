//
// Created by program_machine on 2023/1/30.
//

#pragma once

#include "Game.h"
class Dice : public Game{
public:
    int side;
    Dice();
    void play() override;
};
