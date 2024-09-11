/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:09 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:22:15 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_program(game, 1);
	game->window = mlx_new_window(game->mlx, game->point.x * TILE_SIZE,
			game->point.y * TILE_SIZE, "So Long");
	if (game->window == NULL)
		exit_program(game, 2);
	if (load_images(game) != 0)
		exit_program(game, 3);
	count_collectibles(game);
	game->player_direction = 4;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*file_name;
	char	**map;
	t_point	point;

	if (argc == 1)
		file_name = "Maps/map.ber";
	else if (argc == 2)
		file_name = ft_strjoin("Maps/", argv[1]);
	map = read_map_from_file(file_name);
	point = count_lines(file_name);
	if (argc == 2)
		free(file_name);
	valid_map(map, point);
	game.point = point;
	game.map = map;
	initialize_game(&game);
	render_map(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	exit_program(&game, 3);
	return (0);
}
