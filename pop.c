#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NICKEL 5
#define DIME 10
#define QUARTER 25


void
change(int coins){
int dimes=floor(coins/DIME);
int temp=dimes*DIME;
int nickels=floor((coins-temp)/NICKEL);
printf("Change given: %d cents as %d dime(s) and %d nickel(s).\n",coins,dimes,nickels);
}

int
machine(char choice,int *coins,int price){
if (choice == 'r' | choice == 'R'){
        return 1;
}
else if (choice == 'd' | choice == 'D'){
        printf("%3s\n","Dime detected.");
        *coins=*coins+DIME;
}
else if (choice == 'n' | choice == 'N'){
        printf("%3s\n","Nickel detected.");
        *coins=*coins+NICKEL;
}
else if (choice == 'q' | choice == 'Q'){
        printf("%3s\n","Quarter detected.");
        *coins=*coins+QUARTER;
}
else{
        printf("%3s\n","Unknown coin rejected.");
}

printf("%5s%d%s\n","You have inserted a total of ", *coins," cents");

if (*coins<price){
        printf("%5s%d%s\n","Please insert ",price-*coins," more cents");
}
if (*coins > price){
    printf("%5s\n","Pop is dispensed. Thank you for your business! Please come again.");
        return 1;
}
return 0;
}

void
main(int argc, char *argv[]){
if (argc<=1){
        printf("Please specify selling price as command line argument.\n");
        printf("Usage: pop [price]\n");
        exit(0);
}
int price=atoi(argv[1]);
char choice;

if (price <30 | price > 105){
        printf("Price must be from 30 to 105 cents inclusive\n");
        exit(0);
}
if (price%5!=0){
        printf("Price must be a multiple of 5.\n");
        exit(0);
}
printf("Welcome to my C Pop Machine!\n");

while (choice!='e' | choice !='E'){

        int to_return;
        int done=0;
        int coins=0;

        printf("\nPop is %d cents. Please insert any combination of ",price);
        printf("nickels [N or n], dimes [D or d] or quarters [Q or q]. ");
        printf("You can also press R or r for coin return.\n");

        while(done==0){
                        printf("\nEnter coin (NDQR):");
                        scanf(" %c",&choice);
                        if (choice == 'e' | choice == 'E'){
                        to_return=coins;
                        change(to_return);
                        printf("Shutting down. Goodbye.\n");
 exit(0);
                        }
                        else if (choice == 'r' | choice == 'R'){
                        to_return=coins;
                        done=1;
                        }
                        else {
                        done=machine(choice,&coins,price);
                        to_return = coins-price;
                        }
        }
change(to_return);
}
}
