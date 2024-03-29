#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet)
{
    char C[3] = {'J', 'Q', 'K'};
    printf("Shuffling....");
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
    int playersGuess;
    printf("what's the position of queen - 1,2, or 3?");
    scanf("%d", &playersGuess);
    if (C[playersGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("You win");
    }
    else
    {
        cash -= bet;
        printf("You loose");
    }
}

int main()
{
    int bet;
    while (cash > 0)
    {
        printf("what's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
            break;
        Play(bet);
    }
}