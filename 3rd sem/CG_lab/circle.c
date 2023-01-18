#include <stdio.h>
#include <graphics.h>

void mid_point_circle(int h, int k, int radius) {
	int x = 0;
	int y = radius;

	int p = 1 - radius;
	while (x < y) {
		putpixel( x + h,  y + k, WHITE);
		putpixel(-x + h,  y + k, WHITE);
		putpixel( x + h, -y + k, WHITE);
		putpixel(-x + h, -y + k, WHITE);
		putpixel( y + h,  x + k, WHITE);
		putpixel(-y + h,  x + k, WHITE);
		putpixel( y + h, -x + k, WHITE);
		putpixel(-y + h, -x + k, WHITE);

		x++;
		if (p < 0) {
			p = p + (2 * x) + 1;
		} else {
			p = p + (2 * x) - (2 * y) + 1;
			y--;
		}
	}
}

int main(void) {
	int x_c, y_c, radius;
	printf("Enter x coordinate of center: ");
	scanf("%d", &x_c);
	printf("Enter y coordinate of center: ");
	scanf("%d", &y_c);
	printf("Enter radius: ");
	scanf("%d", &radius);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	mid_point_circle(x_c, y_c, radius);

	getchar();
	closegraph();
	return 0;
}
