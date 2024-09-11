/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:30 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:22:34 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_program(game, 4);
	move_player(keycode, game);
	return (0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_program(game, 4);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
}
