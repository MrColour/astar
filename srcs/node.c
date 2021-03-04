/***************************************************************************
 * FILENAME:    node.c
 * DESCRIPTION: File that deals with node function
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 20Feb2021
***************************************************************************/

#include "astar.h"

t_node	*new_node(int x, int y)
{
	t_node	*new;

	new = SDL_malloc(sizeof(*new));
	new->x = x;
	new->y = y;

	new->next = NULL;
	return (new);
}
