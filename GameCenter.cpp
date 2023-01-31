//
// Created by Changzy on 2023/1/24.
//
#include "Coin.h"
#include "Dice.h"
#include "Roulette.h"
#include "iostream"

using namespace std;


int main() {
    while(true){
        int type;
        cout << "Which game do you want to play?(give the number)" << endl;
        cout << "1.Tossing coins." << endl;
        cout << "2.Rolling dices." << endl;
        cout << "3.Roulette." << endl;
        cout << ">";
        cin >> type;
        switch (type) {
            case 1:{
                Coin coin;
                coin.play();
                break;
            }
            case 2: {
                Dice dice;
                dice.play();
                break;
            }
            case 3:{
                Roulette roulette;
                roulette.play();
                break;
            }
            default:
                cout <<"Please enter a right number!" << endl;
        }
        cout  << "Do you want to choose game again?(Y/N)"<< endl;
        cout << ">" ;
        char c;
        cin >> c;
        if(c == 'Y') break;
    }

}