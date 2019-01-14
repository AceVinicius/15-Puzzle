#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "./headers/game.h"
#include "./headers/rendering.h"



void
render_game (SDL_Renderer *renderer,
			 SDL_Texture  *texture,
	         SDL_Rect     *window,
			 SDL_Rect     *image,
			 const int     window_height,
			 const int     window_width,
			 const int     image_height,
			 const int     image_width,
			 const game_t *game)
{
	for (int row = 0; row < N; ++row)
	{
		for (int column = 0; column < N; ++column)
		{
		 	if (game->state == WON_STATE || game->board[ row ][ column ][ ID ] != 0)
		 	{
			 	image->x  = game->board[ row ][ column ][ ROW_ID ]    * image_width  / N;
			 	image->y  = game->board[ row ][ column ][ COLUMN_ID ] * image_height / N;
			 	window->x = column * window_width  / N;
			 	window->y = row    * window_height / N;
			 	SDL_RenderCopy(renderer, texture, image, window);
		 	}
		}
	}
}
