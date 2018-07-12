/*----------------------------------------------------------------------------------------
| Programmer: Rahul Singal															     |
| Class: CptS 121, Spring 2016, Lab Section 1										     |
| Programming Assignment: PA 5														     |
| Date Created: February 29, 2016													     |
| Date Last Modified: February 29, 2016												     |
| Description: Initializations of user-defined functions for Programming Assignment # 5  |
----------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

#define _CRT_SECURE_NO_WARNINGS

//Function Initializations
void game_menu(void);
int get_menu_option(void);
void play_yahtzee(int *score1, int *score2);
void determine_die_usage(int *dice, int *dice_usage);
void print_game_rules(void);
int run_combination(int combination, int round, int *dice_usage, int *score_usage);
int select_combination(int *score_usage);
int roll_dice(void); 
void roll_again(int *dice);
void print_dice(int dice[]);
void print_one(void);
void print_two(void);
void print_three(void);
void print_four(void);
void print_five(void);
void print_six(void);
int sum_of_ones(int *dice_usage, int *score_usage);
int sum_of_twos(int *dice_usage, int *score_usage);
int sum_of_threes(int *dice_usage, int *score_usage);
int sum_of_fours(int *dice_usage, int *score_usage);
int sum_of_fives(int *dice_usage, int *score_usage);
int sum_of_sixes(int *dice_usage, int *score_usage);
int three_of_a_kind(int *dice_usage, int *score_usage);
int four_of_a_kind(int *dice_usage, int *score_usage);
int full_house(int *dice_usage, int *score_usage);
int small_straight(int *dice_usage, int *score_usage);
int large_straight(int *dice_usage, int *score_usage);
int yahtzee(int *dice_usage, int *score_usage);
int chance(int *dice_usage, int *score_usage);

