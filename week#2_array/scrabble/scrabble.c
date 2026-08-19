
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// added new library in header secrtion
int POINTS [26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
// points assigned to each letter from A to Z according to given data

int calculate_score (string word); 

int main (void)
{
    // taking the words from both players
   string player_1 = get_string ("Player_1 :");
   string player_2 = get_string ("Player_2 :");
   
   //calculating the score of words of both players 
   int score_1 = calculate_score (player_1);
   int score_2 = calculate_score (player_2);

   //comparing results to find winner
   if (score_1 > score_2)
   {
      printf ("Player 1 wins\n");
   }
   else if (score_2 > score_1)
   {
      printf ("player 2 wins\n");
   }

   //printing "tie" if both scores are same or equal
   if (score_1 == score_2)
   {
      printf ("Tie !");
   }
}

int calculate_score (string word)
{
   int score = 0;

   //checking each letter of word 
   for (int i = 0; strlen(word) > i; i++)
   {
      // if the letter is uppercase, then convert A to Z into 0 to 25
      if (isupper(word[i]))
      {
         score += POINTS[word[i] - 'A'];
      }
      // if the letter is lowercase, then convert a to z into 0 to 25
      else if (islower(word[i]))
      {
         score += POINTS[word[i] - 'a'];
      }
   }

   return score; // the program ends here and gives the value of score
}
