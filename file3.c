#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NICKEL 5
#define DIME 10
#define QUARTER 25
#define n NICKEL
#define N NICKEL
#define d DIME
#define D DIME
#define q QUARTER
#define Q QUARTER

void main(int argc, char *argv[]) {

	if (argc <= 1 ){
		printf("Please specify selling price\n");
		printf("Usage pop [price]\n ");
	}




	else {
		int price = atoi(argv[1]);
		int coins = 0;
		bool done = 0;
		char coinEntered = 'n';

		printf("Welcome to C Pop Machine!\n\n");
		printf("Pop is %d cents. Please insert any combination of nickels [N or n] or dimes [D or d] or quarters [Q or q]\n\n",price);
		printf("You can enter R or r to abort transaction and recieve a refund\n\n");
		
		while (coins < price) {
			printf("Enter coin (NDQR):  ");
			scanf("%c",&coinEntered); 
			
			if ( (coinEntered == 'n') || (coinEntered == 'N') ){
				coins = coins + NICKEL;
				printf("Nickel detected. You have entered %d cents. Please enter %d cents to recieve pop. Thank you!\n\n", coins, price-coins);
			}

			if ( (coinEntered == 'd') || (coinEntered == 'D') ){
				coins = coins + DIME;
				printf("Dime detected. You have entered %d cents. Please enter %d cents to recieve pop. Thank you!\n\n",coins,price-coins);
			}

			if ( (coinEntered == 'q') || (coinEntered == 'Q') ) {
				coins = coins + QUARTER;
				printf("Quarter detected. You have entered %d cents. Please enter %d cents to recieve pop. Thank you!\n\n",coins,price-coins);
			}
			if ( (coinEntered == 'r') || (coinEntered == 'R') ){
				printf("YOU ARE IN DEEP SHIT");
			}			
			if else {
				printf("Please enter N, D, Q or R\n\n");
			}
		}
		printf("Pop dispensing. Thank you for your business! Good bye!\n\n");

       }




	
}


