#include "utils.h"
#include "libft.h"
#include "raycast.h"

// TODO 入力に不備があった場合のバリデーションしてない

static int	is_valid_rgb(int value)
{
	return (value >= 0 && value <= 255);
}
static int	convert_rgb_hex(int *rgb_colors)
{
	int	hex_color;
	int	i;

	i = 0;
	while(i < 3)
	{
		hex_color = hex_color * 256 + rgb_colors[i];
		i++;
	}
	return (hex_color);
}

static int	parse_rgb_values(char **rgb, int *rgb_colors)
{
	int	i;

	i = 0;
	while(i < 3)
	{
		rgb_colors[i] = ft_atoi(rgb[i]);
		if (!is_valid_rgb(rgb_colors[i]))
		{
			write(2, "Error : color range\n", 20);
			return (-1);
		}
		i++;
	}
	return (0);
}
static void free_char_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != NULL)
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

int		parse_color(char *line)
{
	char	**rgb;
	int		rgb_color[3];

	rgb = ft_split(line, ',');
	if (parse_rgb_values(rgb, rgb_color) != 0)
	{
		free_char_rgb(rgb);
		exit(1);
	}
	free_char_rgb(rgb);
	printf("color: %d %d %d\n", rgb_color[0], rgb_color[1], rgb_color[2]);
	return (convert_rgb_hex(rgb_color));
}