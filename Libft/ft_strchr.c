/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:58:43 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 11:48:33 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	y;
	int		i;

	i = 0;
	y = (char )c;
	while (s[i])
	{
		if (s[i] == y)
			return ((char *)&s[i]);
		i++;
	}
	if (y == '\0')
		return ((char *)&s[i]);
	return (0);
}
