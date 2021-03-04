/***************************************************************************
 * FILENAME:    pacman_assets.h
 * DESCRIPTION: Header file for the fetch functions and enumns
 *
 * ENVIRONMENT:
 *     macOS High Sierra 10.13.6
 *     Visual Studio Code 1.52.1
 * AUTHORS:
 *     Kevin Colour
 * DATES:
 *     Created: 02Feb2021
***************************************************************************/

#ifndef PACMAN_ASSETS_H
# define PACMAN_ASSETS_H

# include "SDLX.h"

#define BOX_SIZE (16)

int	fetch_box_sprite(SDLX_Sprite_Data **dst, int no);

#endif
