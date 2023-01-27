//
// Created by Changzy on 2023/1/24.
//
#include "iostream"
#include "stdlib.h"
using namespace std;

int random_memory = -1;

class Coin {
    int side; // 1 represent head, 0 represent tail
public:
    static int seed; // the seed need to be static

    int getSide() const {
        return side;
    }

    void setSide(int side) {
        Coin::side = side;
    }

    Coin(int side) { this->side = side; }

    Coin() {
        setSide(toss());
    }

    int toss() {
        ::srand(seed);
        int temp = rand();
        seed = temp;
        if (temp % 2 == 1) {
            return 1;
        }
        return 0;
    }
};


int Coin::seed = (long)&random_memory;

int main() {
    while (true) {
        int n;
        cout << "How many coins do you want to toss:(no more than INT_MAX)" << endl;
        cin >> n;
        int count_pos = 0, count_neg = 0;
        for (int i = 0; i <= n; ++i) {
            Coin *coin = new Coin();
            if(coin->getSide() == 1){
                count_pos ++;
            } else {
                count_neg ++;
            }
            delete coin;

        }

        cout << endl;
        cout << "The total head times is:" << count_pos << endl;
        cout << "The total tail times is:" << count_neg << endl;
        float prob_pos = (float) count_pos / n;
        cout << "The probability of head is:" << prob_pos << endl;
        cout << "Do you want to paly again?(Y/N)" << endl;
        char respond;
        cin >> respond;
        if (respond == 'N') break;
    }


}
