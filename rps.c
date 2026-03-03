// C program for the above approach
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int game(char you, char computer)
{
    if (you == computer)
        return -1;
    else if (you == 'r')
        if (computer == 'p') return 0;
        else return 1;
    else if (you == 'p')
        if (computer == 's') return 0;
        else return 1;
    else if (you == 's')
        if (computer == 'r') return 0;
        else return 1;

}

// Driver Code
int main()
{
    // Stores the random number
    int n;

    char you, computer, result;

    // Chooses the random number
    // every time
    srand(time(NULL));

    // Make the random number less
    // than 100, divided it by 100
    n = rand() % 100;

    // Using simple probability 100 is
    // roughly divided among stone,
    // paper, and scissor
    if (n < 33)

        // s is denoting Stone
        computer = 's';

    else if (n > 33 && n < 66)

        // p is denoting Paper
        computer = 'p';

    // r is denoting Rock
    else
        computer = 'r';

    printf("\n\n\n\n\t\t\t\tEnter r for ROCK, p for PAPER and s for SCISSORS\n\t\t\t\t\t\t\t");

    // input from the user
    scanf("%c", &you);

    // Function Call to play the game
    result = game(you, computer);

    if (result == -1) {
        printf("\n\n\t\t\t\tGame Draw!\n");
    }
    else if (result == 1) {
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    }
    else { 
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }
        printf("\t\t\t\tYou choose : %c and Computer choose : %c\n",you, computer);

    return 0;
}
