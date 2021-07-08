#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words 
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //printf("Score 1: %d\n", score1);
    //printf("Score 2: %d\n", score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
  
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int b = strlen(word);
    int arr_score[b];
    int counter = 0;
    //char new_word[b]; //something is going wrong with this! A segmentation fault is caused by a memory access violation. 
    for (int i = 0; i < b; i++)
        {
            if (isupper(word[i]) != 0)
            {
                //printf("Upper Loop: %c\n", word[i]);
                if ((word[i] > 64) && (word[i] < 123) && (word[i] != 91-96))
                {
                    //printf("%c\n", word[i]);
                    arr_score[i] = word[i] - 65;
                    //new_word[i] = word[i];
                }
               
            }
            else
            {
            //printf("%c", word[i]);
            arr_score[i] = 26;
            }
            printf("\n");
            if (islower(word[i]) != 0)
            {
                if ((word[i] > 64) && (word[i] < 123) && (word[i] != 91-96))
                {
                    //printf("%c\n", word[i]);
                    arr_score[i] = word[i] - 97;
                    //new_word[i] = word[i];
                }
                else
                {
                //printf("%c", word[i]);
                arr_score[i] = 26;
                }
                    
                
            }
            //printf("\n");
        }
    for (int i = 0; i < b; i++)
    {
        printf("arr_score: %d", arr_score[i]);
        printf("\n");
    }
   
    int score = 0;
    //int a = strlen(new_word);
    for (int j = 0; j < b; j++)
        {
            score = score + POINTS[arr_score[j]];
            
        }
    printf("Score: %d\n", score);
    return(score);
}

//print arr_score, score, etc. see where it is going too far. 
