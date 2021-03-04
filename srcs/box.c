/***************************************************************************
 * FILENAME:    box.c
 * DESCRIPTION: Controls some box commands.
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

void	set_start_block(t_app *app, int row, int col)
{
	if (app->start != NULL)
	{
		app->start->kind = A_NONE;
		app->start->sprite.current = 0;

		fetch_box_sprite(&(app->start->sprite.sprite_data), 0);
	}

	if (in_range(0, row, app->rows) && in_range(0, col, app->cols))
	{
		app->start = &(app->map[row][col]);

		app->start->kind = A_START;
		app->start->sprite.current = 0;
		fetch_box_sprite(&(app->start->sprite.sprite_data), 5);

	}

}

void	set_end_block(t_app *app, int row, int col)
{
	if (app->end != NULL)
	{
		app->end->kind = A_NONE;
		app->end->sprite.current = 0;

		fetch_box_sprite(&(app->end->sprite.sprite_data), 0);
	}


	if (in_range(0, row, app->rows) && in_range(0, col, app->cols))
	{
		app->end = &(app->map[row][col]);

		app->end->kind = A_END;
		app->end->sprite.current = 0;
		fetch_box_sprite(&(app->end->sprite.sprite_data), 1);
	}
}

void	set_barrier_block(t_app *app, int row, int col)
{
	if (in_range(0, row, app->rows) && in_range(0, col, app->cols))
	{
		app->map[row][col].kind = A_BARRIER;
		app->map[row][col].sprite.current = 0;
		fetch_box_sprite(&(app->map[row][col].sprite.sprite_data), 4);
	}
}

void	make_visited(t_box **box, int x, int y, int place)
{
	if (box[y][x].kind != A_END)
	{
		fetch_box_sprite(&(box[y][x].sprite.sprite_data), 0);
		box[y][x].sprite.current = 0;
		box[y][x].kind = A_PATH;
	}
	box[y][x].place = place;
}
