/*------------------------------------------------------------------------------------
| Programmer: Rahul Singal															 |
| Class: CptS 121, Spring 2016, Lab Section 1										 |
| Programming Assignment: PA 6														 |
| Date Created: March 21, 2016														 |
| Date Last Modified: April 4, 2016													 |
| Description: Game of Battleship													 |
------------------------------------------------------------------------------------*/

#include "PA6.h"

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		main
| Description:			This function will intialize the boards to the dash and call on functions that will
						run the entire game
| Input Parameters:		This function will take in any values
| Returns:				This function will return 0
-------------------------------------------------------------------------------------------------------------*/
int main(void)
{
	int player1_board[10][10] = { 0 }, player2_board[10][10] = { 0 }, player2_hidden_board[10][10] = { 0 };
	int i = 0, j = 0, k = 0;
	int target_row = 0, target_column = 0, first = 0;


	srand((unsigned int)time(NULL));

	//Sets each value of the game boards to '-'
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			player1_board[i][j] = '-';
		}
	}
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			player2_board[i][j] = '-';
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			player2_hidden_board[i][j] = '-';
		}
	}

	//Function that introdoces the game as asks if the user wants the rules. Scans response and goes accoringly.
	start_game();

	//Function that populates the game board for player 1.
	populate_game_board(player1_board);
	
	//Randomly populate player2`s game board
	randomly_populate(player2_board);

	//Determine who goes first
	first = who_goes_first();

	//Function that takes in the selection and runs the game. will take in player1, player2, and hidden board.
	lets_play(first, player1_board, player2_board, player2_hidden_board);

	printf("\n");

	return 0;
}



