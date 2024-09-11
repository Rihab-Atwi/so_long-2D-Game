/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:15 by ratwi             #+#    #+#             */
/*   Updated: 2024/08/11 15:21:21 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	count_lines(char *file)
{
	int		count;
	int		fd;
	char	*line;
	t_point	point;

	count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		point.x = strlen(line);
		free(line);
	}
	close(fd);
	point.y = count;
	return (point);
}

char	**copy_map(char **map, t_point size)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = malloc((size.y + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_copy[size.y] = NULL;
	while (i < size.y)
	{
		map_copy[i] = malloc((size.x + 1) * sizeof(char));
		if (!map_copy[i])
		{
			j = -1;
			while (++j < i)
				free(map_copy[j]);
			free(map_copy);
			return (NULL);
		}
		ft_strcpy(map_copy[i], map[i]);
		i++;
	}
	return (map_copy);
}

char	**read_map_from_file(char *file)
{
	int		fd;
	char	*line;
	t_point	point;
	char	**store;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	point = count_lines(file);
	store = (char **) malloc (sizeof(char *) * (point.y + 1));
	if (!store)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		store[i++] = ft_strdup(line);
		free(line);
	}
	store[point.y] = NULL;
	close(fd);
	return (store);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}
