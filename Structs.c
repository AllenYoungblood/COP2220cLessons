#define _CRT_SECURE_NO_WARNINGS //get rid of the scanf_s warning in VScommunity2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {        //structure to store date variables
    int month;
    int day;
    int year;
} DATE;

typedef struct {         //structure to store person variables
    char name[128];
    DATE birthdate;
    char gender;
    float annualIncome;
} PERSON;

void checkstring(char*, int);           
DATE checkdate();
char getgender();
float getincome();

int main(void) {
    PERSON one[3];          //sets an array of PERSON
    int error = 0, tempDate = -1;
    for (int i = 0; i < 3; i++) {           //for loop to collect person date incremention person each time
        char name[32] = { '\0' };
        printf("Enter persons info\n Name:");
        scanf("%[^\n]%*c", name);
        int holder = strlen(name);          //passing name by refrence to fix local string
        checkstring(&name, holder);
        strcpy(one[i].name, name);
        printf("\nyou entered %s\n\n", one[i].name);
        one[i].birthdate = checkdate();
        one[i].gender = getgender();
        printf("Your gender is %c\n\n", one[i].gender);
        one[i].annualIncome = getincome();
        printf("You entered %.2lf\n\n", one[i].annualIncome);
    }
    for (int i = 0; i < 3; i++) {                           //this parts prints all three people with all the data
        printf("Person %i's information is:\n", i);
        printf("Name:%s\n", one[i].name);
        printf("The birthdate is %02i : %02i : %4i\n", one[i].birthdate.month, one[i].birthdate.day, one[i].birthdate.year);
        printf("The gender is : %c\n", one[i].gender);
        printf("Their income is: $ %.2lf\n\n\n", one[i].annualIncome);
    }
    printf("press any key to exit...");
    getchar();
    return 0;
}
void checkstring(char *name, int holder) {          //Takes strlen and refrence to name in main and places it in sentence case
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
DATE checkdate() {
    int tempDate, error = -1;       //this function is long, and i debated about breaking this down into smaller functions, but decided it would be overkill
    DATE birthdate;
    do {
        printf("please enter the month of birth using two digets for the month\n");
        scanf(" %i", &tempDate);
        getchar();
        if (tempDate < 0 || tempDate > 12) {
            printf("please enter a valid month");
            error = 1;
        }
        else {
            birthdate.month = tempDate;
            error = 0;
        }
    } while (error == 1);
    do {
        printf("please enter the day of birth using two digets for the day\n");
        scanf(" %i", &tempDate);
        getchar();
        if (tempDate < 0) {
            printf("please enter a date above 0\n");
        }
        else if ((birthdate.month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && tempDate > 31) {         //check day refrencing month
            printf("There are only 31 days in the %i month. please try again\n", birthdate.month);
            error = 1;
        }
        else if ((birthdate.month == 4 || 6 || 9 || 11) && tempDate > 30) {
            printf("There are only 30 days in the %i month. please try again\n", birthdate.month);
            error = 1;
        }
        else if (birthdate.month == 4 && tempDate > 29) {           //this was a hard choice, I wanted to ask in order MM/DD/YYYY so i couldnt prevent a user from inputting 29 on a leap year
            printf("There are only 28 days in the 4 month unlkess its a leap year. please try again\n"); // i decided to warn the in the year section instead
            error = 1;
        }
        else {
            birthdate.day = tempDate;
            error = 0;
        }
    } while (error == 1);
    do {
        printf("please enter the year of birth using four digets for the year\n");
        scanf(" %i", &tempDate);
        getchar();
        if (tempDate < 1800 || tempDate > 2021) {
            printf("please enter a valid year, no time travelers allowed\n");
            error = 1;
        }
        else if ((tempDate % 4) != 0 && birthdate.day == 29 && birthdate.month == 2) {
            printf("please enter a leap year since you selected Febuary 29th\n");
            error = 1;
        }
        else {
            birthdate.year = tempDate;
            error = 0;
        }
    } while (error == 1);
    printf("the birthdate you entered is %02i : %02i : %4i\n\n", birthdate.month, birthdate.day, birthdate.year);
    return birthdate;
}
char getgender() {
    char gender = '\0';
    do {
        char input = '\0';
        printf("please enter a gender [M]ale, [F]emale, [O]ther\n");   
        input = getchar();                      // i ask for a var here
        getchar();
        switch (input) {
        case 'M':
        case 'm': 
            gender = 'M';           //and assign it M,F,O depending on what is selected
            break; 
        case 'F':
        case 'f':
            gender = 'F';
            break;
        case 'O':
        case 'o':
            gender = 'O';
            break;
        default:
            printf("Please enter a valid option\n");        // i have a defualt case here
            break;
        }
        if (gender == 'M' || 'F' || 'O') {      //this ALWAYS exits even when gender != M,F, or O
            return gender;                      //will need to be fixed
        }
    } while (gender == 'M' || 'F' || 'O'); //but for some reason this exit condition doesnt work when gender == M or F or O
    return gender;                          // so i added the if statment, but even that doesnt work as expected
}
float getincome() {
    float income = -1; 
    while (income == -1) {
        printf("How much does this person make per year. \nplease enter a number between $0 and $1,000,000\n");
        scanf("%f", &income);
        getchar();
        if (income < 0 || income > 1000000) {
            printf("please enter a valid income\n");        
            income = -1;
        }
    }
    return income;
}