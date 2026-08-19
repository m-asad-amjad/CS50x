#include <stdio.h>
#include <cs50.h>
//including libries

//initialized main section
int main(void)
{
    int n; //intialized a variable n that takes different wlues under the loop
    do //asking to take vaolue n by a variable named "height" from the user
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); // until value of "n" is between 0 and 8

    for (int i = 0; i < n; i++) // this loop is for taking height 
    {
        for (int j = 0; j < n - i - 1; j++) /* this loop is for making all the hashes left 
        aligned by printing spapces suitable times and making the value of always less than the
        the previous one*/
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) //this loop is to take lenghth of each row and printing # sign
        {
            printf("#");
        }
        printf("\n"); //this is to make next rox on next line 
    }
}