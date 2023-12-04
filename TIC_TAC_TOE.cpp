#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void table();
int win();

int main() {
    int player = 1, i, choice;
    char mark;
    int playAgain = 1;
    
    do 
	{
        for (int i = 1; i < 10; ++i)
            square[i] = i + '0';
            
        player = 1;
        playAgain = 1;
        
        do 
		{
            table();
            player = (player % 2) ? 1 : 2;
            printf("Player %d, enter a number for your desired place: ", player);
            scanf("%d", &choice);
            
            mark = (player == 1) ? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && square[choice] == choice + '0') {
                square[choice] = mark;
            } 
			else 
			{
                printf("Invalid move! Try again.\n");
                player--;
                getch();
            }

            i = win();
            player++;
        } 
		while (i == -1);
        table();
        if (i == 1)
            printf("\nPlayer %d wins!\n", --player);
        else
            printf("\nGame draw!\n");

        printf("Do you want to play again? (1 for Yes / Press any button for No): ");
        scanf("%d", &playAgain);
        if (playAgain == 1) 
		{
                continue;
        } 
		else 
		{
            printf("Invalid input! Try again.\n");
            getch();
        }
    }
	while (playAgain == 1);

    printf("Thank you for playing!\n");

    return 0;
}

int win() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void table() 
{
    system("cls");
    system("color f1");
    
    
    
    printf("\n\t      #######  ###  ####   #######     #      ####   #####  ###   ####");
    printf("\n\t         #      #   #         #       # #     #        #    # #   #");
    printf("\n\t         #      #   #         #      #####    #        #    # #   ###");
    printf("\n\t         #      #   #         #     #     #   #        #    # #   #");
    printf("\n\t         #     ###  ####      #    #       #  ####     #    ###   ####\n\n\n");
    
    printf("        [X] will be marked for player-1  \n\n                      &\n\n        [O] will be marked for player-2 \n\n\n");
        printf("                   ...................\n");
         printf("                   |     |     |     | \n");
         printf("                   |  %c  |  %c  |  %c  |\n",square[1], square[2], square[3]);

         printf("                   |_____|_____|_____|\n");
         printf("                   |     |     |     |\n");

         printf("                   |  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);

         printf("                   |_____|_____|_____|\n");
         printf("                   |     |     |     |\n");

         printf("                   |  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
         printf("                   |     |     |     |\n");
         printf("                   ...................\n\n\n");
}

