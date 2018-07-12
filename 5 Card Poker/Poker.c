/*------------------------------------------------------------------------------------
| Programmer: Rahul Singal															 |
| Class: CptS 121, Spring 2016, Lab Section 1										 |
| Bonus Assignment: 5 Card Poker												     |
| Date Created: April 6, 2016														 |
| Date Last Modified: April 29, 2016												 |
| Description: Simulation of 5 Card Poker											 |
------------------------------------------------------------------------------------*/

#include "Poker.h"

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		start_game	
| Description:			This function will start the game by initializing all the variables 
| Input Parameters:		This function will not take in anything
| Returns:				This function will not return anything
| Preconditions:		This funciton has no precondition
| Postconditions:		This function will return to the function it was callef with the initialized variables
-------------------------------------------------------------------------------------------------------------*/
void start_game(void)
{
	int option = 0;
	
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	do
	{
		printf("*****************5-Card-Poker******************\n");
		printf("\n1. Rules\n2. Start game\n3. Quit\n");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			printf("Rules:\nIt is you against the Dealer. The program will deal 5 cards to each player. You have the option of selecting to re-draw any of your cards\n");
			printf("The program will simulate the Dealer and the will decide which cards to replace\nA winner will be decided based on the following order:\n");
			printf("1. Flush\n2. Straight\n3. Four of a Kind\n4. Three of a Kind\n5. Two Pairs\n6. Pair\n");
			printf("If both players have the same hand then the result is a tie\n");
			system("pause>null");
			system("cls");
			break;
		case 2:
			play_game(deck, face, suit);
			break;
		case 3:
			printf("Goodbye!\n");
			break;
		}
	} while (option == 1);

}

