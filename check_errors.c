/* ************************************************************************** */
/*				                                                              */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:50:12 by yberrim           #+#    #+#             */
/*   Updated: 2023/12/05 09:03:11 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_start(char *str)
{
	str = ft_strtrim(str, " \n\t");
	if (str[0] != '1')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	check_wal(char *str)
{
	int	i;

	i = 0;
	str = ft_strtrim(str, " \n\t");
	while (str[i])
	{
		if (str[i] != '1')
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

void	valid_map(t_cube *maps, unsigned int i, unsigned int j)
{
	i = 1;
	while (maps->only_map[i + 1])
	{
		j = 1;
		while (maps->only_map[i][j + 1])
		{
			if (maps->only_map[i][j] == '0')
			{
				if ((maps->only_map[i][j + 1]
					&& maps->only_map[i][j + 1] == ' ')
					|| (j - 1 >= 0 && maps->only_map[i][j - 1] == ' ' )
					|| (maps->only_map[i + 1][j]
						&& maps->only_map[i + 1][j] == ' ')
					|| (i - 1 >= 0 && maps->only_map[i - 1][j] == ' '))
					creat_erro(maps);
				else if (j == ft_strlen(maps->only_map[i]) - 2
					|| (i - 1 >= 0 && ft_strlen(maps->only_map[i - 1]) - 2 < j)
					|| (maps->only_map[i + 1]
						&& ft_strlen(maps->only_map[i + 1]) - 2 < j))
					creat_erro(maps);
			}
			j++;
		}
		i++;
	}
}

void	wall_check(t_cube *maps)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	if (check_wal(maps->only_map[0]))
		creat_erro(maps);
	while (maps->only_map[0][j])
	{
		if (!check_start(maps->only_map[0]) || maps->only_map[0][j] == '\n')
			j++;
		else
			creat_erro(maps);
	}
	while (maps->only_map[i + 1])
	{
		if (check_start(maps->only_map[i]) || check_arr(maps->only_map[i]))
			creat_erro(maps);
		i++;
	}
	j = -1;
	while (maps->only_map[i][++j])
		if (maps->only_map[i][j] != '1' && maps->only_map[i][j] != '\n'
			&& maps->only_map[i][j] != ' ')
			creat_erro(maps);
}

void	check_color(t_cube *maps)
{
	int	i;

	i = 0;
	check_coma(maps->c);
	maps->clr = ft_split(maps->c, ',');
	i = check_clr(maps->clr);
	if (ft_atoi(maps->clr[0]) > 255 || ft_atoi(maps->clr[1]) > 255
		|| ft_atoi(maps->clr[2]) > 255)
	{
		ft_free(maps->clr);
		creat_erro(maps);
	}
	ft_free(maps->clr);
	maps->clr = NULL;
	check_coma(maps->f);
	maps->clr = ft_split(maps->f, ',');
	i += check_clr(maps->clr);
	if (ft_atoi(maps->clr[0]) > 255 || ft_atoi(maps->clr[1]) > 255
		|| ft_atoi(maps->clr[2]) > 255 || i > 0)
	{
		ft_free(maps->clr);
		creat_erro(maps);
	}
	ft_free(maps->clr);
}
