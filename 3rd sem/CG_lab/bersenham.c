#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void bla_line_high(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x_inc = 1;
	if (dx < 0) {
		x_inc = -1;
		dx    = -dx;
	}

	int p = 2 * dx - dy;

	int x = x1;
	int y = y1;

	while (y < y2) {
		putpixel(x, y, WHITE);

		y++;
		if (p > 0) {
			x += x_inc;
			p = p + 2 * dx - 2 * dy;
		} else {
			p = p + 2 * dx;
		}
	}
}

void bla_line_low(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int y_inc = 1;
	if (dy < 0) {
		y_inc = -1;
		dy    = -dy;
	}

	int p = 2 * dy - dx;

	int x = x1;
	int y = y1;

	while (x < x2) {
		putpixel(x, y, WHITE);

		x++;
		if (p > 0) {
			y += y_inc;
			p = p + 2 * dy - 2 * dx;
		} else {
			p = p + 2 * dy;
		}
	}
}

void bla_line(int x1, int y1, int x2, int y2) {
	if (abs(y2 - y1) < abs(x2 - x1)) {
		if (x1 > x2)
			bla_line_low(x2, y2, x1, y1);
		else
			bla_line_low(x1, y1, x2, y2);
	} else {
		if (y1 > y2)
			bla_line_high(x2, y2, x1, y1);
		else
			bla_line_high(x1, y1, x2, y2);
	}
}

int main(void) {
	int x1, x2, y1, y2;
	printf("Enter x1: ");
	scanf("%d", &x1);
	printf("Enter y1: ");
	scanf("%d", &y1);
	printf("Enter x2: ");
	scanf("%d", &x2);
	printf("Enter y2: ");
	scanf("%d", &y2);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	bla_line(x1, y1, x2, y2);

	getchar();
	closegraph();
	return 0;
}
