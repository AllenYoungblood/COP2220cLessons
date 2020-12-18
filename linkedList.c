#define _CRT_SECURE_NO_WARNINGS //get rid of the scanf_s warning in VScommunity2019
                               
#include <stdlib.h>
#include <string.h>    
#include <ctype.h>
#include <time.h>

typedef struct {            //struct to store spacemen name age and weight in KG
    char name[100];
    int age;
    float weight;
} SPACEMAN;

typedef struct NODE {       //node  that holdsaspaceman and points to the next spacemans node
    SPACEMAN person;
    struct NODE* next;
}NODE;

SPACEMAN newSpaceMan();                     
void bubbleSort(NODE* start);
void swap(NODE* a, NODE* b);
void push(NODE** headptr, SPACEMAN newSpaceman);
void returnList(NODE* list);
void wait(int numseconds);
void checkstring(char* name, int holder);

int main() {
    srand(time(0));     //used for the wait function
    NODE* head = NULL;
    while (1) {
        char input = '\0';  
        printf("SPACESHIP CREW MANIFEST:\nPleaseslect a menu option...\n\n   [A]dd A Record.\n   [D]isplay All Records\n   [Q]uit\n\n");  // menu print followed by switch selection
        input = getchar();
        getchar();
        switch (input) {
        case 'A':
        case 'a':
            push(&head, newSpaceMan());
            bubbleSort(head);
            break;
        case 'D':
        case 'd':
            returnList(head);
            break;
        case 'Q':
        case 'q':
            printf("See ya spacecowboy!");
            wait(2);
            return 0;
            break;
        default:
            printf("Please enter a valid option\n");
            break;
        }
    }
}
SPACEMAN newSpaceMan() {
    SPACEMAN newspaceman;
    char name[100];
    printf("Please enter a record\n Name:");
    scanf("%[^\n]%*c", name);
    int holder = strlen(name);
    checkstring(&name, holder);         //places in sentnece case to correctly sort
    strcpy(newspaceman.name, name);              //copy sentence cased name to 
    printf("%s \nWhat is their age?\n", newspaceman.name);
    scanf(" %i", &newspaceman.age);
    printf("%i \nPlease enter their weight in KG\n", newspaceman.age);      //verifys input every time
    scanf(" %f", &newspaceman.weight);
    printf(" %.1lf ", newspaceman.weight);
    getchar();              //added this because it had a floating char messing up the menu
    return newspaceman;
}
void push(NODE** headptr, SPACEMAN newSpaceman) {           //this pushes a spaceman to the front of the heap in a new node
    NODE* new = (NODE*)malloc(sizeof(NODE));            //check out this dynamically allocated memory
    new->person = newSpaceman;
    new->next = *headptr;
    *headptr = new;
}
void returnList(NODE* list) {           //prints list formatted with spaces
    while (list != NULL) {
        printf("Name: %s \n", &list->person.name);
        printf("Age: %i \n", list->person.age);
        printf("Weight:  %.2lf \n\n\n", list->person.weight);
        list = list->next;              //moves pointer to next node to start print
    }
}
void bubbleSort (NODE* start) {             // sorts nodes by switching place
    int switched, i;
    NODE* firstPointer;
    NODE* lastPointer = NULL;
    if (start == NULL)          //will not exicute if head == null
        return;
    do {                            //executes once to determine if switched each time
        switched = 0;
        firstPointer = start;
        while (firstPointer->next != lastPointer)
        {
            if (firstPointer->person.name[0] > firstPointer->next->person.name[0])          //compares first char to decideon swap
            {
                swap(firstPointer, firstPointer->next);
                switched = 1;
            }
            firstPointer = firstPointer->next;
        }
        lastPointer = firstPointer;
    } while (switched);
}
void swap(NODE* a, NODE* b) {           //simple swap person inside node node
    SPACEMAN temp = a->person;
    a->person = b->person;
    b->person = temp;
}
void wait(int numseconds) {
    int mseconds = 1000 * numseconds;       //since I already had the time library, I added this function to improve readability
    clock_t startT = clock();
    while (clock() < startT + mseconds);
}
void checkstring(char* name, int holder) {          //Takes strlen and input structSPACEMAN name and places it in sentence case, it makes it pretty.
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