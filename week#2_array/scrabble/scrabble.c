
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int POINTS [26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int calculate_score (string word);

int main (void)
{
   string player_1 = get_string ("Player_1 :");
   string player_2 = get_string ("Player_2 :");

   int score_1 = calculate_score (player_1);
   int score_2 = calculate_score (player_2);

   if (score_1 > score_2)
   {
      printf ("Player 1 wins\n");
   }
   else if (score_2 > score_1)
   {
      printf ("player 2 wins\n");
   }
   if (score_1 == score_2)
   {
      printf ("Tie !");
   }
}

int calculate_score (string word)
{
   int score = 0;


   for (int i = 0; strlen(word) > i; i++)
   {
      if (isupper(word[i]))
      {
         score += POINTS[word[i] - 'A'];
      }
      else if (islower(word[i]))
      {
         score += POINTS[word[i] - 'a'];
      }
   }

   return score;
}
