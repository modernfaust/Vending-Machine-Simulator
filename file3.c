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

	int testPrice = atoi(argv[1]);
	if ((testPrice%5) !=  0){
		printf("Please choose a price that is a multiple of five. Thank you!\n");
	}
	if (testPrice < 30 || testPrice > 105){
		printf("Please choose a price that is more than 30 cents and less than $1.05. Thank you!\n");
	}



	else {
		int price = atoi(argv[1]);
		int coins = 0;
		bool done = 0;
		char coinEntered = 'x';

		printf("Welcome to C Pop Machine!\n\n");
		printf("Pop is %d cents. Please insert any combination of nickels [N or n] or dimes [D or d] or quarters [Q or q]\n\n",price);
		printf("You can enter R or r to abort transaction and recieve a refund\n\n");

		
		while (coins < price) {
                        printf("Enter coin (NDQR):");
                        scanf("%s",&coinEntered);
			
			if ( (coinEntered == 'n') || (coinEntered == 'N') ){
				coins = coins + NICKEL;
				printf("Nickel detected.\nYou have entered %d cents.\nPlease enter %d cents to recieve pop.\nThank you!\n\n", coins, price-coins);
				if (coins >= price){
					done = 1;
 				}
			}

			if ( (coinEntered == 'd') || (coinEntered == 'D') ){
				coins = coins + DIME;
				printf("Dime detected.\nYou have entered %d cents.\nPlease enter %d cents to recieve pop.\nThank you!\n\n",coins,price-coins);
				if (coins >= price){
                                        done = 1;
                                }
			}

			if ( (coinEntered == 'q') || (coinEntered == 'Q') ) {
				coins = coins + QUARTER;
				printf("Quarter detected.\nYou have entered %d cents.\nPlease enter %d cents to recieve pop.\nThank you!\n\n",coins,price-coins);
				 if (coins >= price){
                                        done = 1;
                                 }
			}
			if ( (coinEntered == 'r') || (coinEntered == 'R') ){
				
			}

		}


		if (done == 1) {
			printf("Pop dispensing. Thank you for your business! Good bye!\n\n");
		}

       }
	
}



