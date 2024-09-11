/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:22 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:22:25 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->point.y)
	{
		x = -1;
		while (++x < game->point.x)
		{
			if (game->map[y][x] == '1')
				render_wall(game, x, y);
			else if (game->map[y][x] == '0')
				render_floor(game, x, y);
			else if (game->map[y][x] == 'E')
				render_exit(game, x, y);
			else if (game->map[y][x] == 'C')
				render_collectable(game, x, y);
			else if (game->map[y][x] == 'P')
				render_player(game, x, y);
		}
	}
	return (0);
}

void	load_image(t_game *game, int index, char *filename)
{
	int	width;
	int	height;

	game->images[index] = mlx_xpm_file_to_image(game->mlx,
			filename, &width, &height);
}

int	check_images_loaded(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		if (game->images[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}

int	load_images(t_game *game)
{
	load_image(game, 0, "images/wall0.xpm");
	load_image(game, 1, "images/bg.xpm");
	load_image(game, 2, "images/exit0.xpm");
	load_image(game, 3, "images/collect.xpm");
	load_image(game, 4, "images/tank_u.xpm");
	load_image(game, 5, "images/tank_d.xpm");
	load_image(game, 6, "images/tank_r.xpm");
	load_image(game, 7, "images/tank_l.xpm");
	load_image(game, 8, "images/exit1.xpm");
	return (check_images_loaded(game));
}
