#include <stdio.h>
#include <graphics.h>

void plot_points_ellipse(int center_x, int center_y, int x, int y) {
	putpixel(center_x + x, center_y + y, WHITE);
	putpixel(center_x - x, center_y + y, WHITE);
	putpixel(center_x + x, center_y - y, WHITE);
	putpixel(center_x - x, center_y - y, WHITE);
}

void mid_point_ellipse(int center_x, int center_y, int radius_x, int radius_y) {
	int radius_x_2     = radius_x * radius_x;
	int radius_y_2     = radius_y * radius_y;
	int two_radius_x_2 = 2 * radius_x_2;
	int two_radius_y_2 = 2 * radius_y_2;

	int x  = 0;
	int y  = radius_y;
	int px = 0;
	int py = two_radius_x_2 * y;

	// Plot the first set of points
	plot_points_ellipse(center_x, center_y, x, y);

	// Region 1
	int p = radius_y_2 - (radius_x_2 * radius_y) + (0.25 * radius_x_2);
	while (px < py) {
		x++;
		px += two_radius_y_2;
		if (p < 0)
			p += radius_y_2 + px;
		else {
			y--;
			py -= two_radius_x_2;
			p += radius_y_2 + px - py;
		}
		plot_points_ellipse(center_x, center_y, x, y);
	}

	// Region 2
	p = radius_y_2 * (x + 0.5) * (x + 0.5) +
	    radius_x_2 * (y - 1) * (y - 1) - radius_x_2 * radius_y_2;
	while (y > 0) {
		y--;
		py -= two_radius_x_2;
		if (p > 0)
			p += radius_x_2 - py;
		else {
			x++;
			px += two_radius_y_2;
			p += radius_x_2 - py + px;
		}
		plot_points_ellipse(center_x, center_y, x, y);
	}
}

int
main()
{
	int c_x, c_y, r_x, r_y;
	printf("Enter the x coordinate of center: ");
	scanf("%d", &c_x);
	printf("Enter the y coordinate of center: ");
	scanf("%d", &c_y);
	printf("Enter the radius in x coordinate: ");
	scanf("%d", &r_x);
	printf("Enter the radius in y coordinate: ");
	scanf("%d", &r_y);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	mid_point_ellipse(c_x, c_y, r_x, r_y);

	getchar();
	closegraph();
}
