# include <stdio.h>
# include <cs50.h>
//included libraries

//started header section
int main ()
{
    string name = get_string("What is your name? ");//taking a string named as "name" from the user
    printf("Hello, %s\n", name);//using format specifier to print the name of user taken in the string called "name"
    return 0;//program ended successfully
}