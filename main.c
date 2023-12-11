/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:15:27 by yberrim           #+#    #+#             */
/*   Updated: 2023/12/06 09:31:13 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cf(t_cube *map, char **str)
{
	if ((ft_strncmp(str[0], "C", 3) == 0) && !map->c)
	{
		map->c = ft_strdup(str[1]);
		map->cnt++;
	}
	else if ((ft_strncmp(str[0], "F", 3) == 0) && !map->f)
	{
		map->f = ft_strdup(str[1]);
		map->cnt++;
	}
}

void	texture_store(t_cube *map, char **str)
{
	if ((ft_strncmp(str[0], "NO", 3) == 0) && !map->no)
	{
		map->no = ft_strdup(str[1]);
		map->cnt++;
	}
	else if ((ft_strncmp(str[0], "SO", 3) == 0) && !map->so)
	{
		map->so = ft_strdup(str[1]);
		map->cnt++;
	}
	else if ((ft_strncmp(str[0], "WE", 3) == 0) && !map->we)
	{
		map->we = ft_strdup(str[1]);
		map->cnt++;
	}
	else if ((ft_strncmp(str[0], "EA", 3) == 0) && !map->ea)
	{
		map->ea = ft_strdup(str[1]);
		map->cnt++;
	}
	set_cf(map, str);
}

int	check_texter(t_cube *map)
{
	int		i;
	char	**str;

	map->cnt = 0;
	i = 0;
	set_null(map);
	while (map->textures[i])
	{
		str = ft_split(map->textures[i], ' ');
		check_count(map, str);
		texture_store(map, str);
		ft_free(str);
		i++;
	}
	if (map->cnt == 6)
		return (1);
	return (0);
}

int	set_map(t_cube *maps, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	maps->map = ft_calloc(i + 1, sizeof(char *));
	if (!maps->map)
		return (1);
	i = 0;
	while (map[i])
	{
		maps->join = ft_strjoin(map[i], "\n");
		maps->map[i] = maps->join;
		i++;
	}
	maps->map[i] = NULL;
	return (i);
}

int	main(int ac, char **av)
{
	t_cube			maps;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!check_cub(av[1]))
	{
		ft_putstr_fd("File Extension != .cub\n", 2);
		return (0);
	}
	if (ac == 2)
	{
		ft_parsing(av, &maps);
		wall_check(&maps);
		valid_map(&maps, i, j);
		check_color(&maps);
		open_window(&maps);
		free_all(&maps);
	}
}
