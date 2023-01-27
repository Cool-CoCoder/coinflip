//
// Created by Changzy on 2023/1/24.
//
#include "iostream"
#include "stdlib.h"
using namespace std;

int random_memory = -1;

class Coin {
    int side; // 1 is positive, 0 is negative
public:
    static int seed; // 种子要static

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
        cout << "How many coins do you want to toss:(do not enter a number over 2 million)" << endl;
        cin >> n;
        Coin coin[n];
        int count_pos = 0, count_neg = 0;
        for (int i = 0; i < n; ++i) {
            if (coin[i].getSide() == 0) {
                cout << 0 << "\t";
                count_neg++;
            } else {
                cout << 1 << "\t";
                count_pos++;
            }
            if((i+1)%9 == 0){
                cout <<endl;
            }
        }
        cout << endl;
        cout << "The total positive number is:" << count_pos << endl;
        cout << "The total negative number is:" << count_neg << endl;
        float prob_pos = (float) count_pos / n;
        cout << "The probability of positive is:" << prob_pos << endl;
        cout << "Do you want to paly again?(Y/N)" << endl;
        char respond;
        cin >> respond;
        if (respond == 'N') break;
    }


}
