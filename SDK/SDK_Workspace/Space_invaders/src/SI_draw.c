/*
 * SI_draw.c
 *
 *  Created on: 16.06.2015.
 *      Author: Standzi, Marko, Dva geja (Urosko i Milan GAY)
 */

#include "SI_draw.h"
#include <math.h>

void draw_square(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 0 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k-2), 0x00A0A000);
		PUT_TO_FSL((j*(640/8) + k-1), 0x0A0A0A0A);
		PUT_TO_FSL((j*(640/8) + k+0), 0xA0A0A0A0);
		PUT_TO_FSL((j*(640/8) + k+1), 0x0A0A0A0A);
		PUT_TO_FSL((j*(640/8) + k+2), 0x00A0A000);
	}
}

void draw_invaderX(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	int i, j, k;
	k = x_crdnt;

	if(1)
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x11111111);//VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000110);
				PUT_TO_FSL((i+0), 0x11111111);//VGA1_PERIPH_MEM_mWriteMemory((i+0), 0x00000000);
				PUT_TO_FSL(i+1,0x11111111);//VGA1_PERIPH_MEM_mWriteMemory((i+1), 0x01100000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x11111111); //VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000001);
				PUT_TO_FSL((i+0), 0x11111111);//PUT_TO_FSL((i+0), 0x10000001);
				PUT_TO_FSL((i+1), 0x11111111);//PUT_TO_FSL((i+1), 0x10000000);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);//VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
					PUT_TO_FSL((i-1), 0x11111111);
					PUT_TO_FSL((i+0), 0x11111111);
					PUT_TO_FSL((i+1), 0x11111111);
						}

			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
					PUT_TO_FSL((i-1), 0x11111111);
					PUT_TO_FSL((i+0), 0x11111111);
					PUT_TO_FSL((i+1), 0x11111111);
						}
			else {
					PUT_TO_FSL((i-1), 0x11111111);
					PUT_TO_FSL((i+0), 0x11111111);
					PUT_TO_FSL((i+1), 0x11111111);
						}
		}
	}
}





void draw_invader(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	if(level%2 == 0)
		draw_invaderX(BaseAddress, x_crdnt, y_crdnt, type);
	else
		draw_invaderX(BaseAddress, x_crdnt, y_crdnt, type);
}

void draw_ship(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int i, k, x, y;

	for (y = 2 + 32*y_crdnt; y < 14 + 32*y_crdnt; y++)
	{
		for(k = -7; k < 7; k++){
			x = x_crdnt + k;
			i = y*(640/8) + x;
			PUT_TO_FSL(i, 0x11111111);
		}
	}

}


void erase_square(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int i, x, y, k;

	for (y = 0 + 32*y_crdnt; y < 32 + 32*y_crdnt; y++)
	{
		for(k = -7; k < 7; k++){
			x = x_crdnt + k;
			i = y*(640/8) + x;
			PUT_TO_FSL(i, 0x00000000);
		}
	}
}

void clear_graphics_screen(Xuint32 BaseAddress)
{
	int i;
	for (i = 0; i < 9600*4; i++){
	    PUT_TO_FSL(i, 0x00000000);
	}
}



void draw_ball(int x, int y, int x_prev, int y_prev)
{
	//Strahinjinja fja
	/*int k;
	int j;

	int r = 50; // radius
	int ox = 100, oy = 100; // origin

	for (k = -r; k < r ; k++)
	{
	    int height = (int)sqrt(r * r - k * k);

	    for (j = -height; j < height; j++)
	    	PUT_TO_FSL(((oy+j)*80 + k + ox), 0x11111111);
	}*/


	PUT_TO_FSL(((y_prev-6)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-5)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-4)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-3)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-2)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-1)*80 + x_prev), 0x11111111);
	PUT_TO_FSL((y_prev*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+1)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+2)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+3)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+4)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+5)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+6)*80 + x_prev), 0x11111111);

	PUT_TO_FSL(((y_prev-6)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-5)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-4)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-3)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-2)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-1)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL((y_prev*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+1)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+2)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+3)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+4)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+5)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+6)*80 + x_prev+1), 0x11111111);

	PUT_TO_FSL(((y-6)*80 + x), 0x00003333); //gore levo
	PUT_TO_FSL(((y-5)*80 + x), 0x00333333);
	PUT_TO_FSL(((y-4)*80 + x), 0x03333333);
	PUT_TO_FSL(((y-3)*80 + x), 0x33333333);
	PUT_TO_FSL(((y-2)*80 + x), 0x33333333);
	PUT_TO_FSL(((y-1)*80 + x), 0x33333333);
	PUT_TO_FSL((y*80 + x), 0x33333333);
	PUT_TO_FSL(((y+1)*80 + x), 0x33333333); //dole levo
	PUT_TO_FSL(((y+2)*80 + x), 0x33333333);
	PUT_TO_FSL(((y+3)*80 + x), 0x33333333);
	PUT_TO_FSL(((y+4)*80 + x), 0x03333333);
	PUT_TO_FSL(((y+5)*80 + x), 0x00333333);
	PUT_TO_FSL(((y+6)*80 + x), 0x00003333);

	PUT_TO_FSL(((y-6)*80 + x+1), 0x33330000); //gore desno
	PUT_TO_FSL(((y-5)*80 + x+1), 0x33333300);
	PUT_TO_FSL(((y-4)*80 + x+1), 0x33333330);
	PUT_TO_FSL(((y-3)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y-2)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y-1)*80 + x+1), 0x33333333);
	PUT_TO_FSL((y*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+1)*80 + x+1), 0x33333333); //dole desno
	PUT_TO_FSL(((y+2)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+3)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+4)*80 + x+1), 0x33333330);
	PUT_TO_FSL(((y+5)*80 + x+1), 0x33333300);
	PUT_TO_FSL(((y+6)*80 + x+1), 0x33330000);
}




