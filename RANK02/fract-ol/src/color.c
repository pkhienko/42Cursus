#include "../include/fractol.h"

void	shift_color(t_fractol *f)
{
	static int	cur = 0;
	static int	colors[] = {WHITE, RED, BLUE, GREEN, SKY_BLUE, SEA_WAVE,
		FOREST_GREEN, SUNSET_ORANGE, GOLDEN_YELLOW, STAR_WHITE, VOID_BLACK,
		NEBULA_PINK, MIDNIGHT_BLUE, COSMIC_PURPLE, ACID_GREEN, CYAN_FLASH,
		VIOLET_HAZE, ORANGE_CRUSH, FLAMINGO_PINK, BLAZE_RED, EMBER_RED,
		LAVA_GLOW, FIRE_YELLOW, VOLCANIC_ORANGE, CREAM, PEACH, LAVENDER,
		BABY_BLUE, MINT_GREEN};

	cur = (cur + 1) % (sizeof(colors) / sizeof(colors[0]));
	f->color = colors[cur];
}

int	get_color(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * \
		((color2 >> 16) & 0xFF) * 5);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * \
		((color2 >> 8) & 0xFF) * 5);
	b = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}
