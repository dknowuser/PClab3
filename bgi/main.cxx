// File: eyes.cpp
// Written by Grant Macklem
//      Grant.Macklem@Colorado.EDU
//              2:00 PM Recitation
// Last modified Nov 22, 1998
// Flicker-free eyes!

/*******************************************************************************
* eyes.exe  Flicker-free, mouse-following, customizably-colored eyes.
* Copyright (C) 1998 Grant Macklem
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* You may contact me, the author by emailing Grant.Macklem@Colorado.EDU
*******************************************************************************/

#include "graphics.h"
//sin^2(x) + cos^3(x)
//pi/2 - 5pi
#include <iostream>
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>    

const unsigned int Width = 640;
const unsigned int Height = 480;
const float Pi = 3.1415926535897932384626433832795;


using namespace std;

int APIENTRY WinMain
( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	initwindow(Width, Height);
	setgraphmode(6);

	//Рисуем оси
	linesettingstype LineStyle;
	LineStyle.linestyle = SOLID_LINE;
	LineStyle.thickness = THICK_WIDTH;
	setcolor(9);

	//Рисуем Ox
	moveto(0, Height / 2);
	lineto(Width, Height / 2);

	//Размечаем оси
	setcolor(15);
	settextstyle(SMALL_FONT, HORIZ_DIR, NULL);

	//Oy
	outtextxy(1, 0, "1");
	outtextxy(1, 120, "0.5");
	outtextxy(1, 230, "0");
	outtextxy(1, 360, "-0.5");
	outtextxy(1, 460, "-1");

	//Ox
	outtextxy(1, 241, "Pi/2");
	outtextxy(72, 241, "Pi");
	outtextxy(143, 241, "3Pi/2");
	outtextxy(214, 241, "2Pi");
	outtextxy(285, 241, "5Pi/2");
	outtextxy(356, 241, "3Pi");
	outtextxy(427, 241, "7Pi/2");
	outtextxy(498, 241, "4Pi");
	outtextxy(569, 241, "9Pi/2");
	outtextxy(618, 241, "5Pi");

	//Цены деления по X и по Y
	float Cx = (5 * Pi - Pi/2.) / (float)440;
	float Cy = 2. / (float)460;

	//Текущее значение аргумента
	float x = Pi / 2.;

	//Максимальное значение
	float Max = -2;

	setcolor(12);
	moveto(0, Height / 2 - (sin(x)*sin(x) + cos(x)*cos(x)*cos(x)) / Cy);
	for (unsigned int i = 0; i < Width - 10; i++, x += Cx)
	{
		//Вычисляем значение функции
		float Value = sin(x)*sin(x) + cos(x)*cos(x)*cos(x);
		unsigned int Position = Height / 2;
		Position -= (unsigned int)(Value / Cy);

		if (Value > Max)
			Max = Value;

		lineto(i + 1, Position);
	};

	//Выводим максимальное значение
	setcolor(15);
	rectangle(500, 400, 629, 469);
	outtextxy(510, 410, "Максимум:");

	char cMax[10];
	gcvt(Max, 1, cMax);

	outtextxy(560, 410, cMax);

	getch();
}

