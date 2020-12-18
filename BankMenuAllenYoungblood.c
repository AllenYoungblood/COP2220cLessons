#include <stdio.h>         
#include <stdlib.h>

double sumOfAll(double account[], int size);
double highToLow(double account[], int size);             
double averageOfAll(double account[], int size);
double lowestDep(double account[], int size);

int main(void) {
    char x;
    int size = 0;
    double balance = 0;
    double holder = 0;              
    double account[100];
    for (int i = 0; i < 100; i++) {     //sets all values 0-99 to "0"
        account[i] = 0;
    }
    while (1) {                 
        printf("*** BANKING MAIN MENU ***\n\n[M]ake a new deposit\n\n[S]um of all deposits\n\n[D]eposits will be displayed from highest to lowest deposit\n\n[A]verage of all deposits\n\n[L]owest deposit will be displayed\n\n[Q]uit the program\n\n");
        scanf(" %c", &x);
        switch ((char)x) {
        case 'M':
        case 'm':
            printf("Current Balance: %.2f \n", balance);
            printf("please enter an amount you would like to deposit enter '0' to stop making deposits\n\n\n:$");         
            scanf("%lf", &holder);
            while (holder != 0.0) {
                account[size] = holder;
                holder = 0;
                balance += account[size];
                size++;
                printf("Current Balance: %.2f \n", balance);
                printf("\nplease enter an amount you would like to deposit enter - 1 to stop making deposits\n\n\n:$");
                scanf("%lf", &holder);
            }
            break;
        case 'S':
        case 's':
            printf("The sum of all your deposits are:\n");          
            holder = sumOfAll(account, size);
            printf("$ %.2lf \n", holder);
            holder = 0;
            printf("\n\n\n");
            break;
        case 'D':
        case 'd':
            highToLow(account, size);
            break;
        case 'A':
        case 'a':
            holder = averageOfAll(account, size);
            printf("the average of all deposits are: \n $ %.2lf \n\n\n", holder);
            holder = 0;
            break;
        case 'L':
        case 'l':
            holder = lowestDep(account, size);
            printf("your lowest deposit was\n$ %.2lf \n\n\n", holder);
            holder = 0;
            break;
        case 'Q':
        case 'q':
            printf("Goodbye\n");
            return 0;
            break;
        default:
            printf("please entter a valid menu selection\n");  
        }
    }
}
double sumOfAll(double account[], int size) {           //loops to add up and return total of deposits
    double  total = 0.0;
    for (int i = 0; i < size; i++) {
        total += account[i];
    }
    return total;
}
double highToLow(double account[], int size) {      // a for loop in a for loop to iterate and find & print next highest var
    double highest = 10000000;
    double pholder = 0;
    double temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (account[j] > pholder && account[j] < highest) {
                pholder = account[j];
            }
        }
        highest = pholder;
        pholder = 0;
        printf("%.2lf \n", highest);
    }
    return 0;
}
double averageOfAll(double account[], int size) {       //adds elements of array and devides them to find average 
    double average;
    double count = 0;
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += account[i];
        count++;
    }
    average = (total / count);
    return average;
}
double lowestDep(double account[], int size) {          // loops to find lowest element. was going to do if lowest !=0, but wasnt sure if $0 would be a test case
    double lowest = 1000000;
    for (int i = 0; i < size; i++) {
        if (account[i] <= lowest) {
            lowest = account[i];
        }
    }
    return lowest;
}