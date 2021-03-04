/***************************************************************************
 * FILENAME:    update.c
 * DESCRIPTION: Updates the states in order to draw the next frame.
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

SDL_bool	empty_box(t_box **box, int x, int y, int col, int row, SDLX_direction try)
{
	SDL_bool result;

	result = SDL_FALSE;

	if (in_range(0, x + try.c.x, col - 1) && in_range(0, y + try.c.y, row - 1))
	{
		if (box[y + try.c.y][x + try.c.x].kind == A_NONE || box[y + try.c.y][x + try.c.x].kind == A_END)
			result = SDL_TRUE;
	}

	return (result);
}

void	draw_path(t_box **box, int cols, int rows, int x, int y, int place)
{
	int tx;
	int ty;

	while (place > 0)
	{
		tx = x;
		ty = y;

		x -= 1;
		if (in_range(0, x, cols - 1) && in_range(0, y, rows - 1) && box[y][x].place == place - 1)
		{
			fetch_box_sprite(&(box[y][x].sprite.sprite_data), 2);
			box[y][x].sprite.current = 0;
			place -= 1;
			tx -= 1;
		}

		x = tx;
		x += 1;
		if (in_range(0, x, cols - 1) && in_range(0, y, rows - 1) && box[y][x].place == place - 1)
		{
			fetch_box_sprite(&(box[y][x].sprite.sprite_data), 2);
			box[y][x].sprite.current = 0;
			place -= 1;
			tx += 1;
		}

		x = tx;
		y -= 1;
		if (in_range(0, x, cols - 1) && in_range(0, y, rows - 1) && box[y][x].place == place - 1)
		{
			fetch_box_sprite(&(box[y][x].sprite.sprite_data), 2);
			box[y][x].sprite.current = 0;
			place -= 1;
			ty -= 1;
		}

		y = ty;
		y += 1;
		if (in_range(0, x, cols - 1) && in_range(0, y, rows - 1) && box[y][x].place == place - 1)
		{
			fetch_box_sprite(&(box[y][x].sprite.sprite_data), 2);
			box[y][x].sprite.current = 0;
			place -= 1;
			ty += 1;
		}

		x = tx;
		y = ty;
	}
}

void	node_update(t_box **box, int rows, int cols, t_node **curr, SDL_bool *found)
{
	t_node	*iter;
	t_node	*last;
	t_node	first;
	SDLX_direction	try;
	int				x;
	int				y;

	iter = *curr;
	*curr = NULL;
	first.next = NULL;
	last = &first;

	if (*found == SDL_TRUE)
		return ;

	while (iter != NULL)
	{
		x = iter->x;
		y = iter->y;

		if (box[y][x].kind == A_END && *found == SDL_FALSE)
		{
			*found = SDL_TRUE;
			draw_path(box, cols, rows, x, y, box[y][x].place);
		}

		try.val = SDLX_UP;
		if (empty_box(box, x, y, cols, rows, try))
		{
			last->next = new_node(x + try.c.x, y + try.c.y);
			last = last->next;
			make_visited(box, x + try.c.x, y + try.c.y, box[y][x].place + 1);
		}
		try.val = SDLX_LEFT;
		if (empty_box(box, x, y, cols, rows, try))
		{
			last->next = new_node(x + try.c.x, y + try.c.y);
			last = last->next;
			make_visited(box, x + try.c.x, y + try.c.y, box[y][x].place + 1);
		}
		try.val = SDLX_DOWN;
		if (empty_box(box, x, y, cols, rows, try))
		{
			last->next = new_node(x + try.c.x, y + try.c.y);
			last = last->next;
			make_visited(box, x + try.c.x, y + try.c.y, box[y][x].place + 1);
		}
		try.val = SDLX_RIGHT;
		if (empty_box(box, x, y, cols, rows, try))
		{
			last->next = new_node(x + try.c.x, y + try.c.y);
			last = last->next;
			make_visited(box, x + try.c.x, y + try.c.y, box[y][x].place + 1);
		}
		iter = iter->next;
	}
	*curr = first.next;
}

void	update_boxes(t_app *cxt)
{
	size_t	i;
	size_t	j;

	SDLX_Sprite	empty_box;


	fetch_box_sprite(&(empty_box.sprite_data), 3);
	SDLX_new_Sprite(&(empty_box));

	i = 0;
	while (i < cxt->rows)
	{
		j = 0;
		while (j < cxt->cols)
		{
			cxt->map[i][j].sprite.current++;
			empty_box.dst = cxt->map[i][j].sprite.dst;
			SDLX_draw_animation(SDLX_GetDisplay()->renderer, &(empty_box));
			SDLX_RenderQueue_add(&(cxt->rQueue), &(cxt->map[i][j].sprite));
			j++;
		}
		i++;
	}

	if (cxt->play == SDL_FALSE)
		return ;

	node_update(cxt->map, cxt->rows, cxt->cols, &(cxt->curr), &(cxt->found));
	fetch_box_sprite(&(cxt->start->sprite.sprite_data), 5);
	fetch_box_sprite(&(cxt->end->sprite.sprite_data), 1);
}
