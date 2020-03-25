#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NICKEL 5
#define DIME 10
#define QUARTER 25

int
machine(char choice,int *coins,int price){
if (choice == 'r' | choice == 'R'){
        return 1;
}
else if (choice == 'd' | choice == 'D'){
        *coins=*coins+DIME;
}
else if (choice == 'n' | choice == 'N'){
        *coins=*coins+NICKEL;
}
else if (choice == 'q' | choice == 'Q'){
        *coins=*coins+QUARTER;
}
else{
        printf("Unknown coin rejected.\n");
}

printf("You have inserted a total of %d cents\n",*coins);

if (*coins<price){
    printf("Please insert %d more cents\n",price-*coins);
}
if (*coins >= price){
    printf("Pop is dispensed. Thank you for your business! Please come again.\n");
        return 1;
}
return 0;
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
char choice;
int done=0;

if (price <30 | price > 105){
        printf("Price must be from 30 to 105 cents inclusive\n");
        exit(0);
}
if (price%5!=0){
        printf("Price must be a multiple of 5.\n");
        exit(0);
}
while (choice!='e' | choice !='E'){
printf("Welcome to my C Pop Machine!\n");
printf("\nPop is %d cents. Please insert any combination of ",price);
printf("nickels [N or n], dimes [D or d] or quarters [Q or q]. ");
printf("You can also press R or r for coin return.\n");

while(done==0){
        printf("\nEnter coin (NDQR): ");
        scanf(" %c", &choice);
        if (choice == 'e' | choice == 'E'){
        break;
        }
        done=machine(choice,&coins,price);
}
change(coins,price);
printf("Shutting down. Goodbye.");
}
}
