/***************************************************************************
 * FILENAME:    utils.c
 * DESCRIPTION: Utility general purpose functions
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 20Feb2021
***************************************************************************/

#include "SDL2/SDL.h"

SDL_bool	in_range(int a, int b, int c)
{
	SDL_bool	result;

	result = SDL_FALSE;

	if (a <= b && b <= c)
		result = SDL_TRUE;
	return (result);
}
