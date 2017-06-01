/*
 * SI_logic.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_logic.h"


void move_spaceship(Xuint8 *dir)
{
	erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, spaceship_x, SHIP_Y);
	if(*dir == 0)
	{
		if(spaceship_x == MAX_SHIP_X)
		{
			spaceship_x--;
			*dir = 1;
		}
		else
			spaceship_x++;
	}
	else if(spaceship_x == MIN_SHIP_X)
	{
		spaceship_x++;
		*dir = 0;
	}
	else
		spaceship_x--;


	draw_ship(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, spaceship_x, SHIP_Y);
}



void generate_init_invaders_positions()
{
	int j;

	for(j = 0; j < INIT_ROWS + level - 1; j++)	//Generate positions for invaders
	{
		invaders_map[5][j+INVADER_INIT_ROW] = 1;
		invaders_map[10][j+INVADER_INIT_ROW] = 1;
		invaders_map[15][j+INVADER_INIT_ROW] = 1;
		invaders_map[20][j+INVADER_INIT_ROW] = 1;
		invaders_map[25][j+INVADER_INIT_ROW] = 1;
		invaders_map[30][j+INVADER_INIT_ROW] = 1;
		invaders_map[35][j+INVADER_INIT_ROW] = 1;
		invaders_map[40][j+INVADER_INIT_ROW] = 1;
		invaders_map[45][j+INVADER_INIT_ROW] = 1;
		invaders_map[50][j+INVADER_INIT_ROW] = 1;
		invaders_map[55][j+INVADER_INIT_ROW] = 1;
		invaders_map[60][j+INVADER_INIT_ROW] = 1;
		invaders_map[65][j+INVADER_INIT_ROW] = 1;
		invaders_map[70][j+INVADER_INIT_ROW] = 1;
		invaders_map[75][j+INVADER_INIT_ROW] = 1;



	}
}


