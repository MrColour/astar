/***************************************************************************
 * FILENAME:    pacman_structs.h
 * DESCRIPTION: Structs to be used in the PacMan application.
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 02Feb2021
***************************************************************************/

#include "SDLX.h"

#define APP_COLS 18
#define APP_ROWS 18

enum	box_type
{
	A_NONE,
	A_START,
	A_END,
	A_BLOCK,
	A_PATH,
	A_BARRIER,
};

typedef	struct	box
{
	int			kind;
	SDL_bool	render;
	int			place;

	SDLX_Sprite	sprite;
}				t_box;

typedef	struct	s_node
{
	int			y;
	int			x;

	struct s_node	*next;
}				t_node;

typedef struct	app
{
	int			ticks;
	SDL_bool	quit;

	SDL_Color	bg_color;
	SDLX_Sprite	background;

	t_box		*start;
	t_box		*end;
	SDL_bool	play;

	size_t		rows;
	size_t		cols;
	t_box		**map;

	SDL_bool	found;
	t_node		*curr;

	SDLX_RenderQueue	rQueue;

	SDLX_GameInput		game_in;

}				t_app;
