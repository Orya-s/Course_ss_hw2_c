#include <stdio.h>
#include "myBank.h"
#include "myBank.c"

int main() {

    int accessible = 1;
    char command;
    double amount;
    int accNum;

    while (accessible != 0) {
        printf("Please enter the wanted action here (for the list of possible actions please enter 'Z'): ");
        scanf(" %c", &command);

        switch (command) {
            case 'O':
                printf("Please enter deposit amount: ");
                scanf("%lf", &amount);
                if(amount < 0){
                    printf("You can not open an account with a negative balance.\n");
                    break;
                }
                accNum = OpenAccount(amount);
                if (accNum == -1) {
                    printf("There is no more room in the bank to open a new account.\n");
                } else {
                    printf("Your new account number is- %d\n", accNum);
                }
                break;

            case 'B':
                printf("Please enter your account number: ");
                scanf("%d", &accNum);
                amount = balance(accNum);
                if (amount == -1) {
                    printf("Account is closed.\n");
                } else {
                    printf("Your balance is- %.2lf\n", amount);
                }
                break;

            case 'D':
                printf("Please enter your account number: ");
                scanf("%d", &accNum);
                printf("Please enter the requested deposit amount: ");
                scanf("%lf", &amount);
                if(amount < 0){
                    printf("You can not deposit a negative amount.\n");
                    break;
                }
                double newAmount= deposit(accNum, amount);
                if(newAmount == -1){
                    printf("Account is closed.\n");
                }
                else{
                    printf("The current balance is- %.2lf\n", newAmount);
                }
                break;

            case 'W':
                printf("Please enter your account number: ");
                scanf("%d", &accNum);
                printf("Please enter the requested withdrawal amount: ");
                scanf("%lf", &amount);
                if(amount < 0){
                    printf("You can not withdraw a negative amount.\n");
                    break;
                }
                newAmount= withdrawal(accNum,amount);
                if(newAmount == -1){
                    printf("Account is closed.\n");
                }
                else if(newAmount == -2){
                    printf("There is not enough money in the account.\n");
                }
                else{
                    printf("The current balance is- %.2lf\n", newAmount);
                }
                break;

            case 'C':
                printf("Please enter your account number: ");
                scanf("%d", &accNum);
                close(accNum);
                printf("Your account is now closed. \n");
                break;

            case 'I':
                printf("Please enter the wanted interest rate (percentage): ");
                double interestRate;
                scanf("%lf", &interestRate);
                addInterest(interestRate);
                printf("The interest rate has been updated.\n");
                break;

            case 'P':
                printBank();
                break;

            case 'E':
                closeBank();
                printf("The bank has been closed.\n");
                accessible= 0;
                break;

            case 'Z':
                printf("Possible actions: \n O - Open a new account with an initial deposit. \n B - Get balance."
                       " \n D - Deposit. \n W - Withdraw. \n C - Close account. \n I - Add interest. \n P - Print all the"
                       " accounts. \n E - Close all accounts and exit. \n note: account numbers run from: 901- 950\n");
                break;

            default:
                printf("No such option, enter 'Z' for possible actions.\n");
        }
    }

    return 0;
}