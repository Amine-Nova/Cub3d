/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:19:17 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:44:52 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	creat_erro(t_cube *maps)
{
	ft_putstr_fd("Error\n", 2);
	free(maps->no);
	free(maps->so);
	free(maps->we);
	free(maps->ea);
	free(maps->f);
	free(maps->c);
	ft_free(maps->only_map);
	ft_free(maps->textures);
	exit(1);
}

void	set_angle(t_cube *maps)
{
	if (maps->player == 'E')
		maps->angle = 0;
	if (maps->player == 'W')
		maps->angle = PI;
	if (maps->player == 'S')
		maps->angle = PI * 0.5;
	if (maps->player == 'N')
		maps->angle = PI * 1.5;
}

void	check_count(t_cube *maps, char **ss)
{
	int	i;

	i = 0;
	while (ss[i])
		i++;
	if (i != 2)
	{
		free(maps->no);
		free(maps->so);
		free(maps->we);
		free(maps->ea);
		free(maps->f);
		free(maps->c);
		ft_free(maps->only_map);
		ft_free(maps->textures);
		ft_putstr_fd("Error in Texture\n", 2);
		exit(1);
	}
}

void	check_coma(char *ss)
{
	int	i;	
	int	count;

	count = 0;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		ft_putstr_fd("There is %d Comma \n", 2);
		exit(1);
	}
}

int	check_clr(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && (str[i][j] != '\n'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
