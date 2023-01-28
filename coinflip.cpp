//
// Created by Changzy on 2023/1/24.
//
#include "iostream"
#include "stdlib.h"
using namespace std;

int random_memory = -1;

class Random_Event{
public:
    int side;
    static int seed; // the seed need to be static
    virtual void toss() = 0; // My experiment has shown that 0~9 is uniformly distributed by the operation rand()%10
    virtual void play() = 0;

};

int Random_Event::seed = (long)&random_memory;


// 1 represent head, 0 represent tail
class Coin : public Random_Event{
public:
    Coin() {
        toss();
    }

    void play() override{
        while (true) {
            int n;
            cout << "How many coins do you want to toss:(no more than INT_MAX)" << endl;
            cout << ">";
            cin >> n;
            int count_pos = 0, count_neg = 0;
            for (int i = 0; i <= n; ++i) {
                Coin *coin = new Coin();
                if(coin->side == 1){
                    count_pos ++;
                } else {
                    count_neg ++;
                }
                delete coin;

            }
            cout << endl;
            cout << "The number of times when the coin is head is:" << count_pos << endl;
            cout << "The number of times when the coin is tail is:" << count_neg << endl;
            float prob_pos = (float) count_pos / n;
            cout << "The ratio of head is:" << prob_pos << endl;
            cout << "Do you want to play again?(Y/N)" << endl;
            char respond;
            cin >> respond;
            if (respond == 'N') break;
        }
    }

private:

    void toss() override {
        ::srand(seed);
        int temp = rand();
        seed = temp;
        if (temp % 2 == 1) {
           side = 1;
        } else {
            side = 0;
        }

    }

};

class dice : public Random_Event{
public:
    dice(){
        toss();
    }

    void play() override{
        int count[6] = {0};
        int n;
        while(true){
            cout << "How many dices do you want to roll?(no more than INT_MAX)" << endl;
            cout << ">";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                dice *d = new dice();
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
private:
    // dice has six sides
    void toss() override{
        // 如何让6个不同的事件均匀出现
        ::srand(seed);
        int temp = rand();
        seed = temp;
        while(temp%10 >5){ // we only want 0~5 uniformly come out
            temp = ::rand();
            seed = temp;
        }
        side = temp%10;
    }
};

int main() {
    while(true){
        int type;
        cout << "Which game do you want to play?(give the number)" << endl;
        cout << "1.Tossing coins." << endl;
        cout << "2.Rolling dices." << endl;
        cout << ">";
        cin >> type;
        switch (type) {
            case 1:{
                Coin coin;
                coin.play();
                break;
            }
            case 2: {
                dice dice;
                dice.play();
                break;
            }
            default:
                cout <<"Please enter a right number!" << endl;
        }
    }

}
