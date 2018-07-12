/*---------------------------------------------------------------------------------------
| Programmer: Rahul Singal															    |
| Class: CptS 121, Spring 2016, Lab Section 1										    |
| Programming Assignment: PA 5														    |
| Date Created: February 29, 2016													    |
| Date Last Modified: February 29, 2016												    |
| Description: Definitions of user-defined functions for Programming Assignment # 5     |
---------------------------------------------------------------------------------------*/

#include "Yahtzee.h"

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		play_yahtzee
| Description:			This function will run the entire game of yahtzee for both players and indirectly 
						return the score from each round in the score array.
| Input Parameters:		This function will take in the score arrays for both players as pointers
| Returns:				This function will return the scores obtained from each round indirectly using pointers
-------------------------------------------------------------------------------------------------------------*/
void play_yahtzee(int *score1, int *score2)
{
	int round = 0;
	int dice[5] = { 0 };
	int dice_usage[6] = { 0 };
	int score1_usage[14] = { 0 };
	int score2_usage[14] = { 0 };
	int combination = 0;

	for (round = 0; round < 14; round++) //Loop that will run for 14 rounds
	{
		//This will contain all the steps for running the game of yahtzee for both players. 
		// 1. Roll the dice and store in array
		// 2. Assume only one roll for now. Then put the dice values in the dice_usage array
		// 3. Ask the user to select a combination
		// 4. Perform the computaion and store in score array. increment the score usage array accordingly. 
		printf("Player1:\n");
		system("pause");
		
		dice[0] = roll_dice();
		dice[1] = roll_dice();
		dice[2] = roll_dice();
		dice[3] = roll_dice();
		dice[4] = roll_dice();

		//Function that prints the dice to the screen. 

		print_dice(dice); //WORKS

		//NEed to ask them which dice to re-roll.Problem here is that either they have to manually answer for each dice
		//If they just input the die number they want to re-roll will that work? What if they want 1/5 or 5/5?
		
		roll_again(dice);

		determine_die_usage(dice, dice_usage); //WORKS

		system("pause");

		combination = select_combination(score1_usage); //Will ask for a combination and return the selected one.
		
		score1[round] = run_combination(combination, round, dice_usage, score1_usage); //Will run the given combination and adjust the score for this round. score1_usage and dice_usage are pointers
		//WORKS For option 1 RIGHT NOW!

		printf("Score1[%d] = %d\n", round, score1[round]);
		system("pause");
		system("cls");

		//Need to reset the dice_usage array manually.
		dice_usage[0] = 0;
		dice_usage[1] = 0;
		dice_usage[2] = 0;
		dice_usage[3] = 0;
		dice_usage[4] = 0;
		dice_usage[5] = 0;
		
		//printf("\n");

		
		printf("Player 2:\n");
		system("pause");

		printf("\nPlayer2:\n");
		dice[0] = roll_dice();
		dice[1] = roll_dice();
		dice[2] = roll_dice();
		dice[3] = roll_dice();
		dice[4] = roll_dice();
		print_dice(dice); //WORKS

		roll_again(dice);

		determine_die_usage(dice, dice_usage); //WORKS

		system("pause");
		combination = select_combination(score2_usage);
		//combination = select_combination();
		score2[round] = run_combination(combination, round, dice_usage, score2_usage);

		printf("Score2[%d] = %d\n", round, score2[round]);

		//round = 14;
	}
	
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		
| Description:			This function will 
| Input Parameters:		This function will 
| Returns:				This function will 
-------------------------------------------------------------------------------------------------------------*/
void roll_again(int *dice)
{
	int rolls = 1, re_roll1 = 0, re_roll2 = 0, re_roll3 = 0, re_roll4 = 0, re_roll5 = 0, num_re_roll = 0;

	for (rolls = 1; rolls < 3; rolls++)
	{
		printf("How many dice would you like to re-roll?\n");
		scanf("%d", &num_re_roll);

		if (num_re_roll == 0)
		{
			printf("Do nothing\n");
			rolls = 3;
		}
		else if (num_re_roll == 1)
		{
			printf("Please enter which dice to re-roll\n");
			scanf("%d", &re_roll1);
			//Then in here re-roll that specific dice value. remember dice[0-5]
			dice[re_roll1 - 1] = roll_dice();
			//Then print out the dice again.
			print_dice(dice);
			//The go back to the beginning of this loop - WORKS
		}
		else if (num_re_roll == 2)
		{
			printf("Please enter which dice to re-roll\n");
			scanf("%d%d", &re_roll1, &re_roll2);
			dice[re_roll1 - 1] = roll_dice();
			dice[re_roll2 - 1] = roll_dice();
			print_dice(dice);
		}
		else if (num_re_roll == 3)
		{
			printf("Please enter which dice to re-roll\n");
			scanf("%d%d%d", &re_roll1, &re_roll2, &re_roll3);
			dice[re_roll1 - 1] = roll_dice();
			dice[re_roll2 - 1] = roll_dice();
			dice[re_roll3 - 1] = roll_dice();
			print_dice(dice);
		}
		else if (num_re_roll == 4)
		{
			printf("Please enter which dice to re-roll\n");
			scanf("%d%d%d%d", &re_roll1, &re_roll2, &re_roll3, &re_roll4);
			dice[re_roll1 - 1] = roll_dice();
			dice[re_roll2 - 1] = roll_dice();
			dice[re_roll3 - 1] = roll_dice();
			dice[re_roll4 - 1] = roll_dice();
			print_dice(dice);
		}
		else if (num_re_roll == 5)
		{
			printf("Please enter which dice to re-roll\n");
			scanf("%d%d%d%d%d", &re_roll1, &re_roll2, &re_roll3, &re_roll4, &re_roll5);
			dice[re_roll1 - 1] = roll_dice();
			dice[re_roll2 - 1] = roll_dice();
			dice[re_roll3 - 1] = roll_dice();
			dice[re_roll4 - 1] = roll_dice();
			dice[re_roll5 - 1] = roll_dice();
			print_dice(dice);
		}
	}

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
int select_combination(int *score_usage)
{
	int combination = 0;
	
	printf("Please choose from these combinations\n");
	printf("0 means you have not used it yet, 1 means you have!\n");
	printf("1. Sum of ones     %d\n", score_usage[0]);
	printf("2. Sum of twos     %d\n", score_usage[1]);
	printf("3. Sum of threes   %d\n", score_usage[2]);
	printf("4. Sum of fours    %d\n", score_usage[3]);
	printf("5. Sum of fives    %d\n", score_usage[4]);
	printf("6. Sum of sixes    %d\n", score_usage[5]);
	printf("7. Three of a kind %d\n", score_usage[6]);
	printf("8. Four of a kind  %d\n", score_usage[7]);
	printf("9. Full house      %d\n", score_usage[8]);
	printf("10. Small Straight %d\n", score_usage[9]);
	printf("11. Large Straight %d\n", score_usage[10]);
	printf("12. Yahtzee        %d\n", score_usage[11]);
	printf("13. Chance         %d\n", score_usage[12]);
	scanf("%d", &combination);
	
	return combination;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
int run_combination(int combination, int round, int *dice_usage, int *score_usage)
{
	int sum = 0;
	if (combination == 1)
	{
		//Sum of ones
		sum = sum_of_ones(dice_usage, score_usage); //Pointers so I can use them accordingly. 
											  //In the function check to see value of score_usage then add a one to it. 
											  //It will return the sum. 
	}
	else if (combination == 2)
	{
		//Sum of twos
		sum = sum_of_twos(dice_usage, score_usage);
	}
	else if (combination == 3)
	{
		//Sum of threes
		sum = sum_of_threes(dice_usage, score_usage);
	}
	else if (combination == 4)
	{
		//Sum of fours
		sum = sum_of_fours(dice_usage, score_usage);
	}
	else if (combination == 5)
	{
		//Sum of fives
		sum = sum_of_fives(dice_usage, score_usage);
	}
	else if (combination == 6)
	{
		//Sum of sixes
		sum = sum_of_sixes(dice_usage, score_usage);
	}
	else if (combination == 7)
	{
		//Three of a kind
		sum = three_of_a_kind(dice_usage, score_usage);
	}
	else if (combination == 8)
	{
		//Four of a kind
		sum = four_of_a_kind(dice_usage, score_usage);
	}
	else if (combination == 9)
	{
		//Full House
		sum = full_house(dice_usage, score_usage);
	}
	else if (combination == 10)
	{
		//Small Straight
		sum = small_straight(dice_usage, score_usage);
	}
	else if (combination == 11)
	{
		//Large Straight
		sum = large_straight(dice_usage, score_usage);
	}
	else if (combination == 12)
	{
		//Yahtzee
		sum = yahtzee(dice_usage, score_usage);
	}
	else if (combination == 13)
	{
		//Chance
		sum = chance(dice_usage, score_usage);
	}
	else
	{
		printf("Error: You did not select from 1 to 13\n");
		sum = 0;
	}
	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_ones
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_ones(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[0] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[0] * 1;
		score_usage[0] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_twos
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_twos(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[1] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[1] * 2;
		score_usage[1] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_threes
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_threes(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[2] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[2] * 3;
		score_usage[2] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_fours
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_fours(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[3] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[3] * 4;
		score_usage[3] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_fives
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_fives(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[4] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[4] * 5;
		score_usage[4] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		sum_of_sixes
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int sum_of_sixes(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[5] == 1)
	{
		printf("Error: Combination Already used\n");
	}
	else
	{
		sum = dice_usage[5] * 6;
		score_usage[5] = 1;
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		three_of_a_kind
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int three_of_a_kind(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0;
	
	if (score_usage[6] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] >= 3)
			{
				sum = (dice_usage[0] * 1) + (dice_usage[1] * 2) + (dice_usage[2] * 3) + (dice_usage[3] * 4) + (dice_usage[4] * 5) + (dice_usage[5] * 6);
				score_usage[6] = 1;
				index = 6;
			}
			else
			{
				sum = 0;
			}
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		four_of_a_kind
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int four_of_a_kind(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0;

	if (score_usage[7] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] >= 4)
			{
				sum = (dice_usage[0] * 1) + (dice_usage[1] * 2) + (dice_usage[2] * 3) + (dice_usage[3] * 4) + (dice_usage[4] * 5) + (dice_usage[5] * 6);
				score_usage[7] = 1;
				index = 6;
			}
			else
			{
				sum = 0;
			}
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		full_house
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int full_house(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0, three = 0, two = 0;

	if (score_usage[8] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] == 3)
			{
				three = 1; //This means that we found an index with a three
			}
			else if (dice_usage[index] == 2)
			{
				two = 1; //This means that we found an index with a two
			}
		}

		if ((three == 1) && (two == 1))
		{
			sum = 25;
			score_usage[8] = 1;
		}
		else
		{
			sum = 0;
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		small_straight
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int small_straight(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0, small = 0;

	if (score_usage[9] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] >= 1)
			{
				small += 1; //This will increment small if the loop finds a one
			}
		}

		if (small >= 4)
		{
			sum = 30;
			score_usage[9] = 1;
		}
		else
		{
			sum = 0;
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		large_straight
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int large_straight(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0, large = 0;

	if (score_usage[10] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] == 1)
			{
				large += 1; //This will increment small if the loop finds a one
			}
		}

		if (large == 5)
		{
			sum = 40;
			score_usage[10] = 1;
		}
		else
		{
			sum = 0;
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		yahtzee
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int yahtzee(int *dice_usage, int *score_usage)
{
	int sum = 0, index = 0;

	if (score_usage[11] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		for (index = 0; index < 6; index++)
		{
			if (dice_usage[index] == 5)
			{
				sum = 50;
				score_usage[11] = 1;
				index = 6;
			}
			else
			{
				sum = 0;
			}
		}
	}

	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		chance
| Description:			This function will calculate the sum for this combination selection
| Input Parameters:		This function will take in the the dice usage and score usage arrays as pointers
| Returns:				This function will return the sum obtained from this combination
-------------------------------------------------------------------------------------------------------------*/
int chance(int *dice_usage, int *score_usage)
{
	int sum = 0;

	if (score_usage[12] == 1)
	{
		printf("Error: Combination already used\n");
	}
	else
	{
		sum = (dice_usage[0] * 1) + (dice_usage[1] * 2) + (dice_usage[2] * 3) + (dice_usage[3] * 4) + (dice_usage[4] * 5) + (dice_usage[5] * 6);
		score_usage[12] = 1;
	}
	return sum;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void determine_die_usage(int *dice, int *dice_usage)
{
	int index = 0;

	for (index = 0; index < 5; index++)
	{
		if (dice[index] == 1)
		{
			dice_usage[0] += 1;
		}
		else if (dice[index] == 2)
		{
			dice_usage[1] += 1;
		}
		else if (dice[index] == 3)
		{
			dice_usage[2] += 1;
		}
		else if (dice[index] == 4)
		{
			dice_usage[3] += 1;
		}
		else if (dice[index] == 5)
		{
			dice_usage[4] += 1;
		}
		else if (dice[index] == 6)
		{
			dice_usage[5] += 1;
		}

	}

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		game_menu
| Description:			This function will print out a list of options that the user will select
| Input Parameters:		This function will not take in anything
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void game_menu(void)
{
	printf("1. Print game rules\n");
	printf("2. Start a game of Yathzee\n");
	printf("3. Exit\n\n");
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		get_menu_option
| Description:			This function will scanf the option selected by the user and return it
| Input Parameters:		This function will not take in anything
| Returns:				This function will return the menu option selected by the user
-------------------------------------------------------------------------------------------------------------*/
int get_menu_option(void)
{
	int option = 0;
	scanf(" %d", &option); //make sure option is 1-3 later.
	return option;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		game_rules
| Description:			This function will print out the rules of Yahtzee to the screen
| Input Parameters:		This function will not take in anything
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
void print_game_rules(void)
{
	printf("********************************Object of the Game*******************************************\n");
	printf("Roll the five dice and choose the hand category that will yield you the most points.\n");
	printf("Each of the 13 possible hands can only be used once. Once 14 rounds have passed the game ends\n\n");
	printf("****************************Point Values*************************\n");
	printf("Three of a Kind = sum of all five dice\n");
	printf("Four of a Kind = sum of all five dice\n");
	printf("Full House = 25 points\n");
	printf("Small Straight(Four dice in numerical order) = 30 points\n");
	printf("Large Straight(All five dice in numerical order) = 40 points\n");
	printf("Chance = the sum of all five dice\n");
	printf("Yahtzee(Five of a kind) = 50 points\n");
	printf("\"Ones\" through \"Sixes\" = the sum of all those values*\n");
	printf("*if this total exceeds 65 then you will recive a 35 point bonus\n");

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		roll_die
| Description:			This function will roll the dice randomly and modify the value stored in each variable
using pointers
| Input Parameters:		This function will take in all 5 die variables
| Returns:				This function will not return anything
-------------------------------------------------------------------------------------------------------------*/
int roll_dice(void)
{
	int die = 0;

	die = (rand() % 6) + 1;

	return die;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_dice(int dice[])
{
	int index = 0;

	for (index = 0; index < 5; index++)
	{
		if (dice[index] == 1)
		{
			//Print one
			printf("Dice Value = %d\n", 1);
			print_one();
		}
		else if (dice[index] == 2)
		{
			//print two
			printf("Dice Value = %d\n", 2);
			print_two();
		}
		else if (dice[index] == 3)
		{
			//print three
			printf("Dice Value = %d\n", 3);
			print_three();
		}
		else if (dice[index] == 4)
		{
			//print four
			printf("Dice Value = %d\n", 4);
			print_four();
		}
		else if (dice[index] == 5)
		{
			//print five
			printf("Dice Value = %d\n", 5);
			print_five();
		}
		else if (dice[index] == 6)
		{
			//print six
			printf("Dice Value = %d\n", 6);
			print_six();
		}

	}
		

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_one(void)
{
	printf("o o o\n");
	printf("o x o\n");
	printf("o o o\n");

}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_two(void)
{
	printf("o o x\n");
	printf("o o o\n");
	printf("x o o\n");
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_three(void)
{
	printf("o o x\n");
	printf("o x o\n");
	printf("x o o\n");
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_four(void)
{
	printf("x o x\n");
	printf("o o o\n");
	printf("x o x\n");
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_five(void)
{
	printf("x o x\n");
	printf("o x o\n");
	printf("x o x\n");
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:
| Description:			This function will
| Input Parameters:		This function will
| Returns:				This function will
-------------------------------------------------------------------------------------------------------------*/
void print_six(void)
{
	printf("x o x\n");
	printf("x o x\n");
	printf("x o x\n");
}