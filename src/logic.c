#include <stdlib.h>
#include <time.h>

#include "../lib/headers/game.h"
#include "../lib/headers/logic.h"



int
count_cells (const game_t *game)
{
	int count = 0;
	for (int row = 0; row < N; ++row)
	{
		for (int column = 0; column < N; ++column)
		{
			if (game->board[ row ][ column ][ ID ] == game->board[ row ][ column ][ MASTER ])
			{
				count++;
			}
		}
	}
	return count;
}



void
game_over_condition (game_t *game)
{
	if (count_cells(game) == N * N)
	{
		game->state = WON_STATE;
	}
}



void
swap (int *cell_x,
	  int *cell_y)
{
	const int  temp   = *cell_x;
	          *cell_x = *cell_y;
	          *cell_y =  temp;
}



void
player_move (game_t    *game,
			 int       *row,
			 int       *column,
			 const int  direction)
{
	if (direction == UP && *row > 0)
	{
		for (size_t k = 0; k < 3; k++)
		{
			swap(&game->board[ *row ][ *column ][ k ],
				 &game->board[ *row - 1 ][ *column ][ k ]);
		}
		*row -= 1;
	}
	else if (direction == LEFT && *column > 0)
	{
		for (size_t k = 0; k < 3; k++)
		{
			swap(&game->board[ *row ][ *column ][ k ],
				 &game->board[ *row ][ *column - 1 ][ k ]);
		}
		*column -= 1;
	}
	else if (direction == DOWN && *row < N-1)
	{
		for (size_t k = 0; k < 3; k++)
		{
			swap(&game->board[ *row ][ *column ][ k ],
				 &game->board[ *row + 1 ][ *column ][ k ]);
		}
		*row += 1;
	}
	else if (direction == RIGHT && *column < N-1)
	{
		for (size_t k = 0; k < 3; k++)
		{
			swap(&game->board[ *row ][ *column ][ k ],
				 &game->board[ *row ][ *column + 1 ][ k ]);
		}
		*column += 1;
	}
}



void
reset_game (game_t *game,
			int    *row,
			int    *column)
{
	srand( time(NULL) );
	for (int i = 0; i < 10000000; ++i)
	{
		player_move(game,
				    row,
				    column,
				    rand() % 4);
	}
	for (int i = 0; i < N - 1; ++i)
	{
		player_move(game,
				    row,
				    column,
				    DOWN);
		player_move(game,
				    row,
				    column,
				    RIGHT);
	}
	game->state = RUNNING_STATE;
	game->score = 0;
	*column     = N - 1;
	*row        = N - 1;
}



void
switch_cell (game_t    *game,
			 int       *row,
			 int       *column,
			 const int  direction)
{
	if (game->state == RUNNING_STATE)
	{
		player_move(game,
					row,
					column,
					direction);
		if (game->board[ N - 1 ][ N - 1 ][ ID ] == 0)
		{
			game_over_condition(game);
		}
		game->score++;
	}
	else if (game->state == WON_STATE)
	{
		reset_game(game,
				   row,
				   column);
	}
}
