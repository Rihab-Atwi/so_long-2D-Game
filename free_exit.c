/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:23:11 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:23:13 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		if (game->images[i] != NULL)
		{
			mlx_destroy_image(game->mlx, game->images[i]);
			game->images[i] = NULL;
		}
		i++;
	}
}

void	exit_program(t_game *game, int i)
{
	if (i >= 1)
		free_2d_array(game->map);
	if (i >= 2)
		mlx_destroy_window(game->mlx, game->window);
	if (i >= 3)
		free_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
