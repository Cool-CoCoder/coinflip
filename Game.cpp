//
// Created by program_machine on 2023/1/30.
//
#include "iostream"
#include "stdlib.h"

int random_memory = -1;
long seed = (long)&random_memory;; // global variable
// My experiment has shown that 0~9 is uniformly distributed by the operation rand()%10


// 暂时限制 0-9
int RandomManage(int low,int high){
    srand(seed);
    int temp = rand();

    while (temp % 10 > high || temp %10 < low) {
        temp = ::rand();
    }
    seed = temp;
    return temp%10;
}