//
// Created by program_machine on 2023/1/30.
//
#include "Dice.h"
#include "iostream"
#include "stdlib.h"
using namespace std;

Dice::Dice() {
    // dice has six sides
    side = RandomManage(1, 6);

}

void Dice::play() {
    int count[6] = {0};
    int n;
    while(true){
        cout << "How many dices do you want to roll?(no more than INT_MAX)" << endl;
        cout << ">";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Dice *d = new Dice();
            count[d->side] ++;
            delete d;
        }
        cout << endl;
        for (int i = 0; i < 6; ++i) {
            cout << "The occurrence time of "<< i <<" is "<<count[i];
            cout << ". The ratio is: " << (float) count[i]/(float )n << endl;
        }
        cout << "Do you want to play again?(Y/N)" << endl;
        char respond;
        cin >> respond;
        if (respond == 'N') break;
}
}



