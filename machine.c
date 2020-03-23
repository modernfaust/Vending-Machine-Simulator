#include <stdio.h>
#include <machine.h>
//THIS FUNCTION SIMULATES THE COIN AND DISPENSOR MECHANISMS. DOES NOT SIMULATE THE DISTRIBUTION OF CHANGE
void
machine(int coins,int price)
{
switch(coins)
{
case NICKEL:
        coins=coins+NICKEL;

case DIME:
        coins=coins+DIME;

case QUARTER:
        coins=coins+QUARTER;
}
printf("You have inserted a total of %d cents",coins)
if (coins<price)
{
        printf("Please insert %d more cents",price-coins);
}
if (coins > price)
{
        printf("Pop is dispensed. Thank you for your business! Please come again.");
        return true;
}
return false;
}

