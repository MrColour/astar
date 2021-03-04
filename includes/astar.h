/***************************************************************************
 * FILENAME:    pacman.h
 * DESCRIPTION: General header for pacman.
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 01Feb2021
***************************************************************************/

#ifndef PACMAN_H
# define PACMAN_H

# include "SDLX.h"

# include "astar_structs.h"
# include "astar_assets.h"

# define ASSETS "assets/"

int		astar_init(t_app *dst);
void	input_entry(t_app *cxt);
void	update_boxes(t_app *cxt);

void	set_end_block(t_app *app, int row, int col);
void	set_start_block(t_app *app, int row, int col);
void	set_barrier_block(t_app *app, int row, int col);

void	make_visited(t_box **box, int x, int y, int place);

SDL_bool	in_range(int a, int b, int c);

t_node		*new_node(int x, int y);

#endif