//Completed BUT Error when the game ends, Run Time Check Failure... 
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		play_game
| Description:			This function run the enitre game. It will shuffle, deal, and print the cards to the
|						Screen. It willrun the game until the user wants to quit, it will change the cards if
|						The user decides to, it will automatically change the dealers cards based on the hand
|						And determine a winner
| Input Parameters:		This function will take in int wDeck[][13], const char *wFace[], const char *wSuit[]
| Returns:				This function will not return anything
| Preconditions:		The face and suit arrays are already initialized and contain the possible combinations
| Postconditions:		The function will return to main and end the game
-------------------------------------------------------------------------------------------------------------*/
void play_game(int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int index = 0, card1 = 0, card2 = 0, card3 = 0, card4 = 0;
	int j = 0, winner = 0, i = 0;
	int p1_pair = 0, p1_two_pair = 0, p1_three_of_kind = 0, p1_four_of_kind = 0, p1_flush = 0, p1_straight = 0;
	int p2_pair = 0, p2_two_pair = 0, p2_three_of_kind = 0, p2_four_of_kind = 0, p2_flush = 0, p2_straight = 0;
	int total_dealt = 0;
	int num_replace = 0;
	char play_again = { '\0' };

	int change1 = 0, change2 = 0, change3 = 0, change4 = 0, change5 = 0;

	char p1_card1_suit[10] = { "\0" };
	char p1_card1_face[10] = { "\0" };
	char p1_card2_suit[10] = { "\0" };
	char p1_card2_face[10] = { "\0" };
	char p1_card3_suit[10] = { "\0" };
	char p1_card3_face[10] = { "\0" };
	char p1_card4_suit[10] = { "\0" };
	char p1_card4_face[10] = { "\0" };
	char p1_card5_suit[10] = { "\0" };
	char p1_card5_face[10] = { "\0" };

	char p2_card1_suit[10] = { "\0" };
	char p2_card1_face[10] = { "\0" };
	char p2_card2_suit[10] = { "\0" };
	char p2_card2_face[10] = { "\0" };
	char p2_card3_suit[10] = { "\0" };
	char p2_card3_face[10] = { "\0" };
	char p2_card4_suit[10] = { "\0" };
	char p2_card4_face[10] = { "\0" };
	char p2_card5_suit[10] = { "\0" };
	char p2_card5_face[10] = { "\0" };

	system("cls");

	for (index = 0; index < 100; index++)
	{
		printf("***********5-Card-Poker************\n");
		
		p1_card1_suit[10] = "\0";
		p1_card1_face[10] = "\0";
		p1_card2_suit[10] = "\0";
		p1_card2_face[10] = "\0";
		p1_card3_suit[10] = "\0";
		p1_card3_face[10] = "\0";
		p1_card4_suit[10] = "\0";
		p1_card4_face[10] = "\0";
		p1_card5_suit[10] = "\0";
		p1_card5_face[10] = "\0";

		p2_card1_suit[10] = "\0";
		p2_card1_face[10] = "\0";
		p2_card2_suit[10] = "\0";
		p2_card2_face[10] = "\0";
		p2_card3_suit[10] = "\0";
		p2_card3_face[10] = "\0";
		p2_card4_suit[10] = "\0";
		p2_card4_face[10] = "\0";
		p2_card5_suit[10] = "\0";
		p2_card5_face[10] = "\0";

		//Need to set wDeck to 0
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 13; j++)
			{
				wDeck[i][j] = 0;
			}
		}
		
		shuffle(wDeck); //This places the cards at random spots. 
		
		deal_user(wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit, &p1_card2_face, &p1_card2_suit, &p1_card3_face, &p1_card3_suit, &p1_card4_face, 
				  &p1_card4_suit, &p1_card5_face, &p1_card5_suit); //This will deal the cards face up to the screen
	    
		deal_computer(wDeck, wFace, wSuit, &p2_card1_face, &p2_card1_suit, &p2_card2_face, &p2_card2_suit, &p2_card3_face, &p2_card3_suit, &p2_card4_face, 
					  &p2_card4_suit, &p2_card5_face, &p2_card5_suit); //This will deal the computer cards to the screen
		
		total_dealt = 10;
		//Check for all possible combinations.

		p1_pair = check_pair(1, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_pair = check_pair(2, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_two_pair = check_two_pair(1, p1_pair, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_two_pair = check_two_pair(2, p2_pair, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_three_of_kind = check_three_of_a_kind(1, p1_pair, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_three_of_kind = check_three_of_a_kind(2, p2_pair, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_four_of_kind = check_four_of_a_kind(1, p1_three_of_kind, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_four_of_kind = check_four_of_a_kind(2, p2_three_of_kind, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_flush = check_flush(1, p1_card1_suit, p1_card2_suit, p1_card3_suit, p1_card4_suit, p1_card5_suit); //Checks user
		p2_flush = check_flush(2, p2_card1_suit, p2_card2_suit, p2_card3_suit, p2_card4_suit, p2_card5_suit); //Checks computer

		p1_straight = check_straight(1, p1_pair, p1_flush, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_straight = check_straight(2, p2_pair, p2_flush, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		num_replace = user_decision(); 

		switch (num_replace)
		{
		case 0:
			//do nothing
			break;
		case 1:
			printf("Which card do you want to replace?\n");
			scanf("%d", &card1);	
			if (card1 == 1)
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit);
			}
			else if (card1 == 2)
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card2_face, &p1_card2_suit);
			}
			else if (card1 == 3)
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card3_face, &p1_card3_suit);
			}
			else if (card1 == 4)
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card4_face, &p1_card4_suit);
			}
			else if (card1 == 5)
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card5_face, &p1_card5_suit);
			}
			
			break;
		case 2:
			printf("Which two cards do you want to replace?\n");
			scanf("%d%d", &card1, &card2);
			if ((card1 == 1) || (card2 == 1))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit);
			}
			if ((card1 == 2) || (card2 == 2))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card2_face, &p1_card2_suit);
			}
			if ((card1 == 3) || (card2 == 3))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card3_face, &p1_card3_suit);
			}
			if ((card1 == 4) || (card2 == 4))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card4_face, &p1_card4_suit);
			}
			if ((card1 == 5) || (card2 == 5))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card5_face, &p1_card5_suit);
			}

			break;
		case 3: 
			printf("Which three cards do you want to replace?\n");
			scanf("%d%d%d", &card1, &card2, &card3);
			if ((card1 == 1) || (card2 == 1) || (card3 == 1))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit);
			}
			if ((card1 == 2) || (card2 == 2) || (card3 == 2))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card2_face, &p1_card2_suit);
			}
			if ((card1 == 3) || (card2 == 3) || (card3 == 3))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card3_face, &p1_card3_suit);
			}
			if ((card1 == 4) || (card2 == 4) || (card3 == 4))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card4_face, &p1_card4_suit);
			}
			if ((card1 == 5) || (card2 == 5) || (card3 == 5))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card5_face, &p1_card5_suit);
			}

			break;
		case 4:
			printf("Which four cards do you want to replace?\n");
			scanf("%d%d%d%d", &card1, &card2, &card3, &card4);
			if ((card1 == 1) || (card2 == 1) || (card3 == 1) || (card4 == 1))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit);
			}
			if ((card1 == 2) || (card2 == 2) || (card3 == 2) || (card4 == 2))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card2_face, &p1_card2_suit);
			}
			if ((card1 == 3) || (card2 == 3) || (card3 == 3) || (card4 == 3))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card3_face, &p1_card3_suit);
			}
			if ((card1 == 4) || (card2 == 4) || (card3 == 4) || (card4 == 4))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card4_face, &p1_card4_suit);
			}
			if ((card1 == 5) || (card2 == 5) || (card3 == 5) || (card4 == 5))
			{
				test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card5_face, &p1_card5_suit);
			}

			break;
		case 5:
			test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card1_face, &p1_card1_suit);
			test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card2_face, &p1_card2_suit);
			test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card3_face, &p1_card3_suit);
			test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card4_face, &p1_card4_suit);
			test_change(&total_dealt, wDeck, wFace, wSuit, &p1_card5_face, &p1_card5_suit);

			break;
		}

		system("pause>null");
		system("cls");
		//Print updated Cards.
		//printf("Test -> in Main (User)\n");
		printf("Player 1\n");
		printf("Card 1: %5s of %-8s\n", p1_card1_face, p1_card1_suit); //This prints the cards to the screen.
		printf("Card 2: %5s of %-8s\n", p1_card2_face, p1_card2_suit); //This prints the cards to the screen.
		printf("Card 3: %5s of %-8s\n", p1_card3_face, p1_card3_suit); //This prints the cards to the screen.
		printf("Card 4: %5s of %-8s\n", p1_card4_face, p1_card4_suit); //This prints the cards to the screen.
		printf("Card 5: %5s of %-8s\n", p1_card5_face, p1_card5_suit); //This prints the cards to the screen.

		//Create a function that checks the logic of the cards and determines what cards to replace for the dealer.
		
		computer_decision(&change1, &change2, &change3, &change4, &change5, p2_pair, p2_two_pair, p2_three_of_kind, p2_four_of_kind, p2_straight, p2_flush, p2_card1_face, p2_card2_face,
				p2_card3_face, p2_card4_face, p2_card5_face, p2_card1_suit, p2_card2_suit, p2_card3_suit, p2_card4_suit, p2_card5_suit);
		
		if (change1 == 1)
		{
			test_change(&total_dealt, wDeck, wFace, wSuit, &p2_card1_face, &p2_card1_suit);
		}
		if (change2 == 1)
		{
			test_change(&total_dealt, wDeck, wFace, wSuit, &p2_card2_face, &p2_card2_suit);
		}
		if (change3 == 1)
		{
			test_change(&total_dealt, wDeck, wFace, wSuit, &p2_card3_face, &p2_card3_suit);
		}
		if (change4 == 1)
		{
			test_change(&total_dealt, wDeck, wFace, wSuit, &p2_card4_face, &p2_card4_suit);
		}
		if (change5 == 1)
		{
			test_change(&total_dealt, wDeck, wFace, wSuit, &p2_card5_face, &p2_card5_suit);
		}
		
		//printf("Test -> in Main (Computer)\n");
		printf("Dealer\n");
		printf("Card 1: %5s of %-8s\n", p2_card1_face, p2_card1_suit); //This prints the cards to the screen.
		printf("Card 2: %5s of %-8s\n", p2_card2_face, p2_card2_suit); //This prints the cards to the screen.
		printf("Card 3: %5s of %-8s\n", p2_card3_face, p2_card3_suit); //This prints the cards to the screen.
		printf("Card 4: %5s of %-8s\n", p2_card4_face, p2_card4_suit); //This prints the cards to the screen.
		printf("Card 5: %5s of %-8s\n\n", p2_card5_face, p2_card5_suit); //This prints the cards to the screen.


		//Revaluate cards ->
		p1_pair = check_pair(1, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_pair = check_pair(2, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_two_pair = check_two_pair(1, p1_pair, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_two_pair = check_two_pair(2, p2_pair, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_three_of_kind = check_three_of_a_kind(1, p1_pair, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_three_of_kind = check_three_of_a_kind(2, p2_pair, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_four_of_kind = check_four_of_a_kind(1, p1_three_of_kind, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_four_of_kind = check_four_of_a_kind(2, p2_three_of_kind, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer

		p1_flush = check_flush(1, p1_card1_suit, p1_card2_suit, p1_card3_suit, p1_card4_suit, p1_card5_suit); //Checks user
		p2_flush = check_flush(2, p2_card1_suit, p2_card2_suit, p2_card3_suit, p2_card4_suit, p2_card5_suit); //Checks computer

		p1_straight = check_straight(1, p1_pair, p1_flush, p1_card1_face, p1_card2_face, p1_card3_face, p1_card4_face, p1_card5_face); //Checks user
		p2_straight = check_straight(2, p2_pair, p2_flush, p2_card1_face, p2_card2_face, p2_card3_face, p2_card4_face, p2_card5_face); //Checks computer


		//Determine a winner. 
		//Call a function that will take in the both players: straight, flush, two pairs, pairs, etc.. it will return a 1 if player 1 wins, 2 if player 2 wins, 0 if a tie.
		winner = determine_winner(p1_pair, p1_two_pair, p1_three_of_kind, p1_four_of_kind, p1_flush, p1_straight, p2_pair, p2_two_pair, p2_three_of_kind, p2_four_of_kind, p2_flush, p2_straight);

		//Then ask if they want to play again, if yes then index++, if no then index == 100.
		printf("\nDo you want to play again?(y or n)\n");
		scanf(" %c", &play_again);
		
		if (play_again == 'y')
		{
			printf("\nLets play!\n");
			system("pause>null");
			system("cls");
		}
		else if (play_again == 'n')
		{
			printf("\nGoodbye!\n");
			index = 100;
		}

	}



}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		test_change
| Description:			This function will change the card that is recieved, it will deal the next card logically
|						In the deck
| Input Parameters:		This function will take in int *num_dealt, const int wDeck[][13], const char *wFace[], 
|						const char *wSuit[], char card_face[10], char card_suit[10]
| Returns:				This function will not return anything
| Preconditions:		The num_dealt variable will have the number of cards already dealt and make sure the card
|						Dealt is the next card
| Postconditions:		The function will increment the num_dealt and change the face and suit of the given card
-------------------------------------------------------------------------------------------------------------*/
void test_change(int *num_dealt, const int wDeck[][13], const char *wFace[], const char *wSuit[], char card_face[10], char card_suit[10])
{
	int row = 0;
	int column = 0;
	int card = *num_dealt;

	/* loop through rows of wDeck */
	for (row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == card)
			{
				if (card == *num_dealt)
				{
					strcpy(card_face, wFace[column]); //This means that card1 face and suit should be different than what it was originally! hopefully 
					strcpy(card_suit, wSuit[row]);
				}
			}
		}
	}

	*num_dealt = *num_dealt + 1;

}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		shuffle
| Description:			This function will shuffle the deck 
| Input Parameters:		This function will take in int wDeck[][13]
| Returns:				This function will not return anything
| Preconditions:		The deck must contain the suits and face values
| Postconditions:		The function will change the order of corresponding face and suit 
-------------------------------------------------------------------------------------------------------------*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		deal_user
| Description:			This function will deal the cards to the user and print them to the screem
| Input Parameters:		This function will take in const int wDeck[][13], const char *wFace[], const char *wSuit[], 
|						char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10], 
|						char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], 
|						char card5_face[10], char card5_suit[10]
| Returns:				This function will not return anything
| Preconditions:		The deck must be shuffled
| Postconditions:		The values of each cards face and suit will be modified and indirectly stored
-------------------------------------------------------------------------------------------------------------*/
void deal_user(const int wDeck[][13], const char *wFace[], const char *wSuit[], char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10],
	char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], char card5_face[10], char card5_suit[10])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	printf("Player 1:\n");
					/* deal each of the 52 cards */
	for (card = 1; card <= 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					printf("Card %d: %5s of %-8s\n", card, wFace[column], wSuit[row]); //This prints the cards to the screen.
					if (card == 1)
					{
						strcpy(card1_face, wFace[column]); //CORRECT!!
						strcpy(card1_suit, wSuit[row]);
					}
					else if (card == 2)
					{
						strcpy(card2_face, wFace[column]);
						strcpy(card2_suit, wSuit[row]);
					}
					else if (card == 3)
					{
						strcpy(card3_face, wFace[column]);
						strcpy(card3_suit, wSuit[row]);
					}
					else if (card == 4)
					{
						strcpy(card4_face, wFace[column]);
						strcpy(card4_suit, wSuit[row]);
					}
					else if (card == 5)
					{
						strcpy(card5_face, wFace[column]);
						strcpy(card5_suit, wSuit[row]);
					}
				}
			}
		}
	}
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		deal_computer
| Description:			This function will deal the cards to the dealer and print the hidden card to the screen
| Input Parameters:		This function will take in const int wDeck[][13], const char *wFace[], const char *wSuit[], 
|						char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10], 
|						char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], 
|						char card5_face[10], char card5_suit[10]
| Returns:				This function will not return anything
| Preconditions:		The deck must be shuffled and the user must of been dealt their cards before
| Postconditions:		The values of each card and its corresponding face and suit values will be changed indirectly
-------------------------------------------------------------------------------------------------------------*/
void deal_computer(const int wDeck[][13], const char *wFace[], const char *wSuit[], char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10],
	char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], char card5_face[10], char card5_suit[10])
{
	int row = 0;
	int column = 0;
	int card = 0;

	printf("Dealer:\n");

	for (card = 6; card <= 10; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					printf("Card %d: ?\n", card);
					//printf("Card %d: %5s of %-8s\n", card, wFace[column], wSuit[row]); //This prints the cards to the screen.
					if (card == 6)
					{
						strcpy(card1_face, wFace[column]); //CORRECT!!
						strcpy(card1_suit, wSuit[row]);
					}
					else if (card == 7)
					{
						strcpy(card2_face, wFace[column]);
						strcpy(card2_suit, wSuit[row]);
					}
					else if (card == 8)
					{
						strcpy(card3_face, wFace[column]);
						strcpy(card3_suit, wSuit[row]);
					}
					else if (card == 9)
					{
						strcpy(card4_face, wFace[column]);
						strcpy(card4_suit, wSuit[row]);
					}
					else if (card == 10)
					{
						strcpy(card5_face, wFace[column]);
						strcpy(card5_suit, wSuit[row]);
					}
				}
			}
		}
	}
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		user_decision
| Description:			This function will determine how many cards the user wants to replace if any
| Input Parameters:		This function will not take in anything
| Returns:				This function will return the number of cards to replace
| Preconditions:		None
| Postconditions:		It will return 0 if no new cards, 1-5 for number of cards they choose
-------------------------------------------------------------------------------------------------------------*/
int user_decision(void)
{
	char replace = '\0';
	int num_replace = 0;

	printf("Do you want to replace any of your existing cards?(y or n)\n");
	scanf(" %c", &replace);

	if ((replace == 'y') || (replace == 'Y'))
	{
		printf("How many cards do you want to replace?(0-5)\n");
		scanf("%d", &num_replace);	
	}
	else
	{
		printf("Keeping your existing cards....\n");
	}
	
	return num_replace;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		computer_decision
| Description:			This function will determine which cards the dealer will change by using the logic of
|						The current hand
| Input Parameters:		This function will take in int *change_1, int *change_2, int *change_3, int *change_4, 
|						int *change_5, int pair, int two_pairs, int three_of_kind, int four_of_kind, int straight,
|						int flush, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], 
|						char card5_face[10], char card1_suit[10], char card2_suit[10], char card3_suit[10], 
|						char card4_suit[10], char card5_suit[10]
| Returns:				This function will not return anything
| Preconditions:		The cards the computer has has to be inputed, the combinations the dealer has needs to 
|						Be correct
| Postconditions:		If the function determines a card needs to be changed, then it will indirectly change 
|						change_(1-5) to a 1
-------------------------------------------------------------------------------------------------------------*/
void computer_decision(int *change_1, int *change_2, int *change_3, int *change_4, int *change_5, int pair, int two_pairs, int three_of_kind, int four_of_kind, int straight,
	int flush, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10], char card1_suit[10], char card2_suit[10], char card3_suit[10], char card4_suit[10], char card5_suit[10])
{
	if (flush == 1)
	{
		//Replace none
		*change_1 = 0;
		*change_2 = 0;
		*change_3 = 0;
		*change_4 = 0;
		*change_5 = 0;
	}
	if (straight == 1)
	{
		//Replace none
		*change_1 = 0;
		*change_2 = 0;
		*change_3 = 0;
		*change_4 = 0;
		*change_5 = 0;
	}
	else if (four_of_kind == 1)
	{
		//Replace none
		*change_1 = 0;
		*change_2 = 0;
		*change_3 = 0;
		*change_4 = 0;
		*change_5 = 0;
	}
	else if (three_of_kind == 1) 
	{
		//Replace two. -> figure out which two to change
		if (strcmp(card1_face, card2_face) == 0) //Card 1 and Card 2 are the same
		{
			if (strcmp(card2_face, card3_face) == 0) //Replace cards 4 and 5 -> 1,2,3
			{
				*change_4 = 1;
				*change_5 = 1;
			}
			else if (strcmp(card2_face, card4_face) == 0) //Replace cards 3 and 5 -> 1,2,4
			{
				*change_3 = 1;
				*change_5 = 1;
			}
			else if (strcmp(card2_face, card5_face) == 0) //Replace cards 3 and 4 -> 1,2,5
			{
				*change_3 = 1;
				*change_4 = 1;
			}
		}
		else if (strcmp(card1_face, card3_face) == 0) //Card 1 and 3 are the same.
		{
			if (strcmp(card3_face, card4_face) == 0) //Replace cards 2 and 3 -> 1,3,4
			{
				*change_2 = 1;
				*change_3 = 1;
			}
			else if (strcmp(card3_face, card5_face) == 0) //Replace cards 2 and 4 -> 1,3,5
			{
				*change_2 = 1;
				*change_4 = 1;
			}
		}
		else if (strcmp(card1_face, card4_face) == 0) //Card 1 and 4 are the same
		{
			if (strcmp(card4_face, card5_face) == 0) //Replace card 3 and 4 -> 1,4,5
			{
				*change_3 = 1;
				*change_4 = 1;
			}
		}
		else if (strcmp(card2_face, card3_face) == 0) //Card 2 and 3 are the same
		{
			if (strcmp(card3_face, card4_face) == 0) //Replace card 1 and 5 -> 2,3,4
			{
				*change_1 = 1;
				*change_5 = 1;
			}
			else if (strcmp(card3_face, card5_face) == 0) //Replace card 1 and 4 -> 2,3,5
			{
				*change_1 = 1;
				*change_4 = 1;
			}
		}
	}
	else if (two_pairs == 1)
	{
		//Replace none
		*change_1 = 0;
		*change_2 = 0;
		*change_3 = 0;
		*change_4 = 0;
		*change_5 = 0;
	}
	else if (pair == 1)
	{
		//Replace three -> Figure out which three to change
		if (strcmp(card1_face, card2_face) == 0)
		{
			*change_3 = 1;
			*change_4 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card1_face, card3_face) == 0)
		{
			*change_2 = 1;
			*change_4 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card1_face, card4_face) == 0)
		{
			*change_3 = 1;
			*change_2 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card1_face, card5_face) == 0)
		{
			*change_2 = 1;
			*change_3 = 1;
			*change_4 = 1;
		}
		else if (strcmp(card2_face, card3_face) == 0)
		{
			*change_1 = 1;
			*change_4 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card2_face, card4_face) == 0)
		{
			*change_1 = 1;
			*change_3 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card2_face, card5_face) == 0)
		{
			*change_1 = 1;
			*change_3 = 1;
			*change_4 = 1;
		}
		else if (strcmp(card3_face, card4_face) == 0)
		{
			*change_1 = 1;
			*change_2 = 1;
			*change_5 = 1;
		}
		else if (strcmp(card3_face, card5_face) == 0)
		{
			*change_1 = 1;
			*change_2 = 1;
			*change_4 = 1;
		}
		else if (strcmp(card4_face, card5_face) == 0)
		{
			*change_1 = 1;
			*change_2 = 1;
			*change_3 = 1;
		}
	}
	else
	{
		//Replace all 5.
		*change_1 = 1;
		*change_2 = 1;
		*change_3 = 1;
		*change_4 = 1;
		*change_5 = 1;
	}
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_pair
| Description:			This function will check to see if there is a pair. If the player is the user it will
|						Print the result otherwise it will not
| Input Parameters:		This function will take in int player, char card1_face[10], char card2_face[10], 
|						char card3_face[10], char card4_face[10], char card5_face[10]
| Returns:				This function will return a 1 if there is pair, 0 if none
| Preconditions:		Player has to indicate which player its searching for
| Postconditions:		Return the result
-------------------------------------------------------------------------------------------------------------*/
int check_pair(int player, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10])
{
	int pair = -1;

	if ((strcmp(card1_face, card2_face) == 0) || (strcmp(card1_face, card3_face) == 0) || (strcmp(card1_face, card4_face) == 0) || (strcmp(card1_face, card5_face) == 0) ||
		(strcmp(card2_face, card3_face) == 0) || (strcmp(card2_face, card4_face) == 0) || (strcmp(card2_face, card5_face) == 0) || (strcmp(card3_face, card4_face) == 0) || (strcmp(card3_face, card5_face) == 0) ||
		(strcmp(card4_face, card5_face) == 0))
	{
		if (player == 1)
		{
			printf("You have a pair!\n");
			pair = 1;
		}
		else
		{
			pair = 1;
		}
		
	}
	else
	{
		pair = 0;
	}

	return pair;
}

