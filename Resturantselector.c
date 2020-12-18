#define _CRT_SECURE_NO_WARNINGS //get rid of the scanf_s warning in VScommunity2019
                              
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     
#include <ctype.h>
#include <time.h>

typedef struct {            //struct to store restuarnt name and cost 
    char name[32];
    int cost;
} EATERY;

void randomFood(char* selection);       // functions to slect random places, also included a string uppercase function for my struct and a wait function for readability
void customEatery();
void wait(int numseconds);
void checkstring(char* name, int holder);

int main() {
    srand(time(0));     //defualt values in a static array
    char foodTypes[12][12] = { "Mexican", "Chinese", "Thai", "Southwest", "WestIndian", "Irish", "Fastfood", "BBQ", "Creole", "Carribian", "Japanese", "Korean" };
    while (1) {
        char input = '\0';
        printf("Welcome to the Random Resturant slector!\nPlanning on going out, but not sure where to go, worry no more!\n\n[C]hoose a theme of food for me!\n[L]et me pick some resturants!\n[E]xit the program.\n");  // menu print followed by switch selection
        input = getchar();
        getchar();
        switch (input) {
        case 'C':
        case 'c':
            randomFood(&foodTypes);
            break;
        case 'L':
        case 'l':
            customEatery();
            break;
        case 'E':
        case 'e':
            printf("Goodbye!");
            wait(2);
            return 0;
            break;
        default:
            printf("Please enter a valid option\n");
            break;
        }
    }
}
void randomFood(char selection[12][12]) {       //this function selects from a pre set array of food choices. it doesnt have dynamic memory allocation, but It made the program more useful 
    int sizeOfSele = 12, holder = 0;
    int input = 13;
    printf("Your options are:\n");
        for (int i = 0; i < sizeOfSele; i++) {
           printf("\n %i ", i + 1);
           for (int j = 0; j < 12; j++) {
               printf("%c", selection[i][j]);
           }
       }
       printf("\n\nPress enter and we will randomly select one for you!\n");
       getchar();
       int random = rand() % sizeOfSele + 1;
       printf("Looks like you guys are going to have %s\n\n", selection[random]);  //random decission statment
       wait(2);

}
void customEatery() {       //this is where you enter places youre trying to decide on and select randomly.
    EATERY* dynamicEatery;
    int holder, input;
    printf("How many resturants would you like to pick from?\nEnter a number between 2 and 9\n");  //less than 2 isnt a decission and more than 9 is rediculous 
    input = getchar() - 48;
    getchar();
    dynamicEatery = calloc(input, sizeof(EATERY));      //allocates and clears the array for EATERY
    if (dynamicEatery == NULL) {
        printf("There was an allocation critical error. exiting program\n");        //error if youre unable to allocate off the heap
        exit(-1);
    }
    for (int i = 0; i < input; i++) {
        printf("Please enter the name of Resturant %i\n", i + 1);
        scanf("%[^\n]%*c", dynamicEatery[i].name);
        checkstring(&dynamicEatery[i].name, strlen(dynamicEatery[i].name));     //this pushes it to sentence case
        printf("Please enter how many $ this Resturant is. (enter between 1 - 4)\n");
        dynamicEatery[i].cost = getchar() - 48;
        getchar();
    }
    printf("Press any key to select a random restaurant\n");
    int random = rand() % input + 1;
    printf("\n\n\nLooks like you're going to %s and you'll spend ", dynamicEatery[random].name);
    for (int i = 0; i < dynamicEatery[random].cost; i++) {
        printf("$");
    }
    printf("\n press enter to continue...");
    getchar();
    free(dynamicEatery);
}
void wait(int numseconds) {
    int mseconds = 1000 * numseconds;       //since I already had the time library, I added this function to improve readability and not corwd the screen
    clock_t startT = clock();
    while (clock() < startT + mseconds);
}
void checkstring(char* name, int holder) {          //Takes strlen and input structEATERY name and places it in sentence case, it makes it pretty.
    if ((int)name[0] >= 97 && (int)name[0] < 123) {
        name[0] = toupper(name[0]);
    }
    for (int i = 1; i < holder; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
        else {
            name[i] = tolower(name[i]);
        }
    }
}