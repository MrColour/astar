/***************************************************************************
 * FILENAME:    main.c
 * DESCRIPTION: Entry point for Pacman
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 01Feb2021
***************************************************************************/

#include "astar.h"

#define SPEED (6)

int	main(SDL_UNUSED int ac, SDL_UNUSED char *args[])
{
	t_app		app_cxt;

	SDLX_GetDisplay();
	astar_init(&(app_cxt));
	while (app_cxt.quit == SDL_FALSE)
	{
		app_cxt.quit = SDLX_poll();
		input_entry(&app_cxt);

		update_boxes(&app_cxt);

		SDLX_discrete_frames(&app_cxt.ticks);
		SDLX_RenderQueue_flush(SDLX_GetDisplay()->renderer, &(app_cxt.rQueue));
		SDLX_screen_reset(SDLX_GetDisplay()->renderer, &(app_cxt.bg_color));
	}
	return (EXIT_SUCCESS);
}
