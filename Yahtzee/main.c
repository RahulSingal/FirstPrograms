/*------------------------------------------------------------------------------------
| Programmer: Rahul Singal															 |
| Class: CptS 121, Spring 2016, Lab Section 1										 |
| Programming Assignment: PA 5														 |
| Date Created: February 29, 2016													 |
| Date Last Modified: February 29, 2016												 |
| Description: Main function for Programming Assignment # 5							 |
------------------------------------------------------------------------------------*/

#include "Yahtzee.h"

int main(void)
{
	int option = 0;

	//Variables needed in main: 
	int player1_score[14] = { 14 };
	int player2_score[14] = { 0 };
	int player1 = 0, player2 = 0;

	srand((unsigned int)time(NULL));

	do
	{
		game_menu();
		option = get_menu_option();
		system("pause");
		system("cls");

		if (option == 1)
		{
			print_game_rules();
		}
		else if (option == 2)
		{
			system("cls");
			//Function that take in all the variables needed from main and runs the game - needs the score array for both players
			play_yahtzee(player1_score, player2_score);

			if ((player1_score[0] + player1_score[1] + player1_score[2] + player1_score[3] + player1_score[4] + player1_score[5]) >= 63)
			{
				printf("Player 1 gets the bonus 35 points!\n");
				player1 += 35;
			}
			else
			{
				printf("Player 1 does not get the bonus.\n");
				player1 += 0;
				//Nothing
			}
			player1 = ((player1)+(player1_score[0]) + (player1_score[1]) + (player1_score[2]) + (player1_score[3]) + (player1_score[4])
				+ (player1_score[5]) + (player1_score[6]) + (player1_score[7]) + (player1_score[8]) + (player1_score[9]) + (player1_score[10])
				+ (player1_score[11]) + (player1_score[12]) + (player1_score[13]));


			if ((player2_score[0] + player2_score[1] + player2_score[2] + player2_score[3] + player2_score[4] + player2_score[5]) >= 63)
			{
				printf("Player 2 gets the bonus 35 points!\n");
				player2 += 35;
			}
			else
			{
				printf("Player 2 does not get the bonus.\n");
				player2 += 0;
				//Nothing
			}
			player2 = ((player2)+(player2_score[0]) + (player2_score[1]) + (player2_score[2]) + (player2_score[3]) + (player2_score[4])
				+ (player2_score[5]) + (player2_score[6]) + (player2_score[7]) + (player2_score[8]) + (player2_score[9]) + (player2_score[10])
				+ (player2_score[11]) + (player2_score[12]) + (player2_score[13]));

			if (player1 > player2)
			{
				printf("Player 1 beat Player 2!\n");
				printf("Player 1: %d , Player 2: %d\n", player1, player2);
			}
			else if (player2 > player1)
			{
				printf("Player 2 beat Player 1!\n");
				printf("Player 2: %d , Player 1: %d\n", player2, player1);
			}
			else if (player1 == player2)
			{
				printf("Player 1 and Player 2 are tied....\n");
				printf("Player 1: %d , Player 2: %d\n", player1, player2);
			}
		}
		else if (option == 3)
		{
			printf("Goodbye.\n");
		}
	
	} while (option == 1);


	return 0;


}