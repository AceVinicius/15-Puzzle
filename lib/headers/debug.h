#ifndef DEBUG_H_
#define DEBUG_H_



void
debug_board (const game_t *game)
{
	DEBUG
	(
		puts("");
		for (int i = 0; i < N; ++i)
		{
			printf(" -");
			for (int j = 0; j < N; ++j)
			{
				printf("-----");
			}
			printf("\n |%3d |", game->board[ i ][ 0 ][ ID ]);
			for (int j = 1; j < N; ++j)
			{
				printf("%3d |", game->board[ i ][ j ][ ID ]);
			}
			puts("");
		}
		printf(" -");
		for (int j = 0; j < N; ++j)
		{
			printf("-----");
		}
		puts("");
	)
}



void
debug_o_pos (const int row,
             const int column)
{
	DEBUG
	(
		printf("\n board[ %d ][ %d ][ 2 ]\n", row, column);
	)
}



void
debug_score (const game_t *game)
{
	DEBUG
	(
		printf("\n score: %d\n", game->score);
	)
}



#endif // DEBUG_H_
