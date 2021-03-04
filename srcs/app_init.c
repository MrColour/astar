/***************************************************************************
 * FILENAME:    app_init.c
 * DESCRIPTION: Does the initialization of the app.
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 15Feb2021
***************************************************************************/

#include "astar.h"

#define OFFSET_X (12)
#define OFFSET_Y (12)

t_box	**alloc_map(size_t rows, size_t cols)
{
	size_t	i;
	size_t	j;
	t_box	 **map;

	i = 0;
	map = SDL_calloc(rows, sizeof(*map));
	while (i < rows)
	{
		j = 0;
		map[i] = SDL_calloc(cols, sizeof(**map));
		while (j < cols)
		{
			map[i][j].kind = A_NONE;
			map[i][j].render = SDL_FALSE;

			SDLX_new_Sprite(&(map[i][j].sprite));
			map[i][j].sprite._dst = (SDL_Rect){
				OFFSET_X + j * (BOX_SIZE + 1),
				OFFSET_Y + i * (BOX_SIZE + 1),
				BOX_SIZE,
				BOX_SIZE
			};

			fetch_box_sprite(&(map[i][j].sprite.sprite_data), 3);
			j++;
		}
		i++;
	}
	return (map);
}

int		astar_init(t_app *dst)
{
	dst->ticks = 0;
	dst->quit = SDL_FALSE;

	SDL_memset4(&(dst->bg_color), 0x00404040, 4);

	dst->start = NULL;
	dst->end = NULL;
	dst->play = SDL_FALSE;

	dst->rows = APP_ROWS;
	dst->cols = APP_COLS;
	dst->map = alloc_map(dst->rows, dst->cols);

	set_start_block(dst, 3, 1);
	dst->curr = new_node(1, 3);
	dst->found = SDL_FALSE;

	set_end_block(dst, 7, 15);

	SDLX_RenderQueue_init(&(dst->rQueue));

	dst->game_in = g_GameInput;

	return (EXIT_SUCCESS);
}
