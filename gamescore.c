#define _CRT_SECURE_NO_WARNINGS //get rid of the scanf_s warning in VScommunity2019

#include <stdio.h>         
#include <stdlib.h>

int wLT(int scores[][2], int size);                    //winlosstie, I noticed the variable name was a bit ambiguous
int winsResult(int scores[][2], int size);             

int main(void) {
    char choice;                                            
    int size = 0, holder = 0, scores[100][2] = { 0 };     //size = size of array used, chose not to make array dynamic, holder holds temp values
    while (size != -1) {                                    
        printf("***********************************************\n\n** MAIN   MENU**\n\n***********************************************\n\nA) Enter game result\n\nB) Current Record(# of wins and # of losses and # of ties)\n\nC) Display ALL results from all games WON\n\nD) Display ALL results ordered by opponent score from low to high.\n\nE) Quit\n");
        scanf(" %c", &choice);
        switch ((char)choice) {
        case 'A':
        case 'a':
            // holder = 0;              comment this out to allow to add games after -1 
            while (holder != -1) {
                printf("Please enter the home team score for game. (-1 to exit)\n");       // handles new scores and allows entry until quit switch argument
                scanf(" %i", &holder);
                if (holder != -1) {
                    scores[size][0] = holder;
                    printf("\nWhat was opposing teams score?\n");
                    scanf(" %i", &holder);
                    scores[size][1] = holder;
                    size++;
                    printf("next game scores\n");
                }
            }
            break;
        case 'B':
        case 'b':
            printf("The current record is:\n");
            wLT(scores, size);                      //again, wLT is win loss tie
            break;
        case 'C':
        case 'c':
            winsResult(scores, size);    // games where home team won
            break;
        case 'D':
        case 'd':
            printf("The game results ordered from highest opponent score to lowest opponent score are:\n");
            oppScoreHL(scores, size);               //this one was a doozie, look at the function for comments
            break;
        case 'E':
        case 'e':
            printf("Goodbye\n");    
            size = -1;
            break;
        default:
            printf("please entter a valid menu selection\n");  //user preventitive coding so if it wont take wrong cases
        }
    }
}
int wLT(int scores[][2], int  size) {
    int home = 0, opp = 0, tie = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i][0] == scores[i][1]) {
            tie++;
        } else if (scores[i][0] > scores[i][1]) {     
            home++;
        } else {
            opp++;
        }
    }
    printf("%i home wins\n%i opponent wins\n%i ties\n", home, opp, tie);
    return 0;
}
int winsResult(int scores[][2], int size) {
    for (int i = 0; i < size; i++) {
        if (scores[i][0] > scores[i][1]) {          // if home wins, print game# and results and the loop runs through all games
            int home = scores[i][0];
            int opp = scores[i][1];
            printf("We won game %i with a score of %d - %d\n", (i + 1), home, opp);
        }
    }
    return 0;
}
int oppScoreHL(int scores[][2], int size) {
    int holder[100][2] = { 0 };
    for (int i = 0; i <= size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {                
            if (scores[j][1] > scores[j + 1][1]) {          
                holder[j][0] = scores[j + 1][0];
                holder[j][1] = scores[j + 1][1];            //this is to bubble sort both elements of a bubble array baised on opponent score
                scores[j + 1][0] = scores[j][0];            //im not sure if there is a better way to do this
                scores[j + 1][1] = scores[j][1];            
                scores[j][0] = holder[j][0];                
                scores[j][1] = holder[j][1];                // could always add a 3rd element to the sub array to keep track of game
            }
        }
        
    }
    for (int i = 0; i < size; i++) {
        printf("%i - %i\n", scores[i][0], scores[i][1]);    //prints the sorted array in order
    }
}                                                           