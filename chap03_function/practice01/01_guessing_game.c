/**
    Guessing game

    Orig: https://dl.dropboxusercontent.com/u/16142350/ProbSolving2016/chap03/chap03_function.pdf
*/

#include <stdio.h>  /** printf, scanf */
#include <time.h>   /** rand, srand */


/** Macros */
#define G_NUM_MAX   100
#define initialise_number_generator()   srand((unsigned int)time(NULL))
#define choose_secret_number()          ( rand() % G_NUM_MAX + 1 )


/** Function prototypes */
int
play(const int secret_number);


/** Function definitions */
int
main(void)
{
    int high_score = 0;
    int score;
    char command;

    initialise_number_generator();

    printf("Guess the secret number between 1 and %d.\n\n", G_NUM_MAX);
    while(1)
    {
        if((score = play(choose_secret_number())) < high_score) /** The lowest score is the best score */
        {
            high_score = score;
            printf("New high score: %d\n", high_score); /** This should be "New low score" .. */
        }

        printf("Play again? (Y/N) ");
        scanf(" %c", &command);

        if(command != 'y' && command != 'Y')
            break;

        printf("\n");
    }
    return 0;
}

/**
 *  \brief Play guess game
 *  \return score           count of guess
 *  \param  secret_number   secret number, which is the user should play with
 */
int
play(const int secret_number)
{
    int guess, num_guesses = 0;
    while(1)
    {
        printf("Enter guess: ");
        scanf("%d", &guess);

        ++num_guesses;

        if(guess == secret_number)
        {
            printf("You won in %d guesses!\n\n", num_guesses);
            break;
        }
        else if(guess < secret_number)
            printf("Too low; try again.\n");
        else
            printf("Too high; try again.\n");
    }

    return num_guesses;
}
