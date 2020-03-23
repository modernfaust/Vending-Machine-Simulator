#include<stdio.h>
#include<machine.h>
//THIS INCLUDES THE MAIN FUNCTION, WHICH WILL ACT AS THE MAIN VENDING MACHINE INTERFACE, CALLING ALL THE NECESSARY FUNCTIONS
void
main(int argc, char *argv[])
{
if (argc<=1)
{
  printf("Please specify selling price as command line argument.\n")
  printf("Usage: pop [price]\n");
}

printf("Welcome to my C Pop Machine!\n");
printf("\nPop is %d cents. Please insert any combination of ",price);
printf("nickels [N or n], dimes [D or d] or quarters [Q or q]. ");
printf("You can also press R or r for coin return.\n");

int price = atoi(argv[1]);
int coins = 0;
bool done=false;

while(coins<=price)
{
  printf("\nEnter coin (NDQR): \n");
  machine(coins,price);
}
}
//issues:
// NEED TO FIGURE OUT HOW TO CALCULATE CHANGE
// NEED TO FIGURE OUT HOW TO TAKE IN ONLY THE CORRECT INPUT
// NEED TO FIGURE OUT HOW TO CHECK FOR PRICE MULTIPLE OF 5
// NEED TO FIGURE OUT HOW TO CHECK FOR PROPER PRICE
