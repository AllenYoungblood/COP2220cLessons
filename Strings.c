#define _CRT_SECURE_NO_WARNINGS //get rid of the stupid scanf_s warning in VScommunity2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char string[],int number);				//Allen Youngblood 10/12/2020 COP2220c
void horzontal(char string[], int number);
void pyrimid(char string[], int number);

int main(void) {
	int exit = -1;
	do {
		char string[101] = { 0 };										//100char + NULL '\0'
		char exitswitch = -1;
		int number = 0, exit = -1;
		printf("Please enter a string up to 100 characters. \n");
		scanf("%[^\n]%*c", string);								// get string until enter char
		number = strlen(string);

		printf("The string you entered is:\n%s \n\n", string);	//return string forward
		reverse(string, number);
		horzontal(string, number);
		pyrimid(string, number);
		printf("There are %zu characters in your string \n", strlen(string));  //count characters in string using strlen
		while (exit == -1) {
			printf("would you like to enter another string? \n [Y]es or [N]o\n");
			exitswitch = getchar();
			getchar();
			switch (exitswitch) {
			case 'Y':
			case 'y':
				exit = 0;
				break;
			case 'N':
			case 'n':
				exit = 1;
				break;
			default:
				printf("Please enter a valid option\n");
				exit = -1;
				break;
			}
		}
		if (exit == 1) {
			break;
		}
	} while (exit != 1);
	printf("goodbye");
	return 0;
} 
void reverse(char string[], int number) {
	printf("your string reversed is\n");					//reverse string is self explaining code a thing?
	_strrev(string);
	printf("%s\n\n", string);
	_strrev(string);			//reverse it back
}
void horzontal(char string[], int number) {
	printf("Your string horizontally is\n");
	for (int i = 0; i < number + 1; i++) {					// prints horazontal 
		printf("%c\n", string[i]);
	}
	printf("\n");
}
void pyrimid(char string[], int number) {
	printf("Your string as a pyrimid looks like this:\n");
	for (int i = 0; i < number + 1; i++) {					// prints in a triangle. right triangle to be specific
		int j = 0;
		while (j != i) {
			printf("%c", string[j]);
			j++;
		}
		printf("\n");
	}
	printf("\n");
}