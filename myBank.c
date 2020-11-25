#include "myBank.h"
#include <stdio.h>
#define OPEN 1
#define CLOSED -1
#define AccountOne 901

double bank[50][2];

double OpenAccount(double cash){
    for(int i=0; i<50; i++){
        if(bank[i][1] != OPEN){
            bank[i][1]= OPEN;
            bank[i][0]= cash;
            return i+ AccountOne;
        }
    }
    return -1;  //bank is already full
}

double balance(int num){
    if(bank[num- AccountOne][1] == OPEN){
        return bank[num- AccountOne][0];
    }
    return -1; //account is closed
}

double deposit(int num, double cash){
    if(bank[num- AccountOne][1] == OPEN){
        bank[num- AccountOne][0] += cash;
        return bank[num- AccountOne][0];
    }
    return -1; //account is closed
}

double withdrawal(int num, double cash){
    if(bank[num- AccountOne][1] == OPEN){
        if(bank[num- AccountOne][0] >= cash){
            bank[num- AccountOne][0] -= cash;
            return bank[num- AccountOne][0];
        }
        return -2; //not enough money in the account
    }
    return -1; //account is closed
}

double close(int num){
    if(bank[num- AccountOne][1] == OPEN){
        bank[num- AccountOne][1] = CLOSED;
        bank[num- AccountOne][0] = 0;
        return 0; //account has been closed
    }
    return -1; //account was already closed
}

void addInterest(double interest1){
    double interest= (interest1)/100 +1;
    for(int i=0; i<50; i++){
        if(bank[i][1] == OPEN) {
            bank[i][0] = bank[i][0] * interest;
        }
    }
}

void printBank(){
    for(int i=0; i<50; i++){
        if(bank[i][1] == OPEN){
            printf("Account number: %d , Account balance: %.2lf. \n", i+AccountOne, bank[i][0]);
        }
    }
}

void closeBank(){
    for(int i=0; i<50; i++){
        if(bank[i][1] == OPEN){
            bank[i][0]= 0;
            bank[i][1]= CLOSED;
        }
    }

}