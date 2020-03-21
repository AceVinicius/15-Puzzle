#ifndef GAME_H_
# define GAME_H_



#define DEBUG(X)       // X

#define UP              0
#define LEFT            1
#define DOWN            2
#define RIGHT           3

#define RUNNING_STATE   1
#define WON_STATE       2
#define QUIT_STATE      3

#define N               4

#define ROW_ID          0
#define COLUMN_ID       1
#define ID              2
#define MASTER          3



typedef struct
{
	int board[ N ][ N ][ 4 ];

	int score;
	int state;
} game_t;



#endif // GAME_H_
