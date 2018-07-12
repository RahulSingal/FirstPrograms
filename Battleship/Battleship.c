#include"PA6.h"

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		start_game
| Description:			This function will ask the user if they want the rules and print them or move on
| Input Parameters:		This function will not take in any values
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void start_game(void)
{
	char rules = '\0';

	printf("************BattleShip************\n");
	printf("Would you like the rules?<y or n>\n");
	scanf(" %c", &rules);

	if ((rules == 'y') || (rules == 'Y'))
	{
		printf("In the game of battleship each player gets to place 5 ships of varying length on the 10x10 game board.\n");
		printf("Ships may be placed vertically or horizonatall and fit on one line. The Carrier has a length of 5, Battleship\n");
		printf("has a length of 4, Cruiser and Submarine has a length of 3, and the Destroyer has a length of 2.");
		printf("\n");
		printf("Each player takes turns and chooses coordinates to attack, and the board will display if the shot was a hit or\n");
		printf("miss. Once a player destroys all 5 ships that player wins!\n");
	}
	else
	{
		printf("Brilliant lets play\n");
	}


}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		populate_game_board
| Description:			This function will ask the user if they want to manually populate their game board 
|						or randomly populate and move on
| Input Parameters:		This function will take in the game board for the user
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void populate_game_board(int player1[][10])
{
	int decision = 0;

	printf("How do you want to populate the game board?\n");
	printf("1. Enter ship position manually\n");
	printf("2. Allow program to randomly position ships\n");
	scanf("%d", &decision);

	if (decision == 1)
	{
		//Call function that manually selects the position
		manually_populate(player1);
	}
	else if (decision == 2)
	{
		//Call function that randomly selects the position
		randomly_populate(player1);
	}
	else
	{
		printf("Error: Wrong selection\n");
	}

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		manually_populate
| Description:			This function will ask the user for the coordinates of each ship and place them on 
|						their corresponding game board
| Input Parameters:		This function will take in the game board for the user
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void manually_populate(int player[][10])
{
	int index = 0, row = 0, column = 0, i = 0, j = 0;
	//Shit load of printf and scanf for each ship. Maybe for loop for each ship.

	printf("\n");
	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i< 10; i++)
	{
		printf("%d", i);
		for (j = 0; j < 10; j++)
		{
			printf(" %c", player[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Carrier Ship
	for (index = 0; index < 5; index++)
	{
		printf("Please enter one set of coordinates for the Carrier(Separated by a space, enter)\n");
		scanf("%d%d", &row, &column);
		//check to see if it has been used already.
		if (player[row][column] == '-')
		{
			player[row][column] = 'c';
		}
		else
		{
			printf("Error: Coordinate is already being used\n");
			index = index - 1;
		}
	}

	printf("\n");
	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i< 10; i++)
	{
		printf("%d", i);
		for (j = 0; j < 10; j++)
		{
			printf(" %c", player[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//BattleShip
	for (index = 0; index < 4; index++)
	{
		printf("Plese enter one coordinates for the BattleShip\n");
		scanf("%d%d", &row, &column);
		if (player[row][column] == '-')
		{
			player[row][column] = 'b';
		}
		else
		{
			printf("Error: Coordinate is already being used\n");
			index = index - 1;
		}
	}

	printf("\n");
	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i< 10; i++)
	{
		printf("%d", i);
		for (j = 0; j < 10; j++)
		{
			printf(" %c", player[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Cruiser 
	for (index = 0; index < 3; index++)
	{
		printf("Please enter one coordinates for the Cruiser\n");
		scanf("%d%d", &row, &column);
		if (player[row][column] == '-')
		{
			player[row][column] = 'r';
		}
		else
		{
			printf("Error: Coordinate is already being used\n");
			index = index - 1;
		}
	}

	printf("\n");
	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i< 10; i++)
	{
		printf("%d", i);
		for (j = 0; j < 10; j++)
		{
			printf(" %c", player[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Submarine
	for (index = 0; index < 3; index++)
	{
		printf("Please enter one coordinates for the Submarine\n");
		scanf("%d%d", &row, &column);
		if (player[row][column] == '-')
		{
			player[row][column] = 's';
		}
		else
		{
			printf("Error: Coordinate is already being used\n");
			index = index - 1;
		}
	}

	printf("\n");
	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i< 10; i++)
	{
		printf("%d", i);
		for (j = 0; j < 10; j++)
		{
			printf(" %c", player[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Destroyer
	for (index = 0; index < 2; index++)
	{
		printf("Please enter one coordinates for the Destroyer\n");
		scanf("%d%d", &row, &column);
		if (player[row][column] == '-')
		{
			player[row][column] = 'd';
		}
		else
		{
			printf("Error: Coordinate is already being used\n");
			index = index - 1;
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		randomly_populate
| Description:			This function will randomly populate the game board making sure that the ship do not
|						overlap each other
| Input Parameters:		This function will take in the game board for the player
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void randomly_populate(int player[][10])
{
	int row_carrier = 0, column_carrier = 0, row_battleship = 0, column_battleship = 0, row_cruiser = 0, column_cruiser = 0,
		row_submarine = 0, column_submarine = 0, row_destroyer = 0, column_destroyer = 0;

	int path = 0, index = 0, i = 0, value = 0;

	//For Carrier
	path = rand() % 2; //either 0 or 1 (0 is vertical, 1 is horizontal)
	if (path == 0)
	{
		row_carrier = rand() % 6;
		column_carrier = rand() % 10;
		for (index = 0; index < 5; index++)
		{
			player[row_carrier + index][column_carrier] = 'c';
		}
	}
	else if (path == 1)
	{
		row_carrier = rand() % 10;
		column_carrier = rand() % 6;
		for (index = 0; index < 5; index++)
		{
			player[row_carrier][column_carrier + index] = 'c';
		}
	}

	//For Battleship
	path = rand() % 2; //either 0 or 1 (0 is vertical, 1 is horizontal)
	if (path == 0) //Vertical. So change rows. 
	{
		do
		{
			row_battleship = rand() % 7;
			column_battleship = rand() % 10;
			if ((player[row_battleship][column_battleship] != '-') || (player[row_battleship + 1][column_battleship] != '-')
				|| (player[row_battleship + 2][column_battleship] != '-') || (player[row_battleship + 3][column_battleship] != '-'))
			{
				//Will skip remaining code and re-roll row and column.
				value = 0;
			}
			else
			{
				for (index = 0; index < 4; index++)
				{
					player[row_battleship + index][column_battleship] = 'b';
				}
				value = 1;
			}
		} while (value == 0);
	}
	else if (path == 1)
	{
		do
		{
			row_battleship = rand() % 10;
			column_battleship = rand() % 7;
			if ((player[row_battleship][column_battleship] != '-') || (player[row_battleship][column_battleship + 1] != '-')
				|| (player[row_battleship][column_battleship + 2] != '-') || (player[row_battleship][column_battleship + 3] != '-'))
			{
				//Will skip remaining code and re-roll row and column
				value = 0;
			}
			else
			{
				for (index = 0; index < 4; index++)
				{
					player[row_battleship][column_battleship + index] = 'b';
				}
				value = 1;
			}
		} while (value == 0);
	}

	//For Cruiser
	path = rand() % 2; //either 0 or 1 (0 is vertical, 1 is horizontal)
	if (path == 0) //Vertical. So change rows. 
	{
		do
		{
			row_cruiser = rand() % 8;
			column_cruiser = rand() % 10;
			if ((player[row_cruiser][column_cruiser] != '-') || (player[row_cruiser + 1][column_cruiser] != '-')
				|| (player[row_cruiser + 2][column_cruiser] != '-'))
			{
				//Will skip remaining code and re-roll row and column.
				value = 0;
			}
			else
			{
				for (index = 0; index < 3; index++)
				{
					player[row_cruiser + index][column_cruiser] = 'r';
				}
				value = 1;
			}
		} while (value == 0);
	}
	else if (path == 1)
	{
		do
		{
			row_cruiser = rand() % 10;
			column_cruiser = rand() % 8;
			if ((player[row_cruiser][column_cruiser] != '-') || (player[row_cruiser][column_cruiser + 1] != '-')
				|| (player[row_cruiser][column_cruiser + 2] != '-'))
			{
				//Will skip remaining code and re-roll row and column
				value = 0;
			}
			else
			{
				for (index = 0; index < 3; index++)
				{
					player[row_cruiser][column_cruiser + index] = 'r';
				}
				value = 1;
			}
		} while (value == 0);
	}


	//For Submarine
	path = rand() % 2; //either 0 or 1 (0 is vertical, 1 is horizontal)
	if (path == 0) //Vertical. So change rows. 
	{
		do
		{
			row_submarine = rand() % 8;
			column_submarine = rand() % 10;
			if ((player[row_submarine][column_submarine] != '-') || (player[row_submarine + 1][column_submarine] != '-')
				|| (player[row_submarine + 2][column_submarine] != '-'))
			{
				//Will skip remaining code and re-roll row and column.
				value = 0;
			}
			else
			{
				for (index = 0; index < 3; index++)
				{
					player[row_submarine + index][column_submarine] = 's';
				}
				value = 1;
			}
		} while (value == 0);
	}
	else if (path == 1)
	{
		do
		{
			row_submarine = rand() % 10;
			column_submarine = rand() % 8;
			if ((player[row_submarine][column_submarine] != '-') || (player[row_submarine][column_submarine + 1] != '-')
				|| (player[row_submarine][column_submarine + 2] != '-'))
			{
				//Will skip remaining code and re-roll row and column
				value = 0;
			}
			else
			{
				for (index = 0; index < 3; index++)
				{
					player[row_submarine][column_submarine + index] = 's';
				}
				value = 1;
			}
		} while (value == 0);
	}

	//For Destroyer
	path = rand() % 2; //either 0 or 1 (0 is vertical, 1 is horizontal)
	if (path == 0) //Vertical. So change rows. 
	{
		do
		{
			row_destroyer = rand() % 9;
			column_destroyer = rand() % 10;
			if ((player[row_destroyer][column_destroyer] != '-') || (player[row_destroyer + 1][column_destroyer] != '-'))
			{
				//Will skip remaining code and re-roll row and column.
				value = 0;
			}
			else
			{
				for (index = 0; index < 2; index++)
				{
					player[row_destroyer + index][column_destroyer] = 'd';
				}
				value = 1;
			}
		} while (value == 0);
	}
	else if (path == 1)
	{
		do
		{
			row_destroyer = rand() % 10;
			column_destroyer = rand() % 9;
			if ((player[row_destroyer][column_destroyer] != '-') || (player[row_destroyer][column_destroyer + 1] != '-'))
			{
				//Will skip remaining code and re-roll row and column
				value = 0;
			}
			else
			{
				for (index = 0; index < 2; index++)
				{
					player[row_destroyer][column_destroyer + index] = 'd';
				}
				value = 1;
			}
		} while (value == 0);
	}
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		who_goes_first
| Description:			This function will determine which player goes forth, print the result to the screen
						and return the result
| Input Parameters:		This function will not take in in any values
| Returns:				This function will return the a 0 if player1 goes first or 1 if player2 goes first
-------------------------------------------------------------------------------------------------------------*/
int who_goes_first(void)
{
	int value = 0;

	value = rand() % 2; //Either 0 or 1.

	if (value == 0) //player1
	{
		printf("Player 1 has been randomly selected to go first!\n");
		system("pause");
	}
	else
	{
		printf("Player 2 has been randomly selected to go first!\n");
		system("pause");
	}

	return value;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		print_board
| Description:			This function will print the board to the screen
| Input Parameters:		This function will take in the game board of the player
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void print_board(int board[][10])
{
	int i = 0, j = 0;

	printf("  %d %d %d %d %d %d %d %d %d %d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (i = 0; i < 10; i++)
	{
	printf("%d", i);
	for (j = 0; j < 10; j++)
	{
	printf(" %c", board[i][j]);
	}
	printf("\n");
	}
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		lets_play
| Description:			This function will play the entire game
| Input Parameters:		This function will take in the result of who goes first, the corresponding game boards
|						for each player (3 total)
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void lets_play(int first, int player1[][10], int player2[][10], int player2_hidden[][10])
{
	Stats p1_stats = { 0,0,0,0.0};
	Stats p2_stats = { 0,0,0, 0.0};

	if (first == 0)
	{
		//Player one goes first
		//Function that runs the game with player1 going first
		play_for_one(player1, player2, player2_hidden, first);
	}
	else if (first == 1)
	{
		//Player two goes first
		//Function that runs the game with player2 going first
		play_for_one(player1, player2, player2_hidden, first);

	}
	

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		play_for_one
| Description:			This function will play the entire game with player one going first
| Input Parameters:		This function will take in the game boards for each player (3 total)
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void play_for_one(int player1[][10], int player2[][10], int player2_hidden[][10], int move)
{
	FILE *infile = NULL;
	Stats p1_stats = { 0,0,0,0.0,"\0" };
	Stats p2_stats = { 0,0,0,0.0,"\0" };
	int win = 0;  
	int index = 0, row = 0, column = 0; //
	int hit_carrier_p1 = 0, hit_battleship_p1 = 0, hit_submarine_p1 = 0, hit_destroyer_p1 = 0, hit_cruiser_p1 = 0; 
	int hit_carrier_p2 = 0, hit_battleship_p2 = 0, hit_submarine_p2 = 0, hit_destroyer_p2 = 0, hit_cruiser_p2 = 0;
	int num_of_hits_player1 = 0, num_of_hits_player2 = 0, num_of_misses_player1 = 0, num_of_misses_player2 = 0, num_of_shots_player1 = 0, num_of_shots_player2 = 0;
	int num_destroyed_p1[5] = { 0 }, num_destroyed_p2[5] = { 0 };  
	double ratio_player1 = 0, ratio_player2 = 0;
	int result = 0, same = 0, repeat = 0, player = 0; 
	char ship;
	int done = -2;
	int num_destroyed = 0;

	infile = fopen("battleship.log", "w");

	do
	{
		//This function runs the entire game.
		system("cls");
		for (index = 0; index < 5; index++)
		{
			do
			{
				printf("Player 1\n"); //Prints user`s board
				print_board(player1);
				printf("Player 2\n"); //Prints computers hidden board
				print_board(player2_hidden);
				player = 1;
				coordinates_of_attack(&row, &column); //Will return the selected coordinates 
				result = hit_miss_or_destroy_p2(row, column, player2, player2_hidden); //0 means re-check, 1 means it is a hit, -1 means it is a miss. 

				fprintf(infile, "%s\n", "Player 1:");

				if (result == 0)
				{
					same = 0; //Runs back in the do-while
					system("pause");
				}
				else if (result == 1)
				{
					
					//Write the coordinates to the logfile. 
					fprintf(infile, "%s %d %s %d %s\n", "Row:", row, ",Column:", column, ",Hit");
					system("cls");
					same = 1; //Gets out of the do-while
					num_of_hits_player1 = num_of_hits_player1 + 1;
					num_of_shots_player1 = num_of_shots_player1 + 1;
					printf("%d,%d is a hit!\n", row, column);
					ship = update_board_p2(player2, player2_hidden, row, column, result);
					update_ships(ship, &hit_carrier_p1, &hit_battleship_p1, &hit_cruiser_p1, &hit_submarine_p1, &hit_destroyer_p1);
				}
				else if (result == -1)
				{
					fprintf(infile, "%s %d %s %d %s\n", "Row:", row, ",Column:", column, ",Miss");
					system("cls");
					same = 1;
					num_of_misses_player1 = num_of_misses_player1 + 1;
					num_of_shots_player1 = num_of_shots_player1 + 1;
					printf("%d,%d is a miss!\n", row, column);
					update_board_p2(player2, player2_hidden, row, column, result);
				}
			} while (same == 0);

			fprintf(infile, "%s\n", "Player 2:");
			check_destruction(infile, hit_carrier_p1, hit_battleship_p1, hit_cruiser_p1, hit_submarine_p1, hit_destroyer_p1, num_destroyed_p1);
			printf("Player 1\n"); //Prints user`s board
			print_board(player1);
			printf("Player 2\n"); //Prints computers hidden board
			print_board(player2_hidden);

			do
			{
				computer_shot(&row, &column);
				result = hit_miss_or_destroy(row, column, player1);
				if (result == 0)
				{
					repeat = 0;
				}
				else if (result == 1)
				{
					fprintf(infile, "%s %d %s %d %s\n", "Row:", row, ",Column:", column, ",Hit");
					printf("Computer Selects: %d,%d\n", row, column);
					printf("%d,%d is a hit!\n", row, column);
					num_of_hits_player2 = num_of_hits_player2 + 1;
					num_of_shots_player2 = num_of_shots_player2 + 1;
					repeat = 1;
					ship = update_board_p1(player1, row, column, result);
					update_ships(ship, &hit_carrier_p2, &hit_battleship_p2, &hit_cruiser_p2, &hit_submarine_p2, &hit_destroyer_p2);
				}
				else if (result == -1)
				{
					fprintf(infile, "%s %d %s %d %s\n", "Row:", row, ",Column:", column, ",Miss");
					printf("Computer Selects: %d,%d\n", row, column);
					printf("%d,%d is a miss!\n", row, column);
					num_of_misses_player2 = num_of_misses_player2 + 1;
					num_of_shots_player2 = num_of_shots_player2 + 1;
					update_board_p1(player1, row, column, result);
					repeat = 1;
				}

			} while (repeat == 0);

			check_destruction(infile, hit_carrier_p2, hit_battleship_p2, hit_cruiser_p2, hit_submarine_p2, hit_destroyer_p2, num_destroyed_p2);
			done = check_win(infile, num_destroyed_p1, num_destroyed_p2); //retuns a 0 if player 1 wins, 1 if player 2 wins, -1 if none.
		
			if (done == 0)
			{
				index = 101;
				win = 1;
				ratio_player1 = ((double)num_of_hits_player1) / num_of_misses_player1;
				ratio_player2 = ((double)num_of_hits_player2) / num_of_misses_player2;
				fprintf(infile, "*******Player 1 Stats**********\n");
				p1_stats.total_hits = num_of_hits_player1;
				p1_stats.total_misses = num_of_misses_player1;
				p1_stats.total_shots = num_of_shots_player1;
				p1_stats.hits_miss_ratio = ratio_player1;
				strcpy(p1_stats.result, "Win!");
				fprintf(infile, "Total Hits: %d\n", p1_stats.total_hits);
				fprintf(infile, "Total Misses: %d\n", p1_stats.total_misses);
				fprintf(infile, "Total Shots: %d\n", p1_stats.total_shots);
				fprintf(infile, "Ratio: %lf\n", p1_stats.hits_miss_ratio);
				fprintf(infile, "Result: %s\n", p1_stats.result);
				fprintf(infile, "*******Player 2 Stats**********\n");
				p2_stats.total_hits = num_of_hits_player2;
				p2_stats.total_misses = num_of_misses_player2;
				p2_stats.total_shots = num_of_shots_player2;
				p2_stats.hits_miss_ratio = ratio_player2;
				strcpy(p2_stats.result, "Loss!\n");
				fprintf(infile, "Total Hits: %d\n", p2_stats.total_hits);
				fprintf(infile, "Total Misses: %d\n", p2_stats.total_misses);
				fprintf(infile, "Total Shots: %d\n", p2_stats.total_shots);
				fprintf(infile, "Ratio: %lf\n", p2_stats.hits_miss_ratio);
				fprintf(infile, "Result: %s\n", p2_stats.result);

				//Writes all the statistics to the Logfile.
			}
			else if (done == 1)
			{
				index = 101;
				win = 1;
				ratio_player1 = ((double)num_of_hits_player1) / num_of_misses_player1;
				ratio_player2 = ((double)num_of_hits_player2) / num_of_misses_player2;
				fprintf(infile, "*******Player 1 Stats**********\n");
				p1_stats.total_hits = num_of_hits_player1;
				p1_stats.total_misses = num_of_misses_player1;
				p1_stats.total_shots = num_of_shots_player1;
				p1_stats.hits_miss_ratio = ratio_player1;
				strcpy(p1_stats.result, "Loss!\n");
				fprintf(infile, "Total Hits: %d\n", p1_stats.total_hits);
				fprintf(infile, "Total Misses: %d\n", p1_stats.total_misses);
				fprintf(infile, "Total Shots: %d\n", p1_stats.total_shots);
				fprintf(infile, "Ratio: %lf\n", p1_stats.hits_miss_ratio);
				fprintf(infile, "Result: %s\n", p1_stats.result);
				fprintf(infile, "*******Player 2 Stats**********\n");
				p2_stats.total_hits = num_of_hits_player2;
				p2_stats.total_misses = num_of_misses_player2;
				p2_stats.total_shots = num_of_shots_player2;
				p2_stats.hits_miss_ratio = ratio_player2;
				strcpy(p2_stats.result, "Win!\n");
				fprintf(infile, "Total Hits: %d\n", p2_stats.total_hits);
				fprintf(infile, "Total Misses: %d\n", p2_stats.total_misses);
				fprintf(infile, "Total Shots: %d\n", p2_stats.total_shots);
				fprintf(infile, "Ratio: %lf\n", p2_stats.hits_miss_ratio);
				fprintf(infile, "Result: %s\n", p2_stats.result);
			}
			else if (done == -1)
			{
				//No one wins, continue playing
			}


			system("pause");
			system("cls");
		}
	} while (win == 0);

	fclose(infile);
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_win
| Description:			This function will check to see if a player has won the game by sinking all their
|						opponents ships
| Input Parameters:		This function will take in a file to write, and the corresponding game boards for
|						each playe
| Returns:				This function will return a 0 if player 1 won, 1 if player 2 won, or a -1 if neither
-------------------------------------------------------------------------------------------------------------*/
int check_win(FILE *infile, int p1_ship_destroyed[], int p2_ship_destroyed[])
{
	//0 means player 1 wins, 1 means player 2, -1 means none.
	int result = -2;
	int index = 0;

	if ((p1_ship_destroyed[0] > 0) && (p1_ship_destroyed[1] > 0) && (p1_ship_destroyed[2] > 0) && (p1_ship_destroyed[3] > 0) && (p1_ship_destroyed[4] > 0))
	{
		fprintf(infile, "%s", "Player 1 Wins\n");
		printf("Player 1 Wins!\n");
		printf("Statistics outputted to logfile Succesfully!\n");
		result = 0;
	}
	else if ((p2_ship_destroyed[0] > 0) && (p2_ship_destroyed[1] > 0) && (p2_ship_destroyed[2] > 0) && (p2_ship_destroyed[3] > 0) && (p2_ship_destroyed[4] > 0))
	{
		fprintf(infile, "%s", "Player 2 Wins\n");
		printf("Player 2 Wins!\n");
		printf("Statistics outputted to logfile Succesfully!\n");
		result = 1;
	}
	else
	{
		result = -1;
	}
		return result;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_destruction
| Description:			This function will check to see if a ship has been destroyed 
| Input Parameters:		This function will take in a file to write, and the number of hits for each ship
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void check_destruction(FILE *infile, int carrier, int battleship, int cruiser, int submarine, int destroyer, int ship_destroyed[])
{

	if (carrier == 5) 
	{
			//Writes destruction to the logfile. ***NEED FILE IN HEADER***
			fprintf(infile, "%s", "Carrier Destroyed!\n");
			printf("Carrier has been destroyed!\n");
			ship_destroyed[0] = 1;
	}

	if (battleship == 4)
	{
			fprintf(infile, "%s", "Battleship Destroyed!\n");
			printf("Battleship has been destroyed!\n");
			ship_destroyed[1] = 1;
	}

	if (cruiser == 3) 
	{
			fprintf(infile, "%s", "Cruiser Destroyed!\n");
			printf("Cruiser has been destroyed!\n");
			ship_destroyed[2] = 1;
	}

	if (submarine == 3) 
	{
			fprintf(infile, "%s", "Submarine Destroyed!\n");
			printf("Submarine has been destroyed!\n");
			ship_destroyed[3] = 1;
	}
	if (destroyer == 2) 
	{
			fprintf(infile, "%s", "Destroyer Destroyed!\n");
			printf("Destroyer has been destroyed!\n");
			ship_destroyed[4] = 1;
	}
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		update_ships
| Description:			This function will update the total hits for each ship using pointers if the ship was
|						hit
| Input Parameters:		This function will take in the number of hits for each ship as pointers and the ship
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void update_ships(char ship, int *carrier, int *battleship, int *cruiser, int *submarine, int *destroyer)
{
	if (ship == 'b')
	{
		*battleship = *battleship + 1;
	}
	else if (ship == 'c')
	{
		*carrier = *carrier + 1;
	}
	else if (ship == 'r')
	{
		*cruiser = *cruiser + 1;
	}
	else if (ship == 's')
	{
		*submarine = *submarine + 1;
	}
	else if (ship == 'd')
	{
		*destroyer = *destroyer + 1;
	}

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		update_board_p1
| Description:			This function will update the board of player 1`s 
| Input Parameters:		This function will take in the board, the row and column, as well as the result
| Returns:				This function will return the value of the ship it updated
-------------------------------------------------------------------------------------------------------------*/
char update_board_p1(int board[][10], int row, int column, int result)
{
	char value = '\0';

	if (result == 1)
	{
		//Hit
		value = board[row][column];
		board[row][column] = '*';
	}
	else if (result == -1)
	{
		value = board[row][column];
		board[row][column] = 'm';
	}

	return value;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		update_board_p2
| Description:			This function will update the board of player 2`s
| Input Parameters:		This function will take in both the boards, the row and column, as well as the result
| Returns:				This function will return the value of the ship it updated
-------------------------------------------------------------------------------------------------------------*/
char update_board_p2(int board[][10], int hidden[][10], int row, int column, int result)
{
	char value = '\0';

	if (result == 1) //this means updating the hidden board with a *. 
	{
		//Hit
		value = board[row][column];
		hidden[row][column] = '*';
	}
	else if (result == -1)
	{
		//Miss
		value = board[row][column];
		hidden[row][column] = 'm';
	}

	return value;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		computer_shot
| Description:			This function will randomly generate a location the computer chooses to attack
| Input Parameters:		This function will take in the row and column as pointers
| Returns:				This function will not return anything 
-------------------------------------------------------------------------------------------------------------*/
void computer_shot(int *row, int *column)
{
	*row = rand() % 10;
	*column = rand() % 10;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		play_for_two
| Description:			This function will run the entire game with player 2 going first
| Input Parameters:		This function will take in the three corresponding boards of the players
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void play_for_two(int player1[][10], int player2[][10], int player2_hidden[][10])
{
	//This function runs the entire game.	
	system("cls");
	printf("Player 1\n");
	print_board(player1);
	printf("Player 2\n");
	print_board(player2_hidden);
	//Call a function that 

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		coordinates_of_attack
| Description:			This function will ask the user to enter the coordinates they want to attack
| Input Parameters:		This function will take in the row and columns as pointers
| Returns:				This function will nor return anything
-------------------------------------------------------------------------------------------------------------*/
int coordinates_of_attack(int *row, int *column)
{
	int temp_row = 0, temp_column = 0;

	printf("Please enter the row and column you want to attack.\n");
	scanf("%d%d", &temp_row, &temp_column);
	*row = temp_row;
	*column = temp_column;

	return 0;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		hit_miss_or_destroy_p2
| Description:			This function will determine if the shot choosen is a hit, miss, and/or destroy
| Input Parameters:		This function will take in the row and column, as well as the coresponding boards
| Returns:				This function will return 0 if the coordinate is already used, 1 if it is a hit, or 
|						a -1 if it is a miss
-------------------------------------------------------------------------------------------------------------*/
int hit_miss_or_destroy_p2(int row, int column, int board[][10], int hidden[][10])
{
	int result = 0, repeat = 0;

		if ((hidden[row][column] == 'm') || (hidden[row][column] == '*')) //This means that the user already selected this point. 
		{
			result = 0; //already used is 0.
			printf("Error: Already attacked this coordinate.\n");
			system("pause");
		}
		if ((board[row][column] == 'c') || (board[row][column] == 'b') || (board[row][column] == 'r')
			|| (board[row][column] == 's') || (board[row][column] == 'd'))// means its a ship. 
		{
			result = 1; //hit = 1
		}
		else if ((board[row][column] == '-') && ((hidden[row][column] != 'm') || (hidden[row][column] != '*')))
		{
			result = -1; //Miss = -1
		}

	return result;

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		hit_miss_or_destroy
| Description:			This function will determine if the shot choosen is a hit, miss, and/or destroy
| Input Parameters:		This function will take in the row and column, as wells as the board
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
int hit_miss_or_destroy(int row, int column, int board[][10])
{
	int result = 0;

	//printf("Row: %d, Column: %d\n", row, column); - Works

	//Check the board
	if ((board[row][column] == '*') || (board[row][column] == 'm')) //This means that the user already selected this point. 
	{
		result = 0; //already used is 0.
		//printf("Error: Already attacked this coordinate.\n");
	}
	if ((board[row][column] != '-') && (board[row][column] != '*') && (board[row][column] != 'm')) //This logic states that it is not a -,x,or m so therefore a ship. 
	{
		result = 1; //hit = 1
	}
	else if (board[row][column] == '-')
	{
		result = -1; //Miss = -1
	}

	return result;
}