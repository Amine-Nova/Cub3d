/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:35:12 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 11:46:48 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	char	*ht;
	char	*nd;
	size_t	i;
	size_t	j;

	ht = (char *)h;
	nd = (char *)n;
	if (len == 0 && ht == 0)
		return (0);
	if (nd[0] == 0)
		return (ht);
	i = 0;
	while (ht[i] && i < len)
	{
		j = 0;
		while (nd[j] && ht[i + j] == nd[j] && i + j < len)
			j++;
		if (j == ft_strlen(nd))
			return (&ht[i]);
		i++;
	}
	return (0);
}
