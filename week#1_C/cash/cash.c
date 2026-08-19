#include <stdio.h>
#include <cs50.h>
//included libraries

int main(void)
{
    int change;// initaialized a variable to store the amount to be changed
    do
    {
        change = get_int("Change owed :"); //the amount to be changed is taken from user by get_string
    }
    while (change < 0); //it will keep giving change until amount to be changed becomes zero
    int coin_count = 0;// this variable will keep count of coins

    while (change >= 25) /* this section will state that when the amount to be changed is greater than 25 
    then firstly lessen the amount to be chnaged by 25 and increase coin_count by one*/
    {
        change = change - 25;
        coin_count = coin_count + 1;
        // we can also write coin_count++
    }
    while (change >= 10) // the same thing for 10 as behaved for 25
    {
        change = change - 10;
        coin_count++;
    }
    while (change >= 5) // same thing for 5
    {
        change = change - 5;
        coin_count++;
    }
    while (change >= 1)// same thing for 1
    {
        change = change - 1;
        coin_count++;
    }
    printf("%i\n", coin_count); // at the last this will be our final output this will print the total number of coins used to make the change

}