/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_two_pair
| Description:			This function will check to see if there are two pairs. It will print the result if
|						It is the first player, otherwise it will not
| Input Parameters:		This function will take in int player, int pair, char card1_face[10], char card2_face[10], 
|						char card3_face[10], char card4_face[10], char card5_face[10]
| Returns:				This function will return a 1 if there are two pairs, a 0 if ot
| Preconditions:		int pair should indicate whether there is one pair and if it shoul look for anothe
| Postconditions:		Will retrun the result of the checking
-------------------------------------------------------------------------------------------------------------*/
int check_two_pair(int player, int pair, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10])
{
	int two_pairs = -1;

	//Have to see if card 1 and card 2 are a pair then see if card 3 and card 4 are a pair. 
	//if pair == 1 then look for two distinct pairs. 
	if (pair == 1)
	{
		//Look for two distinct pairs here
		if (((strcmp(card1_face, card2_face) == 0) && (strcmp(card3_face, card4_face) == 0)) || ((strcmp(card1_face, card2_face) == 0) && (strcmp(card3_face, card5_face) == 0))
			|| ((strcmp(card1_face, card2_face) == 0) && (strcmp(card5_face, card4_face) == 0)))
		{
			two_pairs = 1;
		}
		else if (((strcmp(card2_face, card3_face) == 0) && (strcmp(card1_face, card4_face) == 0)) || ((strcmp(card2_face, card3_face) == 0) && (strcmp(card1_face, card5_face) == 0))
			|| ((strcmp(card2_face, card3_face) == 0) && (strcmp(card4_face, card5_face) == 0)))
		{
			two_pairs = 1;
		}
		else if (((strcmp(card3_face, card4_face) == 0) && (strcmp(card2_face, card5_face) == 0)) || ((strcmp(card3_face, card4_face) == 0) && (strcmp(card1_face, card5_face) == 0))
			|| ((strcmp(card4_face, card5_face) == 0) && (strcmp(card1_face, card3_face) == 0)))
		{
			two_pairs = 1;
		}
		else
		{
			two_pairs = 0;
		}
	}
	else
	{
		two_pairs = 0;
	}
	
	if ((two_pairs == 1) && (player == 1))
	{
		printf("You have two pairs!\n");
	}

	return two_pairs;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_three_of_a_kind
| Description:			This function will check to see if there is a three of a kind, it will print the result
|						If it is player 1, otherwise it will not
| Input Parameters:		This function will take in int player, int pair, char card1_face[10], char card2_face[10], 
|						char card3_face[10], char card4_face[10], char card5_face[10]
| Returns:				This function will return a 1 if there is a three of a kind, 0 otherwise
| Preconditions:		The pair should indicate if there is a pair so if it should look for a three of a kind
| Postconditions:		It will return the result of the search
-------------------------------------------------------------------------------------------------------------*/
int check_three_of_a_kind(int player, int pair, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10])
{
	int three_of_kind = -1;

	if (pair == 1)
	{
		if (strcmp(card1_face, card2_face) == 0)
		{
			if ((strcmp(card2_face, card3_face) == 0) || (strcmp(card2_face, card4_face) == 0) || (strcmp(card2_face, card5_face) == 0))
			{
				three_of_kind = 1;
			}
		}
		else if (strcmp(card2_face, card3_face) == 0)
		{
			if ((strcmp(card3_face, card1_face) == 0) || (strcmp(card3_face, card4_face) == 0) || (strcmp(card3_face, card5_face) == 0))
			{
				three_of_kind = 1;
			}
		}
		else if (strcmp(card3_face, card4_face) == 0) 
		{
			if ((strcmp(card4_face, card1_face) == 0) || (strcmp(card4_face, card2_face) == 0) || (strcmp(card4_face, card5_face) == 0))
			{
				three_of_kind = 1;
			}
		}
		else if (strcmp(card4_face, card5_face) == 0)
		{
			if ((strcmp(card5_face, card1_face) == 0) || (strcmp(card5_face, card2_face) == 0) || (strcmp(card5_face, card3_face) == 0))
			{
				three_of_kind = 1;
			}
		}
		else if (strcmp(card1_face, card3_face) == 0)
		{
			if ((strcmp(card3_face, card4_face) == 0) || (strcmp(card3_face, card5_face) == 0))
			{
				three_of_kind = 1;
			}
		}
		else
		{
			three_of_kind = 0;
		}
	}
	else
	{
		three_of_kind = 0;
	}

	if ((three_of_kind == 1) && (player == 1))
	{
		printf("You have three of a kind!\n");
	}

	return three_of_kind;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_four_of_a_kind
| Description:			This function will determine if the hand has a four of a kind and print the result if
|						Player1 otherwise it will not
| Input Parameters:		This function will take in int player, int three_of_kind, char card1_face[10], 
|						char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]
| Returns:				This function will return a 1 if there is one, 0 if not
| Preconditions:		Three of a kind must indicate if there is a three of a kind 
| Postconditions:		It will return the result of the search 
-------------------------------------------------------------------------------------------------------------*/
int check_four_of_a_kind(int player, int three_of_kind, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10])
{
	int four_of_kind = -1;
	
	if (three_of_kind == 1)
	{
		if (strcmp(card1_face, card2_face) == 0)
		{
			if ((strcmp(card2_face, card3_face) == 0) && (strcmp(card3_face, card4_face) == 0))
			{
				four_of_kind = 1;
			}
			else if ((strcmp(card2_face, card4_face) == 0) && (strcmp(card4_face, card5_face) == 0))
			{
				four_of_kind = 1;
			}
			else if ((strcmp(card2_face, card5_face) == 0) && (strcmp(card5_face, card3_face) == 0))
			{
				four_of_kind = 1;
			}
		}
		else if (strcmp(card2_face, card3_face) == 0)
		{
			if ((strcmp(card2_face, card1_face) == 0) && (strcmp(card1_face, card4_face) == 0))
			{
				four_of_kind = 1;
			}
			else if ((strcmp(card2_face, card4_face) == 0) && (strcmp(card4_face, card5_face) == 0))
			{
				four_of_kind = 1;
			}
			else if ((strcmp(card2_face, card5_face) == 0) && (strcmp(card5_face, card1_face) == 0))
			{
				four_of_kind = 1;
			}
		}
		else if ((strcmp(card3_face, card4_face) == 0) && (strcmp(card3_face, card2_face) == 0) && (strcmp(card2_face, card5_face) == 0)) 
		{
			four_of_kind = 1;
		}
		else if ((strcmp(card3_face, card4_face) == 0) && (strcmp(card3_face, card1_face) == 0) && (strcmp(card1_face, card5_face) == 0))
		{
			four_of_kind = 1;
		}
		else if ((strcmp(card4_face, card5_face) == 0) && (strcmp(card4_face, card1_face) == 0) && (strcmp(card1_face, card3_face) == 0))
		{
			four_of_kind = 1;
		}
		else
		{
			four_of_kind = 0;
		}
	}
	else
	{
		four_of_kind = 0;
	}

	if ((four_of_kind == 1) && (player == 1))
	{
		printf("You have four of a kind!\n");
	}

	return four_of_kind;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_flush
| Description:			This function will check the hand for a flush and print the result if player1 otherwise
|						It will not
| Input Parameters:		This function will take in int player, char card1_suit[10], char card2_suit[10], 
|						char card3_suit[10], char card4_suit[10], char card5_suit[10]
| Returns:				This function will return a 1 if there is one, 0 if not
| Preconditions:		This function recieves the suit`s not the face values
| Postconditions:		It will return the result of the search 
-------------------------------------------------------------------------------------------------------------*/
int check_flush(int player, char card1_suit[10], char card2_suit[10], char card3_suit[10], char card4_suit[10], char card5_suit[10])
{
	int flush = -1;

	if ((strcmp(card1_suit, card2_suit) == 0) && (strcmp(card2_suit, card3_suit) == 0) && (strcmp(card3_suit, card4_suit) == 0) && (strcmp(card4_suit, card5_suit) == 0))
	{
		if (player == 1)
		{
			printf("You have a flush!\n");
			flush = 1;
		}
		else 
		{
			flush = 1;
		}
	}
	else
	{
		flush = 0;
	}

	return flush;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		check_straight
| Description:			This function will check the hand for a straight, it will print the result if player1
|						Otherwise it will not
| Input Parameters:		This function will take in int player, int pair, int flush, char card1_face[10], 
|						char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]
| Returns:				This function will return a 1 if there is one, 0 if not
| Preconditions:		Pair and flush will determine if the function should look for a straight
| Postconditions:		It will return the result of the search
-------------------------------------------------------------------------------------------------------------*/
int check_straight(int player, int pair, int flush, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10])
{
	int straight = -1, index = 0, j = 0;

	//Sort the cards. 
	char arr[5][10];

	int face[13] = { 0 };


	if ((pair == 1) || (flush == 1))
	{
		straight = 0;
	}
	else
	{
		strcpy(arr[0], card1_face);
		strcpy(arr[1], card2_face);
		strcpy(arr[2], card3_face);
		strcpy(arr[3], card4_face);
		strcpy(arr[4], card5_face);

		//Place in array for face
		for (index = 0; index < 5; index++)
		{
			if (strcmp(arr[index], "Ace") == 0)
			{
				face[0] = 1;
			}
			else if (strcmp(arr[index], "Deuce") == 0)
			{
				face[1] = 1;
			}
			else if (strcmp(arr[index], "Three") == 0)
			{
				face[2] = 1;
			}
			else if (strcmp(arr[index], "Four") == 0)
			{
				face[3] = 1;
			}
			else if (strcmp(arr[index], "Five") == 0)
			{
				face[4] = 1;
			}
			else if (strcmp(arr[index], "Six") == 0)
			{
				face[5] = 1;
			}
			else if (strcmp(arr[index], "Seven") == 0)
			{
				face[6] = 1;
			}
			else if (strcmp(arr[index], "Eight") == 0)
			{
				face[7] = 1;
			}
			else if (strcmp(arr[index], "Nine") == 0)
			{
				face[8] = 1;
			}
			else if (strcmp(arr[index], "Ten") == 0)
			{
				face[9] = 1;
			}
			else if (strcmp(arr[index], "Jack") == 0)
			{
				face[10] = 1;
			}
			else if (strcmp(arr[index], "Queen") == 0)
			{
				face[11] = 1;
			}
			else if (strcmp(arr[index], "King") == 0)
			{
				face[12] = 1;
			}
		}

		for (j = 0; j < 9; j++)
		{
			if ((face[j] == 1) && (face[j + 1] == 1) && (face[j + 2] == 1) && (face[j + 3] == 1) && (face[j + 4] == 1))
			{
				if (player == 1)
				{
					printf("You have a straight!\n");
					straight = 1;
					j = 10;
				}
				else
				{
					straight = 1;
					j = 10;
				}
			}
			else 
			{
				straight = 0;
			}
		}
	}
	
	return straight;
}

//Completed + Working
/*-----------------------------------------------------------------------------------------------------------
| Function Name:		determine_winner
| Description:			This function will determine a winner or if it is a tie based on what hands the players 
|						Have
| Input Parameters:		This function will take in int p1_pair, int p1_two_pairs, int p1_three_of_kind, 
|						int p1_four_of_kind, int p1_flush, int p1_straight, int p2_pair, int p2_two_pairs, 
|						int p2_three_of_kind, int p2_four_of_kind, int p2_flush, int p2_straight
| Returns:				This function will return 1 if player1 wins, 2 if the dealer wins, 0 for a tie
| Preconditions:		The hands must of been determined before
| Postconditions:		It will return the result after checking 
-------------------------------------------------------------------------------------------------------------*/
int determine_winner(int p1_pair, int p1_two_pairs, int p1_three_of_kind, int p1_four_of_kind, int p1_flush, int p1_straight,
	int p2_pair, int p2_two_pairs, int p2_three_of_kind, int p2_four_of_kind, int p2_flush, int p2_straight)
{
	int winner = 0; //0 means a tie, 1 means player 1, 2 means player 2
	
	if ((p1_flush == 1) || (p2_flush == 1))
		{
			if ((p1_flush == 1) && (p2_flush == 1))
			{
				printf("Tie, both players have a straight!\n");
				winner = 0;
			}
			else if (p1_flush == 1)
			{
				printf("Player 1 wins with a flush!\n");
				winner = 1;
			}
			else
			{
				printf("Dealer wins with a flush!\n");
				winner = 2;
			}
		}
	else if ((p1_straight == 1) || (p2_straight == 1))
	{
		//Then sfigure out who has it.
		if ((p1_straight == 1) && (p2_straight == 1))
		{
			printf("Tie, both players have a straight!\n");
			winner = 0;
		}
		else if (p1_straight == 1)
		{
			printf("Player 1 wins with a straight!\n");
			winner = 1;
		}
		else
		{
			printf("Dealer wins with a straight!\n");
			winner = 2;
		}
	}

	else if ((p1_four_of_kind == 1) || (p2_four_of_kind == 1))
	{
		if ((p1_four_of_kind == 1) && (p2_four_of_kind == 1))
		{
			printf("Tie, both players have a four of a kind!\n");
			winner = 0;
		}
		else if (p1_four_of_kind == 1)
		{
			printf("Player 1 wins with a four of a kind!\n");
			winner = 1;
		}
		else
		{
			printf("Dealer wins with a four of a kind!\n");
			winner = 2;
		}
	}
	else if ((p1_three_of_kind == 1) || (p2_three_of_kind == 1))
	{
		if ((p1_three_of_kind == 1) && p2_three_of_kind == 1)
		{
			printf("Tie, both players have a three of a kind!\n");
			winner = 0;
		}
		else if (p1_three_of_kind == 1)
		{
			printf("Player 1 wins with a three of a kind!\n");
			winner = 1;
		}
		else
		{
			printf("Dealer wins with a three of a kind!\n");
			winner = 2;
		}
	}
	else if ((p1_two_pairs == 1) || (p2_two_pairs == 1))
	{
		if ((p1_two_pairs == 1) && (p2_two_pairs == 1))
		{
			printf("Tie, both players have two pairs!\n");
			winner = 0;
		}
		else if (p1_two_pairs == 1)
		{
			printf("Player 1 wins with two pairs!\n");
			winner = 1;
		}
		else
		{
			printf("Dealer wins with two pairs!\n");
			winner = 2;
		}
	}
	else if ((p1_pair == 1) || (p2_pair == 1))
	{
		if ((p1_pair == 1) && (p2_pair == 1))
		{
			printf("Tie, both players have a pair!\n");
			winner = 0;
		}
		else if (p1_pair == 1)
		{
			printf("Player 1 wins with a pair!\n");
			winner = 1;
		}
		else
		{
			printf("Dealer wins with a pair!\n");
			winner = 2;
		}
	}
	else
	{
		printf("Tie, neither players have anything.\n");
		winner = 0;
	}

	return winner;
}