/***************************************************************************
 * FILENAME:    app_input.c
 * DESCRIPTION: File for the input of the application.
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 01Mar2021
***************************************************************************/

#include "astar.h"

#define OFFSET_X (12)
#define OFFSET_Y (12)

void	input_entry(t_app *cxt)
{
	int x;
	int y;

	if (SDL_BUTTON(SDL_BUTTON_LEFT) == SDL_GetMouseState(&x, &y))
	{
		x -= OFFSET_X * DISPLAY_SCALE;
		y -= OFFSET_Y * DISPLAY_SCALE;

		x /= (BOX_SIZE + 1) * DISPLAY_SCALE;
		y /= (BOX_SIZE + 1) * DISPLAY_SCALE;
		set_barrier_block(cxt, y, x);
	}

	if (SDL_BUTTON(SDL_BUTTON_RIGHT) == SDL_GetMouseState(&x, &y))
	{
		cxt->play = SDL_TRUE;
		SDL_Log("Run");
	}

	(void)cxt;
}
