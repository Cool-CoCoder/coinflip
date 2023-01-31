//
// Created by Changzy on 2023/1/30.
//
#include "Coin.h"
#include "iostream"
#include "stdlib.h"
using namespace std;


// 1 represent head, 0 represent tail
Coin::Coin() {
    side = RandomManage(0,1);
}

void Coin::play() {
    while (true) {
    int n;
    cout << "How many coins do you want to toss:(no more than INT_MAX)" << endl;
    cout << ">";
    cin >> n;
    int count_head = 0, count_tail = 0;
    for (int i = 0; i <= n; ++i) {
    Coin *coin = new Coin();
    if(coin->side == 1){
    count_head ++;
    } else {
    count_tail ++;
    }
    delete coin;

    }
    cout << endl;
    cout << "The number of times when the coin is head is:" << count_head << endl;
    cout << "The number of times when the coin is tail is:" << count_tail << endl;
    float prob_pos = (float) count_head /(float ) n;
    cout << "The ratio of head is:" << prob_pos << endl;
    cout << "Do you want to play again?(Y/N)" << endl;
    char respond;
    cin >> respond;
    if (respond == 'N') break;
    }
}

