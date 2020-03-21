/******************************************************************************************************
 ******************************************************************************************************
 *****                                                                                            *****
 *****                                  Engenharia de Computaçao                                  *****
 *****                                                                                            *****
 *****                                         Linux Game                                         *****
 *****                                        Version 0.0.1                                       *****
 *****                                                                                            *****
 *****                                       Vinícius Aguiar                                      *****
 *****                                                                                            *****
 *****                                   26.11.2018 - 07.11.2018                                  *****
 *****                                                                                            *****
 ******************************************************************************************************
 ******************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <SDL2/SDL.h>
// #include <SDL_ttf.h>

#include "./headers/game.h"
#include "./headers/debug.h"
#include "./headers/logic.h"
#include "./headers/rendering.h"




// int
// showmenu(SDL_Surface *screen,
//          TTF_Font    *font)
// {
//         Uint32 time;
//         int x, y;
//         const int NUMMENU = 2;
//         const char *labels[NUMMENU] = {"Continue","Exit"};
//         SDL_Surface *menus[NUMMENU];
//         bool selected[NUMMENU] = {0,0};
//         SDL_Color color[2] = {{255,255,255},{255,0,0}};
//
//         menus[0] = TTF_RenderText_Solid(font,labels[0],color[0]);
//         menus[1] = TTF_RenderText_Solid(font,labels[1],color[0]);
//         SDL_Rect pos[NUMMENU];
//         pos[0].x = screen->clip_rect.w/2 - menus[0]->clip_rect.w/2;
//         pos[0].y = screen->clip_rect.h/2 - menus[0]->clip_rect.h;
//         pos[1].x = screen->clip_rect.w/2 - menus[0]->clip_rect.w/2;
//         pos[1].y = screen->clip_rect.h/2 + menus[0]->clip_rect.h;
//
//         SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00));
//
//         SDL_Event event;
//         while(1)
//         {
//                 time = SDL_GetTicks();
//                 while(SDL_PollEvent(&event))
//                 {
//                         switch(event.type)
//                         {
//                                 case SDL_QUIT:
//                                         SDL_FreeSurface(menus[0]);
//                                         SDL_FreeSurface(menus[1]);
//                                         return 1;
//                                 case SDL_MOUSEMOTION:
//                                         x = event.motion.x;
//                                         y = event.motion.y;
//                                         for(int i = 0; i < NUMMENU; i += 1) {
//                                                 if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
//                                                 {
//                                                         if(!selected[i])
//                                                         {
//                                                                 selected[i] = 1;
//                                                                 SDL_FreeSurface(menus[i]);
//                                                                 menus[i] = TTF_RenderText_Solid(font,labels[i],color[1]);
//                                                         }
//                                                 }
//                                                 else
//                                                 {
//                                                         if(selected[i])
//                                                         {
//                                                                 selected[i] = 0;
//                                                                 SDL_FreeSurface(menus[i]);
//                                                                 menus[i] = TTF_RenderText_Solid(font,labels[i],color[0]);
//                                                         }
//                                                 }
//                                         }
//                                         break;
//                                 case SDL_MOUSEBUTTONDOWN:
//                                         x = event.button.x;
//                                         y = event.button.y;
//                                         for(int i = 0; i < NUMMENU; i += 1) {
//                                                 if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
//                                                 {
//                                                         SDL_FreeSurface(menus[0]);
//                                                         SDL_FreeSurface(menus[1]);
//                                                         return i;
//                                                 }
//                                         }
//                                         break;
//                                 case SDL_KEYDOWN:
//                                         if(event.key.keysym.sym == SDLK_ESCAPE)
//                                         {
//                                                 SDL_FreeSurface(menus[0]);
//                                                 SDL_FreeSurface(menus[1]);
//                                                 return 0;
//                                         }
//                         }
//                 }
//                 for(int i = 0; i < NUMMENU; i += 1) {
//                         SDL_BlitSurface(menus[i],NULL,screen,&pos[i]);
//                 }
//                 SDL_Flip(screen);
//                 if(1000/30 > (SDL_GetTicks()-time))
//                         SDL_Delay(1000/30 - (SDL_GetTicks()-time));
//         }
// }



int
main (int         argc,
	  const char *argv[])
{
	game_t   game;
	int      column = N - 1;
	int      row    = N - 1;
	int      k      = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			game.board[ i ][ j ][ ROW_ID ]    = j;
			game.board[ i ][ j ][ COLUMN_ID ] = i;
			game.board[ i ][ j ][ ID ]        = k;
			game.board[ i ][ j ][ MASTER ]    = k++;
		}
	}
	game.board[ N - 1 ][ N - 1 ][ ID ]     = 0;
	game.board[ N - 1 ][ N - 1 ][ MASTER ] = 0;
	game.score                             = 0;
	game.state                             = WON_STATE;
	switch_cell(&game,
		          &row,
		          &column,
		          0);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Surface *surface;
	if (argv[ 1 ] == NULL)
	{
		surface = SDL_LoadBMP("../lib/pictures/guitar.bmp");
	}
	else
	{
    char *str = "../lib/pictures/";
    strcat( str, argv[ 1 ] );
		surface = SDL_LoadBMP( str );
	}
	if (surface == NULL)
	{
		fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_DisplayMode display_size;
	SDL_GetCurrentDisplayMode(0,
	                          &display_size);

	const int image_height  = surface->h;
	const int image_width   = surface->w;
	const int window_height = display_size.h * 0.5;
	const int window_width  = image_width    * window_height / image_height;
	SDL_Rect  window        =
	{
    .w = window_width  / N,
    .h = window_height / N,
	};
	SDL_Rect image =
	{
	  .w = image_width  / N,
	  .h = image_height / N,
	};

	SDL_Window *_window = SDL_CreateWindow("15 Puzzle",
	                                       100,
                                         100,
	                                       window_width,
	                                       window_height,
	                                       SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(_window,
	                                            -1,
	                                            SDL_RENDERER_ACCELERATED |
	                                            SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return EXIT_FAILURE;
	}
	else
	{
		SDL_RenderClear(renderer);
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,
	                                                    surface);
	// SDL_FreeSurface(surface);
	if (texture == NULL)
	{
		fprintf(stderr, "SDL_Texture Error: %s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_Event event;
	while (game.state != QUIT_STATE)
	{
		while (SDL_PollEvent(&event))
		{
			// showmenu(surface,
			//          arial);
			switch (event.type)
			{
				case SDL_QUIT:
					game.state = QUIT_STATE;
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.scancode)
					{
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							switch_cell(&game,
							            &row,
							            &column,
							            UP);
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							switch_cell(&game,
							            &row,
							            &column,
							            LEFT);
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							switch_cell(&game,
							            &row,
							            &column,
							            DOWN);
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							switch_cell(&game,
							            &row,
							            &column,
							            RIGHT);
							break;
						default: {}
					}
				default: {}
			}
		}

		SDL_SetRenderDrawColor(renderer,
		                       0,
		                       0,
		                       0,
		                       255);
		SDL_RenderClear(renderer);
		render_game(renderer,
			        texture,
			        &window,
			        &image,
					window_height,
					window_width,
					image_height,
					image_width,
		            &game);
		SDL_RenderPresent(renderer);

		debug_board(&game);
		debug_o_pos(row,
		            column);
		debug_score(&game);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
