#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    //taking text from the user
    string text = get_string("Text :");

    //counting each character in the text
    for (int i = 0; strlen(text) > i; i++)
    {
        //counting letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        //counting words by counting spaces
        if (text[i] == ' ')
        {
            words++;
        }
        
        //counting sentences by counting punctuation marks
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    
    //calculating the letters
    float L = (float) letters / words * 100.0;

    //calculating words
    float S = (float) sentences / words * 100.0;

    //calculating the index according to given formuls
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);
    //grade will become rounded off index
    {
        calculating the grade according to the index
        if (grade < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (grade >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", grade);
            //printing the grade
        }
    }
}
