#ifndef RENDERING_H_
# define RENDERING_H_



void
render_game (SDL_Renderer *renderer,
             SDL_Texture  *texture,
	         SDL_Rect     *window,
			 SDL_Rect     *image,
			 const int     window_height,
			 const int     window_width,
			 const int     image_height,
			 const int     image_width,
			 const game_t *game);



#endif // RENDERING_H_
