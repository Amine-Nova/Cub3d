/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:41:37 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:42:42 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_lines_lenght(t_cube *maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps->only_map[i])
		i++;
	maps->len = ft_calloc(sizeof(int), i);
	if (!maps->len)
		return ;
	i = 0;
	while (maps->only_map[i])
	{
		j = 0;
		while (maps->only_map[i][j])
			j++;
		maps->len[i] = j;
		i++;
	}
}

int	setmaps_w(t_cube *maps, int i, int j)
{
	int		l;
	char	*tmp;

	i = -1;
	while (maps->only_map[++i])
	{
		tmp = ft_strtrim(maps->only_map[i], " \t\v\r\f");
		maps->only_map[i] = tmp;
		j = 0;
		l = 0;
		while (maps->only_map[i][j])
		{
			if (maps->only_map[i][j] != 'N' && maps->only_map[i][j] != 'S'
				&& maps->only_map[i][j] != 'W' && maps->only_map[i][j] != 'E'
				&& maps->only_map[i][j] != '0' && maps->only_map[i][j] != '1'
				&& maps->only_map[i][j] != '\n')
				return (0);
			if (maps->only_map[i][j] != ' ' && maps->only_map[i][j] != '\t')
				l++;
			j++;
		}
		if (l >= 40)
			return (0);
	}
	return (1);
}

int	check_con(t_cube *maps)
{
	int	i;

	i = 0;
	while (maps->str[i])
	{
		if (maps->str[i] == '\n' && maps->str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	setmaps_h(t_cube *maps)
{
	int	i;

	i = 0;
	while (maps->only_map[i])
		i++;
	if (i > 24)
		return (0);
	return (1);
}

void	ft_parsing(char **av, t_cube *maps)
{
	int	i;
	int	j;

	j = 0;
	read_from_file(maps, av[1]);
	if (check_double_nl(maps->str))
	{
		ft_free(maps->map);
		ft_putstr_fd("Error Map\n", 2);
		exit (1);
	}
	read_only_textures(maps);
	read_only_map(maps);
	i = 0;
	if (check_texter(maps) && store_player_side(maps)
		&& setmaps_w(maps, i, j) && setmaps_h(maps))
		get_lines_lenght(maps);
	else
	{
		ft_free(maps->map);
		ft_putstr_fd("Error Map\n", 2);
		exit (1);
	}
}
