#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NICKEL 5
#define DIME 10
#define QUARTER 25

void
change(int coins){

        int dimes = floor(coins/DIME);
        int temp = dimes*DIME;
        int nickels = floor((coins-temp)/NICKEL);

        printf("Change given: %d cents as %d dime(s) and %d nickel(s).\n",coins,dimes,nickels);

}

// The change(int coins) function counts the dimes and nickels in the change and prints the change in dimes and nickels, in the least amount of coins.
// dimes is the number of ten cent coins that fit into the coins given to the function
// temp is the total amount of money in dimes in the coins provided
// nickels finds how many nickels fit into the coins provided



int
machine(char choice,int *coins,int price){

        if (choice == 'd' | choice == 'D'){

                printf("  Dime detected.\n");
                *coins=*coins+DIME;

        }

        else if (choice == 'n' | choice == 'N'){

                printf("  Nickel detected.\n");
                *coins=*coins+NICKEL;

        }

        else if (choice == 'q' | choice == 'Q'){

                printf("  Quarter detected.\n");
                *coins=*coins+QUARTER;

        }

        else {

                printf("  Unknown coin rejected.\n");

        }

        printf("    You have inserted a total of %d cents.\n", *coins);


        if (*coins < price){

                printf("    Please insert %d more cents.\n",price-*coins);

        }


        if (*coins >=  price){

                printf("     Pop is dispensed. Thank you for your business! Please come again.\n");
                return 1;

        }

        return 0;
}


// The machine(char choice, int *coins, int price) function accepts the user's coin, how much money has been inserted so far and the price of pop
// If the user inserts a dime, there is an alert that a dime has been detected and ten cents is added to the total money.
// This is also the case for nickels and quarters.
// If the user inserts an unknown coin, it is rejected and there is an alert.
// A total is then printed
// If the user has not paid enough, they are told how much they still owe
// If the user has paid enough or has overpaid, a pop is dispensed.  




void
main(int argc, char *argv[]){

        if (argc <= 1) {

                printf("Please specify selling price as command line argument.\n");
                printf("Usage: pop [price]\n");
                exit(0);

        }

        int price = atoi(argv[1]);
        char choice;

        if (price  < 30 || price > 105) {

                printf("Price must be from 30 to 105 cents inclusive\n");

        }

        if (price%5 != 0) {

                printf("Price must be a multiple of 5.\n");

		}

        if ((price%5 == 0) && (price >= 30) && (price <= 105) ) {

                printf("Welcome to my C Pop Machine!\n");


                while (choice != 'e' | choice != 'E'){

                        int to_return;
                        int done = 0;
                        int coins = 0;

                        printf("\nPop is %d cents. Please insert any combination of ",price);
                        printf("nickels [N or n], dimes [D or d] or quarters [Q or q]. ");
                        printf("You can also press R or r for coin return.\n");

                        while(done == 0){

                                printf("\nEnter coin (NDQR):");
                                scanf(" %c",&choice);

                                if (choice == 'e' | choice == 'E'){

                                        to_return = coins;
                                        change(to_return);
                                        printf("Shutting down. Goodbye.\n");
                                        exit(0);

                                }

                                else if (choice == 'r' | choice == 'R'){

                                        to_return = coins;
                                        done = 1;

                                }

                                else {

                                        done = machine(choice,&coins,price);
                                        to_return = coins-price;

                                }

                        }

                change(to_return);
        }
}

}

// The main function reads from the command line and accepts the number of items inputted (argc)  and an array of all the inputs (argv[]).
// If the user has not inputted a price in the command line, there is an alert and the program dies.
// The same thing happens if the price is not within the range or the price is not a multiple of five.
// If the price is legal, there is a printed greeting. 
// While the user has not previously entered 'e' or 'E', the number of coins is set to zero and the user is told the price and which coins they can insert.
// The user is told they can press 'r' or 'R' for a refund.
// If the user has not previously requested a refund while paying for their current pop, they are prompted for a coin and the main function accepts their input.
// If the user presses 'e' or 'E', their money is refunded and the program dies.
// If the user presses 'r' or 'R', their money is refunded and they are re-prompted to enter a coin.
// If the user enters something else, their coin, how much money they have inserted so far and the price of pop are sent to the machine function above.

