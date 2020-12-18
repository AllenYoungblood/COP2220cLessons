#define _CRT_SECURE_NO_WARNINGS //get rid of the scanf_s warning in VScommunity2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {        
    char name[32];
    int odds;
    int payout;
} DOG;

typedef struct {            //win loss structure for recording and returning 
    char name[32];
    char winLoss;
    float bet;
    float win;
} RESULT;

void gamble(DOG* selection, RESULT* roundResult);       //function to handle gamble and result assignment 

int main() {
    srand(time(0));
    float balance = 0;
    int gameCount = -1, holder = 0;
    RESULT results[20];
    DOG racer[9] = {
        {"Lucky", 40, 2 },
        {"Santas Little Helper", 10, 5 },           //initlizing dog names
        {"Sparky", 8, 10 },
        {"All Pink", 6, 15 },
        {"Rocket", 1, 50 },
        {"Lightning", 4, 20 },
        {"Flash", 8,10 },
        {"Steady Eddy", 10, 5 },
        {"Booster", 13, 3 },
    };
    while (1) {
        char input = '\0';
        printf("[G]amble\n\n[R]esults of All Races\n\n[L]eave the Dog Track\n\n");  // menu print followed by switch selection
        input = getchar();
        getchar();
        switch (input) {
        case 'G':
        case 'g':
            gameCount++;
            int selection = 0;
            printf("The dogs are...\n\n");      //this lists the dogs
            for (int i = 0; i < 9; i++) {
                printf("Dog %i \nName:%s \n The chance of winning is %i%c\n The payout is %i to 1\n\n", i+1, racer[i].name, racer[i].odds, 37, racer[i].payout);
            }
            do {
                printf("Please select a dog\n");
                holder = getchar();
                getchar();
                holder -= 48;
                selection = holder;
                if (selection < 1 || selection > 9) {           //throws back invalid options
                    printf("\nplease enter a valid option\n");
                } 
            } while (selection < 1 || selection > 9);
            gamble(&racer[selection - 1], &results[gameCount]);
            break;
        case 'R':
        case 'r':
            printf("The Results are:\n");
            for (int i = 0; i < gameCount; i++) {       //this prints the results in each line
                printf("Race %i The dog was %s You %c Your Bet:%.2lf Your Win Amount:%.2lf\n", i, results[i].name, results[i].winLoss, results[i].bet, results[i].win);
            }
            break;
        case 'L':
        case 'l':
            printf("Goodbye!");    
            return 0;
            break;
        default:
            printf("Please enter a valid option\n");        
            break;
        }
        //        if (gender == 'M' || 'F' || 'O') {
        //            return gender;
        //        }
    }
}
void gamble(DOG* selection, RESULT* roundResult) {
    float payout = 0;
    int bet = -1;
    printf("You selected: \n\n");
    printf("Name:%s \n The chance of winning is %i%c\n The payout is %i to 1\n\n", selection->name, selection->odds, 37, selection->payout);
    while (bet == -1) {
        printf("How much would you like to bet?\n enter a number between $ 1 - 10000\n");       //takes bet amount
        scanf("%d", &bet);
        getchar();
        if (bet < 1 || bet > 10000) {
            printf("please enter a valid income\n");
            bet = -1;
        }
        else {
            printf("you entered %.2lf\n\n", bet);       //verifys amount
        }
    }
    strcpy (roundResult->name, selection->name);
    double random = rand() % 100 + 1;
    if (random < selection->odds) {
        printf("you Won\n");
        roundResult->winLoss = 'W';
        printf("you bet %.2f\n", bet);      //assigns values on a win
        roundResult->bet = bet;
        payout = selection->payout * bet;
        printf("you won $ %.2f\n", payout);
        roundResult->win = payout;
    }
    else {
        printf("You lost! sorry \n");       //assigns values on a loss
        roundResult->winLoss = 'L';
        roundResult->bet = bet;
        payout = 0;
        roundResult->win = payout;
    }
    return 0;
}