#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed :");
    }
    while (change < 0);
    int coin_count = 0;

    while (change >= 25)
    {
        change = change - 25;
        coin_count = coin_count + 1;
        // we can also write coin_count++
    }
    while (change >= 10)
    {
        change = change - 10;
        coin_count++;
    }
    while (change >= 5)
    {
        change = change - 5;
        coin_count++;
    }
    while (change >= 1)
    {
        change = change - 1;
        coin_count++;
    }
    printf("%i\n", coin_count);

}
