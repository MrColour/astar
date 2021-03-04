/***************************************************************************
 * FILENAME:    box_sprites.c
 * DESCRIPTION: Handles the box sprites.
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

SDLX_Sprite_Data	*carve_box_sprite(void)
{
	size_t	i;

	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	texture = IMG_LoadTexture(SDLX_GetDisplay()->renderer, ASSETS"box.png");
	result = SDL_calloc(48 + 3, sizeof(*result));
	i = 0;
	while (i < 8)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){i * 16, 0, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		result[i].skip = 0;
		i++;
	}
	result[7].skip = 6;

	while (i < 8 + 8)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 8) * 16, 16, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		result[i].skip = 0;
		i++;
	}
	result[7 + 8].skip = 6;

	while (i < 8 + 16)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 16) * 16, 32, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		result[i].skip = 0;
		i++;
	}
	result[7 + 16].skip = 6;

	while (i < 8 + 24)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 24) * 16, 48, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		result[i].skip = 0;
		i++;
	}

	while (i < 8 + 32)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 32) * 16, 64, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8;
		result[i].skip = 0;
		i++;
	}

	while (i < 8 + 40 + 3)
	{
		result[i].texture = texture;
		result[i]._src = (SDL_Rect){(i - 40) * 16, 80, 16, 16};
		result[i].src = &(result[i]._src);
		result[i].cycle = 8 + 3;
		result[i].skip = 0;
		i++;
	}
	result[7 + 40 + 3].skip = 6;

	return (result);
}

int	fetch_box_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data *sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_box_sprite();


	*dst = &(sprite_arr[no * 8]);
	return (EXIT_SUCCESS);
}
