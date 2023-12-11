/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:36 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:15:17 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_from_file(t_cube *maps, char *file)
{
	int		i;
	char	**map;

	i = 1;
	maps->fd = open(file, O_RDONLY);
	if (maps->fd < 0)
	{
		ft_putstr_fd("Error Map Read\n", 2);
		exit(1);
	}
	if (i > 0)
	{
		i = read(maps->fd, maps->str, 4096);
		if (i == -1 || i == 0)
		{
			ft_putstr_fd("Error Map Read\n", 2);
			exit(1);
		}
	}
	maps->str[i] = '\0';
	map = ft_split(maps->str, '\n');
	set_map(maps, map);
	ft_free(map);
}

int	len_of_2arr(t_cube *maps)
{
	int	i;

	i = 0;
	while (maps->map[i])
		i++;
	return (i);
}

void	read_only_map(t_cube *maps)
{
	int	i;
	int	j;

	maps->map_size = 0;
	i = maps->maps_start;
	j = 0;
	while (maps->map[i++])
		j++;
	maps->only_map = ft_calloc(j + 1, sizeof(char *));
	if (!maps->only_map)
		return ;
	i = maps->maps_start;
	j = 0;
	while (maps->map[i])
	{
		if (check_nl(maps->map[i]))
			maps->only_map[j++] = maps->map[i];
		i++;
	}
	maps->map_size = j;
	maps->only_map[j] = NULL;
}

int	check_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

void	read_only_textures(t_cube *maps)
{
	int	i;
	int	j;

	maps->maps_start = 0;
	i = 0;
	j = 0;
	maps->textures = ft_calloc(8, sizeof(char *));
	if (!maps->textures)
		return ;
	while (j < 6 && maps->map[i])
	{
		if (check_nl(maps->map[i]))
			maps->textures[j++] = maps->map[i];
		maps->maps_start++;
		i++;
	}
	maps->textures[j] = NULL;
}
