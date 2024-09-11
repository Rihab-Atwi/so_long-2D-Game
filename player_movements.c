/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:22:01 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:22:03 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_new_position(int keycode, t_point *new,
		t_point player, t_game *game)
{
	new->x = player.x;
	new->y = player.y;
	if (keycode == 119)
	{
		new->y--;
		game->player_direction = TANK_UP;
	}
	else if (keycode == 115)
	{
		new->y++;
		game->player_direction = TANK_DOWN;
	}
	else if (keycode == 97)
	{
		new->x--;
		game->player_direction = TANK_LEFT;
	}
	else if (keycode == 100)
	{
		new->x++;
		game->player_direction = TANK_RIGHT;
	}
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	return (new_y >= 0 && new_y < game->point.y && new_x >= 0
		&& new_x < game->point.x);
}

void	handle_move(t_game *game, t_point player, t_point new)
{
	char	new_pos;

	new_pos = game->map[new.y][new.x];
	if (new_pos == 'C')
		game->collectables--;
	game->map[player.y][player.x] = '0';
	game->map[new.y][new.x] = 'P';
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	if (new_pos == 'E' && game->collectables == 0)
	{
		write(1, "YOU WON!\n", 9);
		exit_program(game, 5);
	}
	render_map(game);
}

int	move_player(int keycode, t_game *game)
{
	t_point	player;
	t_point	player_pos;
	t_point	new;
	char	new_pos;

	player_pos = find_player_position(game->map);
	if (player_pos.x == -1 || player_pos.y == -1)
		return (0);
	player.x = player_pos.x;
	player.y = player_pos.y;
	calculate_new_position(keycode, &new, player, game);
	if (is_valid_move(game, new.x, new.y))
	{
		new_pos = game->map[new.y][new.x];
		if (new_pos == '0' || new_pos == 'C'
			|| (new_pos == 'E' && game->collectables == 0))
			handle_move(game, player, new);
	}
	render_map(game);
	return (0);
}
