#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NICKEL 5
#define DIME 10
#define QUARTER 25
#define n NICKEL
#define N NICKEL
#define d DIME
#define D DIME
#define q QUARTER
#define Q QUARTER
void
machine(int coins,int price){
switch(coins){
	case NICKEL:
		coins=coins+NICKEL;

	case DIME:
		coins=coins+DIME;

	case QUARTER:
		coins=coins+QUARTER;
}
printf("You have inserted a total of %d cents",coins);

if (coins<price){
    printf("Please insert %d more cents",price-coins);
}
if (coins > price){
    printf("Pop is dispensed. Thank you for your business! Please come again.");
    return true;
}
return false;
}

void
change(int coins,int price){
int change=price-coins;
int dimes=floor(change/DIME);
int temp=dimes*DIME;
int nickels=floor((change-temp)/NICKEL);
if (change <= 0){
	exit(0);
}
printf("Change given: %d cents as %d dime(s) and %d nickel(s).\n",change,dimes,nickels);
}

void
main(int argc, char *argv[]){
if (argc<=1){
	printf("Please specify selling price as command line argument.\n");
	printf("Usage: pop [price]\n");
	exit(0);
}
int price=atoi(argv[1]);
int coins=0;

if (price <30 | price > 105){
	printf("Price must be from 30 to 105 cents inclusive\n");
	exit(0);
}
if (price%5!=0){
	printf("Price must be a multiple of 5.\n");
	exit(0);
}
printf("Welcome to my C Pop Machine!\n");
printf("\nPop is %d cents. Please insert any combination of ",price);
printf("nickels [N or n], dimes [D or d] or quarters [Q or q]. ");
printf("You can also press R or r for coin return.\n");

while(coins<price){
	printf("\nEnter coin (NDQR): \n");
	machine(coins,price);
}
printf("Pop is dispensed. Thank you for your business! Please come again.");
}
