#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Intialization of the Struct for the Statistics.
typedef struct stats 
{
	int total_hits; 
	int total_misses;
	int total_shots;
	double hits_miss_ratio;
	char result[10];
} Stats;

//Function Initializations
void start_game(void);
void populate_game_board(int player1[][10]);
void manually_populate(int player[][10]);
void randomly_populate(int player[][10]);
int who_goes_first(void);
void lets_play(int first, int player1[][10], int player2[][10], int player2_hidden[][10]);
void play_for_one(int player1[][10], int player2[][10], int player2_hidden[][10], int move);
void play_for_two(int player1[][10], int player2[][10], int player2_hidden[][10]);
void print_board(int board[][10]);
int coordinates_of_attack(int *row, int *column);
int hit_miss_or_destroy(int row, int column, int board[][10]);
int hit_miss_or_destroy_p2(int row, int column, int board[][10], int hidden[][10]);
char update_board_p1(int board[][10], int row, int column, int result);
char update_board_p2(int board[][10], int hidden[][10], int row, int column, int result);
int check_win(FILE *infile, int p1_ship_destroyed[], int p2_ship_destroyed[]);
void update_ships(char ship, int *carrier, int *battleship, int *cruiser, int *submarine, int *destroyer);
void check_destruction(FILE *infile, int carrier, int battleship, int cruiser, int submarine, int destroyer, int ship_destroyed[]);
void computer_shot(int *row, int *column);




