// Betting game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cash = 100;
int Play(int bet)
{
    char P[3] = {'J', 'Q', 'K'};
    printf("Shuffling ...\n");
    srand(time(0)); // seeding random no generator
    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = P[x];
        P[x] = P[y];
        P[y] = temp; // Swaps character at position x & y
    }
    int playersGuess;
    printf("What's the position of queen - 1,2 or 3?\n");
    scanf("%d", &playersGuess);
    if (P[playersGuess - 1] == 'Q')
    {
        cash = cash + 3 * bet;
        printf("You win! Result =\"%c %c %c\" Total cash = %d\n", P[0], P[1], P[2], cash);
    }
    else
    {
        cash = cash - bet;
        printf("You lose! Result =\"%c %c %c\" Total cash = %d\n", P[0], P[1], P[2], cash);
    }
}
int main()
{
    int bet;
    printf("Welcome to Virtual Casino\n\n");
    printf("You have $%d cash and you can bet in amounts of five\n", cash);
    while (cash > 0)
    {
        printf("Enter your bet $");
        scanf("%d", &bet);
        if (bet <= 0 || bet > cash || bet % 5 != 0)
        {
            printf("Please enter a valid bet\n");
        }
        else
        {
            Play(bet);
        }
    }
    printf("\n*******GAME OVER*******\n");

    return 0;
}