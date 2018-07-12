/*------------------------------------------------------------------------------------
| Programmer: Rahul Singal															 |
| Class: CptS 121, Spring 2016, Lab Section 1										 |
| Bonus Assignment: 5 Card Poker												     |
| Date Created: April 6, 2016														 |
| Date Last Modified: April 29, 2016												 |
| Description: Simulation of 5 Card Poker											 |
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Initializations
void start_game(void);
void play_game(int wDeck[][13], const char *wFace[], const char *wSuit[]);
void shuffle(int wDeck[][13]);
void deal_user(const int wDeck[][13], const char *wFace[], const char *wSuit[], char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10], 
			   char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], char card5_face[10], char card5_suit[10]);
void deal_computer(const int wDeck[][13], const char *wFace[], const char *wSuit[], char card1_face[10], char card1_suit[10], char card2_face[10], char card2_suit[10],
				   char card3_face[10], char card3_suit[10], char card4_face[10], char card4_suit[10], char card5_face[10], char card5_suit[10]);
int check_pair(int player, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]);
int check_two_pair(int player, int pair, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]);
int check_three_of_a_kind(int player, int pair, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]);
int check_four_of_a_kind(int player, int three_of_kind, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]);
int check_flush(int player, char card1_suit[10], char card2_suit[10], char card3_suit[10], char card4_suit[10], char card5_suit[10]);
int check_straight(int player, int pair, int flush, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10]);
int user_decision(void);
void test_change(int *num_dealt, const int wDeck[][13], const char *wFace[], const char *wSuit[], char card_face[10], char card_suit[10]);
int determine_winner(int p1_pair, int p1_two_pairs, int p1_three_of_kind, int p1_four_of_kind, int p1_flush, int p1_straight,
					 int p2_pair, int p2_two_pairs, int p2_three_of_kind, int p2_four_of_kind, int p2_flush, int p2_straight);
void computer_decision(int *change_1, int *change_2, int *change_3, int *change_4, int *change_5, int pair, int two_pairs, int three_of_kind, int four_of_kind, int straight, 
					   int flush, char card1_face[10], char card2_face[10], char card3_face[10], char card4_face[10], char card5_face[10], char card1_suit[10], char card2_suit[10], char card3_suit[10], char card4_suit[10], char card5_suit[10]);

