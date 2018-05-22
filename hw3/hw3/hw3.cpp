//Ultimate Tic-Tac-Toe


#include "stdafx.h"


#define EMPTY 0
#define N 9
#define SUB_SIZE 3
#define SUB_NUM 3
#define TIE 1
#define PLAYER1 2
#define PLAYER2 3
#define INVALID -1
#define MIN_INDEX 1
#define NOBODY 0
#define ERROR -2


void print_welcome_message();
void game_play();//progresses the game.
char player_to_char(int player);//switches identifying player value with player name.
void print_board(int board[N][N]);//prints board line by line.
void print_numbers();//prints top number line.
void print_numbers_end();//print bottom number line.
void print_hor_border();//prints horizontal border.
bool is_sub_board_full(int board[N][N], int sub_index);
int get_sub_row(int sub_index);
int get_sub_col(int sub_index);
void print_sub_board_win(int sub_index, int curr_player);
int choose_sub_board(int sub_index,int player);
int choose_position(int board[N][N], int player, int sub_index);
int sub_board_win(int board[N][N],int player,int sub_index);
int who_is_playing(int count);
int sub_board_win_col(int board[N][N], int col, int row, int player, int sub_index);
int sub_board_win_row(int board[N][N], int col, int row, int player, int sub_index);
int sub_board_win_left_slant(int board[N][N], int col, int row, int player, int sub_index);
int sub_board_win_right_slant(int board[N][N], int col, int row, int player, int sub_index);
int game_over(int big_board[N]);
int big_board_win_col(int big_board[N]);
int big_board_win_row(int big_board[N]);
int big_board_win_right_slant(int big_board[N]);
int big_board_win_left_slant(int big_board[N]);
void start_board(int board[N][N]);
int get_position_row(int position);
int get_position_col(int position);
void print_end_message(int game_status);


int main()
{
	int game_status = 0;
	start_board;
	print_welcome_message;
	game_play;
	print_end_message(game_status);
	return 0;
}


void initialization()
{

}


void print_welcome_message()
{
	printf("Welcome to Ultimate Tic-Tac-Toe!\n");
}


void start_board(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = EMPTY;
		}
	}
}

//fix double board print at first turn.
void game_play()
{
	int choosen_sub_board = 0, choosen_position = 0, sub_index = 0, count = 3, player, board_arr[N][N];
	while (count <= 20)
	{
		player = who_is_playing(count);
		if ((count == 3) || sub_board_win(board_arr, player, choosen_sub_board))
		{
			choosen_sub_board = choose_sub_board(sub_index, player);
			print_board(board_arr);
			choosen_position = choose_position(board_arr, player, choosen_sub_board);
			count++;
		}
		else
		{
			player = who_is_playing(count);
			print_board(board_arr);
			choosen_position = choose_position(board_arr, player, choosen_position);
			print_board(board_arr);
			count++;
		}
	}
}


int game_over(int board[N])
{
	int col, row, left_slant, right_slant;
	char win_col, win_row, win_left_slant, win_right_slant;
	win_col = big_board_win_col(board);
	win_row = big_board_win_row(board);
	win_left_slant = big_board_win_left_slant(board);
	win_right_slant = big_board_win_right_slant(board);
	if (col == PLAYER1 || row == PLAYER1 || right_slant == PLAYER1 || left_slant == PLAYER1)
	{
		return PLAYER1;
	}
	if (col == PLAYER2 || row == PLAYER2 || right_slant == PLAYER2 || left_slant == PLAYER2)
	{
		return PLAYER2;
	}
	else
	{
		return EMPTY;
	}
}


