//
// Created by program_machine on 2023/1/30.
//

#pragma once
#include "Roulette.h"
#include "iostream"

using namespace std;


Revolver::Revolver() {
    bulletNum = 0;
    for (int i = 0; i < 6; ++i) {
        magazine[i] = 0;
    }
    index = 0;
    addIndex = 0;
}

// it will add to
bool Revolver::AddBullet() {
    if (bulletNum == 5) { // We don't allow fill all the slot
        return false;
    }
    magazine[addIndex] = 1;
    addIndex++;
    addIndex %= 6;
    bulletNum++;
    return true;
}

// It will return 1 or 0, 1 means the gun shoot a bullet so one man will die
bool Revolver::Shoot() {
    if (magazine[index] == 1) {
        magazine[index] = 0;
        index++;
        index %= 6;
        bulletNum--;
        return true;
    }
    index++;
    index %= 6;
    return false;
}

void Revolver::setIndex(int x) {
    index = x;
}


Gambler::Gambler() {
    status = 1;
}

void Gambler::RollMagazine() {

    revolver.setIndex(RandomManage(0, 5));
}

    bool Gambler::PullTrigger() {
        return revolver.Shoot();
    }

void Gambler::AddBullet() {
        revolver.AddBullet();
    }




void Roulette::SetGamblerNum(int x) {
    gamblerNum = x;
    gambler = new Gambler[gamblerNum];
}

void Roulette::play() {
    cout << "Enter the number of gamblers:" << endl;
    cout << ">";
    cin >> gamblerNum;

    SetGamblerNum(gamblerNum);
    for (int i = 0; i < gamblerNum; ++i) { // 给每个gambler一个id
        gambler[i].Id = i;
    }

    while (true) {
        cout << "Round:";
        cout << Round << endl;
        for (int i = 0; i < gamblerNum; ++i) { // 一轮游戏
            bool tempt = false;
            gambler[i].AddBullet();
            gambler[i].RollMagazine();
            tempt = gambler[i].PullTrigger();
            if (tempt) {
                gambler[(i + 1) % gamblerNum].status = 0;
                ++i;
            }
        }
        cout << "存活的人有：\n";
        int count = 0;
        for (int i = 0; i < gamblerNum; ++i) {
            if (gambler[i].status == 1) {
                count++;
                cout << gambler[i].Id << "号" << endl;
            }
        }
        Round++;
        if (count < 2) break;
    }
}


