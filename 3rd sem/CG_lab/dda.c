#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void dda_line(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	float x_inc = (float)dx / (float)steps;
	float y_inc = (float)dy / (float)steps;

	float x = (float)x1;
	float y = (float)y1;
	putpixel((int)x, (int)y, WHITE);

	for (int i = 0; i < steps; i++) {
		x += x_inc;
		y += y_inc;
		putpixel((int)x, (int)y, WHITE);
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

	dda_line(x1, y1, x2, y2);

	getchar();
	closegraph();

	return 0;
}