int big_board_win_col(int big_board[N])
{
	for (int i = 0; i < 4; i++)
	{
		if (big_board[i] == big_board[i +=3]&& big_board[i += 3] == big_board[i +=6] && big_board[i] == PLAYER1)
		{
			return PLAYER1;
		}
		else if (big_board[i] == big_board[i += 3] && big_board[i += 3] == big_board[i += 6] && big_board[i] == PLAYER2)
		{
			return PLAYER2;
		}
	}

	return EMPTY;
}
int big_board_win_row(int big_board[N])
{
	for (int i = 0; i < 7; i+=3)
	{
		if (big_board[i] == big_board[i += 1] && big_board[i] == big_board[i += 2] && big_board[i] == PLAYER1)
		{
			return PLAYER1;
		}
		else if (big_board[i] == big_board[i += 1] && big_board[i] == big_board[i += 2] && big_board[i] == PLAYER2)
		{
			return PLAYER2;
		}
	}

	return EMPTY;
}
int big_board_win_right_slant(int big_board[N])
{
	if (big_board[3] == big_board[5] && big_board[5] == big_board[7] && big_board[3] == PLAYER1)
	{
		return PLAYER1;
	}
	else if (big_board[3] == big_board[5] && big_board[5] == big_board[7] && big_board[3] == PLAYER2)
	{
		return PLAYER2;
	}
	else
	{
		return EMPTY;
	}
}
int big_board_win_left_slant(int big_board[N])
{
	if (big_board[1] == big_board[5] && big_board[5] == big_board[9] && big_board[1] == PLAYER1)
	{
		return PLAYER1;
	}
	else if (big_board[1] == big_board[5] && big_board[5] == big_board[9] && big_board[1] == PLAYER2)
	{
		return PLAYER2;
	}
	else
	{
		return EMPTY;
	}
}


int sub_board_win_row(int board[N][N], int col, int row, int player,int sub_index)
{
	for (int i = row; i < row + 3; i++)
	{
		if (board[col][i] == board[col + 1][i] && board[col][i] == board[col + 2][i] && board[col][i] == PLAYER1)
		{
			printf("Player %c has won in sub - board %d:\n",player_to_char(player),sub_index);
			return PLAYER1;
		}
		else if (board[col][i] == board[col + 1][i] && board[col][i] == board[col + 2][i] && board[col][i] == PLAYER2)
		{
			printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
			return PLAYER2;
		}
	}
	return EMPTY;
}
int sub_board_win_col(int board[N][N], int col, int row, int player, int sub_index)
{
	for (int i = col; i < col + 3; i++)
	{
		if (board[i][row] == board[i][row + 1] && board[i][row] == board[i][row + 2] && board[i][row] == PLAYER1)
		{
			printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
			return PLAYER1;
			
		}
		else if (board[i][row] == board[i][row + 1] && board[i][row] == board[i][row + 2] && board[i][row] == PLAYER2)
		{
			printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
			return PLAYER2;
		}
	}
	return EMPTY;
}
int sub_board_win_right_slant(int board[N][N], int col, int row, int player, int sub_index)
{
	if (board[col+2][row] == board[col + 1][row + 1] && board[col + 2][row] == board[col][row + 2] && board[col + 1][row + 1] == PLAYER1)
	{
		printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
		return PLAYER1;
	}
	else if (board[col + 2][row] == board[col + 1][row + 1] && board[col + 2][row] == board[col][row + 2] && board[col + 1][row + 1] == PLAYER2)
	{
		printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
		return PLAYER2;
	}
	return EMPTY;
}
int sub_board_win_left_slant(int board[N][N], int col, int row, int player, int sub_index)
{
	if (board[col][row] == board[col + 1][row + 1] && board[col][row] == board[col + 2][row + 2] && board[col][row] == PLAYER1)
	{
		printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
		return PLAYER1;
	}
	else if (board[col][row] == board[col + 1][row + 1] && board[col][row] == board[col + 2][row + 2] && board[col][row] == PLAYER2)
	{
		printf("Player %c has won in sub - board %d:\n", player_to_char(player), sub_index);
		return PLAYER2;
	}
	return EMPTY;
}
int sub_board_win(int board[N][N],int player, int sub_index)
{
	int temp[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = board[i][j];
		}
	}
	int col, row;
	char win_col, win_row, win_left_slant, win_right_slant;
	col = get_sub_col(sub_index);
	row = get_sub_row(sub_index);
	win_col = sub_board_win_col(temp,col,row,player,sub_index);
	win_row = sub_board_win_row(temp, col, row, player, sub_index);
	win_left_slant = sub_board_win_left_slant(temp, col, row, player, sub_index);
	win_right_slant = sub_board_win_right_slant(temp, col, row, player, sub_index);
	if (win_col == PLAYER1 || win_row == PLAYER1 || win_right_slant == PLAYER1 || win_left_slant == PLAYER1)
	{
		return PLAYER1;
	}
	if (win_col == PLAYER2 || win_row == PLAYER2 || win_right_slant == PLAYER2 || win_left_slant == PLAYER2)
	{
		return PLAYER2;
	}
	else
	{
		return EMPTY;
	}
}


