/*
 * SI_logic.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_logic.h"

Xint8 ship_hit_projectile(int i)
{
	if(projectiles_map[i][SHIP_Y] == 2)
	{
		projectiles_map[i][SHIP_Y] = 0;
		projectiles_of_invaders_num[i]--;
		return 1;
	}
	else
		return 0;
}

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

	//Did new leftmost of rightmost part of ship hit a projectile
	if(ship_hit_projectile(spaceship_x-1) || ship_hit_projectile(spaceship_x+1))
	{
		if(--lives == 0)
			game_over = 1;
	}

	draw_ship(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, spaceship_x, SHIP_Y);
}

Xint8 projectile_hit_invader(int i, int j)
{
	int n;

	/* Check if projectile hit left, center or right part of invader */
	for(n = -1; n < 2; n++)
	{
		if(invaders_map[i+n][j])
		{
			invaders_map[i+n][j] = 0;
			erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, i+n, j);
			invaders_num--;
			projectiles_of_ship_num[i]--;



			xil_printf("\nPROJECTILE HIT INVADER\n\r");
			return 1;
		}
	}
	return 0;
}




/*


    	{
			//draw_projectile(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, spaceship_x, SHIP_Y - 1);
				gghjkjhgfdrfghjkjhgftggjjjkkkklk
    	}
    }
}*/



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
		invaders_map[80][j+INVADER_INIT_ROW] = 1;
		invaders_map[85][j+INVADER_INIT_ROW] = 1;
		invaders_map[90][j+INVADER_INIT_ROW] = 1;
		invaders_map[95][j+INVADER_INIT_ROW] = 1;
		invaders_map[100][j+INVADER_INIT_ROW] = 1;
		invaders_map[105][j+INVADER_INIT_ROW] = 1;

	}
}

void generate_init_blocks_position()
{
	projectiles_map[10][SHIP_Y-2] = 3;
	projectiles_map[30][SHIP_Y-2] = 3;
	projectiles_map[50][SHIP_Y-2] = 3;
	projectiles_map[70][SHIP_Y-2] = 3;
	projectiles_map[90][SHIP_Y-2] = 3;
}
