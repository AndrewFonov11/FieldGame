// Field game source code version 1.8.1 (for GitHub)

// The GitHub version of the game is distributed under the GNU GPL v3.0 license

// Additional information in the file INFO_GH.txt

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	srand(time(NULL));
	char mas[20][41];
	int i;
	int jx = 0,jy = 0;
	int gx = 15,gy = 10;
	int ax = 4,ay = 16;
	int ix = 20,iy = 3;
	int px = 7,py = 6;
	int ppx = 2, ppy = 4;
	int kx = 1, ky = 1;
	int cx = 30,cy = 15;
	int yx = 29,yy = 13;
	int hp = 1,xp = 0;
	int dosta = 0,dostb = 0;
	int tx = 0,ty = 0;
	int dx = 0,dy = 0;
	int vx = 0,vy = 0;
	int jj = 0,kk = 0;
	int rnd;
	int pr = 0;
	int disx;
	int disy;
	int ox,oy;
	int ex,ey;
	int qx,qy;
	int rx,ry;
	int yyx,yyy;
	char key;
	do
	{
		sprintf(mas[0], "########################################");
		for (i = 1; i < 19; i++)
			sprintf(mas[i], "#--------------------------------------#");
		sprintf(mas[19], "########################################");
		mas[gy][gx] = '&';
		mas[ay][ax] = '+';
		mas[iy][ix] = '*';
		mas[py][px] = '~';
		mas[ty][tx] = '!';
		mas[ppy][ppx] = '/';
		mas[yy][yx] = '`';
		mas[ky][kx] = 'P';
		mas[cy][cx] = '%';
		mas[dy][dx] = 'T';
		mas[vy][vx] = '^';
		mas[jy][jx] = '0';
		system("cls");
		for (i = 0; i < 20; i++)
			printf("%s\n", mas[i]);
		printf("\nXP: %d",xp);
		printf("\nHP: %d",hp);
		disx = gx - ax;
		disy = gy - ay;
		printf("\nDistance X:%d Distance Y:%d", disx, disy);
		if ((jj == 0) && (kk == 0))
		{
			printf("\nNo weapons");
		}
		else
		{
			printf("\nThere are weapons");
		}
		printf("\nField game v 1.8.1 (for GitHub)");
		key = getch();
		ox = gx;
		oy = gy;
		ex = ix;
		ey = iy;
		qx = ppx;
		qy = ppy;
		rx = cx;
		ry = cy;
		yyx = yx;
		yyy = yy;
		if (key == 'w') gy--;
		if (key == 's') gy++;
		if (key == 'a') gx--;
		if (key == 'd') gx++;
		if ((key == 'q') && (xp > 3)) hp++,xp-=3;
		if ((key == 't') && (xp > 5))
		{
			tx = ox + 1;
			ty = oy + 1;
			xp-=5;
		}
		if ((key == 'r') && (xp > 14))
		{
			dx = ox;
			dy = oy - 1;
			xp-=14;
		}
		if ((key == 'e') && (xp > 4) && (mas[vy][vx] != '0'))
		{
			xp-=4;
			vx = 0,vy = 0;
		}
		if ((key == 'h') && (xp > 17) && (pr == 0))
		{
			pr = 1;
			xp-=17;
			printf("\nYou have tamed a sheep");
			key = getch();
		}
		if ((key == 'j') && (xp > 10) && (jj == 0))
		{
			xp-=10;
			jj = 1;
		}
		if ((key == 'k') && (xp > 25) && (kk == 0))
		{
			xp-=25;
			kk = 1;
		}
		if (key == 'i')
		{
			system("cls");
			printf("Key:");
			printf("\n'w' - forward");
			printf("\n's' - backward");
			printf("\n'a' - left");
			printf("\n'd' - right");
			printf("\n'q' - buy 1 HP");
			printf("\n't' - buy and set a trap");
			printf("\n'r' - buy and set a tnt");
			printf("\n'e' - clear the explosion site");
			printf("\n'h' - tame a sheep");
			printf("\n'j' - buy a simple weapon");
			printf("\n'k' - buy strong weapons");
			printf("\n'x' - end");
			printf("\nSymbols:");
			printf("\n & - player");
			printf("\n + - bonus");
			printf("\n ! - trap");
			printf("\n * - junior opponent");
			printf("\n / - senior opponent");
			printf("\n ~ - portal");
			printf("\n # - wall");
			printf("\n - - field");
			printf("\n P - patrol");
			printf("\n T - tnt");
			printf("\n ^ - site of the last explosion");
			printf("\n %% - sheep");
			printf("\n ` - ghost");
			printf("\n 0 - hidden area");
			printf("\nAdditional information in the INFO_GH.txt file");
			key = getch();
		}
		if (key == 'x') hp = 0;
		if ((key != 'w') && (key != 's') && (key != 'a') && (key != 'd') && (key != 'q') && (key != 't') && (key != 'x') && (key != 'i') && (key != 'r') && (key != 'e') && (key != 'h') && (key != 'j') && (key != 'k'))
		{
			printf("\nWrong action: %c", key);
			key = getch();
		}
		if (mas[gy][gx] == '#')
		{
			gx = ox;
			gy = oy;
			hp--;
			printf("\nYou can't go there");
			key = getch();
		}
		if (pr == 1)
		{	
			if ((cx == ix) && (cy == iy))
			{
				ix = rand() * 1.0 / RAND_MAX * 38 + 1;
				iy = rand() * 1.0 / RAND_MAX * 18 + 1;
				xp+=3;
				printf("\nThe sheep caught the prey");
				key = getch();
			}
			if ((cx == ppx) && (cy == ppy))
			{
				ppx = rand() * 1.0 / RAND_MAX * 38 + 1;
				ppy = rand() * 1.0 / RAND_MAX * 18 + 1;
				xp+=4;
				printf("\nThe sheep caught the prey");
				key = getch();
			}
		}
		if (mas[gy][gx] == 'T')
		{
			printf("\nSomething was set on fire...");
			key = getch();
			hp = 0;
		}
		if ((gy == ay) && (gx == ax))
		{
			ax = rand() * 1.0 / RAND_MAX * 38 + 1;
			ay = rand() * 1.0 / RAND_MAX * 18 + 1;
			rnd = rand() * 1.0 / RAND_MAX * 8 + 1;
			if (rnd == 8) xp += 2;
			else xp++;
		}
		if ((gy == py) && (gx == px))
		{
			px = rand() * 1.0 / RAND_MAX * 38 + 1;
			py = rand() * 1.0 / RAND_MAX * 18 + 1;
			gx = rand() * 1.0 / RAND_MAX * 38 + 1;
			gy = rand() * 1.0 / RAND_MAX * 18 + 1;
		}
		rnd = rand() % 4 + 1;
		if (rnd == 1)
		{
			ix++;
		}
		if (rnd == 2)
		{
			ix--;
		}
		if (rnd == 3)
		{
			iy++;
		}
		if (rnd == 4)
		{
			iy--;
		}
		if (mas[iy][ix] == '#')
		{
			ix = ex;
			iy = ey;
		}
		if (mas[iy][ix] == '!')
		{
			ix = rand() * 1.0 / RAND_MAX * 38 + 1;
			iy = rand() * 1.0 / RAND_MAX * 18 + 1;
			xp++;
			printf("\nThe trap worked");
			key = getch();
		}
		if (mas[iy][ix] == 'T')
		{
			ix = rand() * 1.0 / RAND_MAX * 38 + 1;
			iy = rand() * 1.0 / RAND_MAX * 18 + 1;
			xp+=4;
			vx = dx,vy = dy;
			dx = 0,dy = 0;
			printf("\nThe tnt worked");
			key = getch();
		}
		if ((gy == iy) && (gx == ix))
		{
			if (jj == 1)
			{
				printf("\nWeapons used");
				key = getch();
				jj = 0;
			}
			else
			{
				hp--;
				if (xp != 0)
				{
					xp--;
				}
				printf("\nDamage");
				key = getch();
			}
			ix = ex;
			iy = ey;
		}
		rnd = rand() % 4 + 1;
		if (rnd == 1)
		{
			ppx++;
		}
		if (rnd == 2)
		{
			ppx--;
		}
		if (rnd == 3)
		{
			ppy++;
		}
		if (rnd == 4)
		{
			ppy--;
		}
		if (mas[ppy][ppx] == '#')
		{
			ppx = qx;
			ppy = qy;
		}
		if (mas[ppy][ppx] == '!')
		{
			ppx = rand() * 1.0 / RAND_MAX * 38 + 1;
			ppy = rand() * 1.0 / RAND_MAX * 18 + 1;
			xp+=2;
			printf("\nThe trap worked");
			key = getch();
		}
		if (mas[ppy][ppx] == 'T')
		{
			ppx = rand() * 1.0 / RAND_MAX * 38 + 1;
			ppy = rand() * 1.0 / RAND_MAX * 18 + 1;
			xp+=6;
			vx = dx,vy = dy;
			dx = 0,dy = 0;
			printf("\nThe tnt worked");
			key = getch();
		}
		if ((gy == ppy) && (gx == ppx))
		{
			if (kk == 1)
			{
				printf("\nWeapons used");
				key = getch();
				kk = 0;
			}
			else
			{ 
				if (hp > 3)
				{
					hp-=4;
				}
				else hp--;
				if (xp > 5)
				{
					xp-=6;
				}
				printf("\nDamage");
				key = getch();
			}
			ppx = qx;
			ppy = qy;
		}
		if (kx != 38) kx++;
		else
		{
			kx = 1;
			if (ky != 18) ky++;
			else
			{
				ky = 1;
			}
		}
		if ((gy == ky) && (gx == kx))
		{
			printf("\nStop!");
			key = getch();
			hp = 0;
		}
		if ((ppy == ky) && (ppx == kx))
		{
			ppx = rand() * 1.0 / RAND_MAX * 38 + 1;
			ppy = rand() * 1.0 / RAND_MAX * 18 + 1;
		}
		if ((ay == ky) && (ax == kx))
		{
			ax = rand() * 1.0 / RAND_MAX * 38 + 1;
			ay = rand() * 1.0 / RAND_MAX * 18 + 1;
		}
		if ((mas[ky][kx] == '!') && (xp > 7))
		{
			xp-=8;
		}
		if ((mas[ky][kx] == 'T') && (xp > 20))
		{
			xp-=21;
		}
		if (mas[ky][kx] == '!')
		{
			tx = 0, ty = 0;
			printf("\nIt's better not to disturb the patrol");
			key = getch();
		}
		if (mas[ky][kx] == 'T')
		{
			dx = 0, dy = 0;
			printf("\nIt's better not to disturb the patrol");
			key = getch();
		}
		if ((iy == ky) && (ix == kx))
		{
			ix = rand() * 1.0 / RAND_MAX * 38 + 1;
			iy = rand() * 1.0 / RAND_MAX * 18 + 1;
		}
		if ((cy == ky) && (cx == kx) && (pr == 0))
		{
			cx = rand() * 1.0 / RAND_MAX * 38 + 1;
			cy = rand() * 1.0 / RAND_MAX * 18 + 1;
		}
		if ((cy == ky) && (cx == kx) && (pr == 1))
		{
			cx = rand() * 1.0 / RAND_MAX * 38 + 1;
			cy = rand() * 1.0 / RAND_MAX * 18 + 1;
			pr = 0;
			printf("\nThe patrol doesn't like sheep");
			key = getch();
		}
		rnd = rand() % 4 + 1;
		if (rnd == 1)
		{
			cx++;
		}
		if (rnd == 2)
		{
			cx--;
		}
		if (rnd == 3)
		{
			cy++;
		}
		if (rnd == 4)
		{
			cy--;
		}
		if (mas[cy][cx] == '#')
		{
			cx = rx;
			cy = ry;
		}
		if (mas[cy][cx] == 'T')
		{
			cx = rand() * 1.0 / RAND_MAX * 38 + 1;
			cy = rand() * 1.0 / RAND_MAX * 18 + 1;
			vx = dx,vy = dy;
			dx = 0,dy = 0;
			printf("\nThe tnt worked");
			key = getch();
			if (pr == 1)
			{
				printf("\nYour pet is in trouble!");
				key = getch();
				xp = 0;
				pr = 0;
			}
		}
		rnd = rand() % 4 + 1;
		if (rnd == 1)
		{
			yx++;
		}
		if (rnd == 2)
		{
			yx--;
		}
		if (rnd == 3)
		{
			yy++;
		}
		if (rnd == 4)
		{
			yy--;
		}
		if (mas[yy][yx] == '#')
		{
			yx = yyx;
			yy = yyy;
		}
		if ((gy == yy) && (gx == yx))
		{
			printf("\nThere's something weird here");
			key = getch();
			yx = rand() * 1.0 / RAND_MAX * 38 + 1;
			yy = rand() * 1.0 / RAND_MAX * 18 + 1;
			jj = 0;
			kk = 0;
			xp = 0;
		}
		if ((gx > 39) && (dosta == 0))
		{
			printf("\nAchievement: 'On the other side of the wall'");
			key = getch();
			dosta++;
			xp+=50;
		}
		if ((mas[iy][ix] == '!') && (mas[ppy][ppx] == '!') && (dostb == 0))
		{
			printf("\nAchievement: 'Two beasts in one trap'");
			key = getch();
			dostb++;
			xp+=70;
		}
		if (hp == 0)
		{
			system("cls");
			printf("Game Over!");
		}
	}
	while (hp != 0);
	return 0;
}