int choose_position(int board[N][N],int player,int sub_index)
{
	int col = 0,row =0, position= 0, posi_col = 0, posi_row = 0;
	while (1)
	{
		printf("Player %c, please enter the wanted position in sub-board %d:\n", player_to_char(player), sub_index);
		scanf("%d", &position);
		col = get_sub_col(sub_index);
		row = get_sub_row(sub_index);
		posi_col = get_position_col(position);
		posi_row = get_position_row(position);
		if (board[row + posi_row][col + posi_col] == EMPTY)
		{
			board[row + posi_row][col + posi_col] = player;
			return position;
		}
		else
		{
			printf("Occupied try again\n");
		}
	}
}


int choose_sub_board(int sub_index,int player)
{
	int sub_number;
	printf("Player %c, please enter the index of the wanted sub-board:",player_to_char(player));
	scanf("%d", &sub_number);
	return sub_number;
}


int who_is_playing(int count)
{
	if (count % 2)
	{
		return PLAYER1;
	}
	else
	{
		return PLAYER2;
	}
}


void print_board(int board[N][N])
{
	print_numbers();
	for (int i = 0; i<N; i++)
	{
		printf("%d", i - i % 3 + 1);
		for (int j = 0; j<SUB_SIZE; j++)
		{
			for (int k = 0; k<SUB_NUM; k++)
			{
				if (k>0)
					printf(" ");
				printf("%c", player_to_char(board[i][j*SUB_NUM + k]));
			}
			if (j<SUB_SIZE)
				printf("|");
		}
		printf("%d\n", i - i % 3 + 3);
		if (i % 3 == 2 && i != 8)
			print_hor_border();
	}
	print_numbers_end();
}
void print_numbers()
{
	printf(" ");
	for (int i = 1; i <= SUB_NUM; i++)
	{
		for (int j = 0; j<SUB_SIZE; j++)
		{
			if (j>0) printf(" ");
			printf("%d", i);
		}
		printf(" ");
	}
	printf("\n");
}
void print_hor_border()
{
	for (int i = 1; i <= SUB_NUM; i++)
	{
		for (int j = 0; j < 2 * 2 + 3; j++)
		{
			printf("-");
		} 
	}
	printf("\n");
}
char player_to_char(int player)
{
	switch (player)
	{
	case PLAYER1: return 'X';
	case PLAYER2: return 'O';
	case EMPTY: return ' ';
	}
	return '!';
}
void print_numbers_end()
{
	printf(" ");
	for (int i = 1; i <= SUB_NUM; i++)
	{
		for (int j = 0; j<SUB_SIZE; j++)
		{
			if (j>0) printf(" ");
			printf("%d", i + 6);
		}
		printf(" ");
	}
	printf("\n");
}


bool is_sub_board_full(int board[N][N], int sub_index)
{
	int sub_row = get_sub_row(sub_index);
	int sub_col = get_sub_col(sub_index);
	for (int i = sub_row; i<sub_row + SUB_SIZE; i++)
	{
		for (int j = sub_col; j<sub_col + SUB_SIZE; j++)
		{
			if (board[i][j] == EMPTY)
				return false;
		}
	}
	return true;
}
int get_sub_row(int sub_index)
{
	return ((sub_index - 1) / SUB_NUM) * SUB_SIZE;
}
int get_sub_col(int sub_index)
{
	return ((sub_index - 1) % SUB_NUM) * SUB_SIZE;
}


void print_sub_board_win(int sub_index, int curr_player)
{
	if (curr_player == NOBODY) return;
	printf("Player %c has won in sub-board %d!\n",
		player_to_char(curr_player), sub_index);
}


int get_position_row(int position)
{
	int row = 0;
	if (position > 6)
	{
		row = 2;
	}
	else if (position > 3 && position < 7)
	{
		row = 1;
	}
	return row;
}
int get_position_col(int position)
{
	int col = 0;
	if (position % 3 == 0)
	{
		col = 2;
	}
	else if (position == 2 || position == 5 || position == 8)
	{
		col = 1;
	}
	return col;
}


void print_end_message(int game_status)
{
	if (game_status == TIE)
	{
		printf("Game over, it's a tie!\n");
	}
	else
		printf("Game over, %c is the winner!\n", player_to_char(game_status));
	return;
}
