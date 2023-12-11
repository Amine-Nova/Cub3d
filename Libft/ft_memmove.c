/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:37 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 11:46:02 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	if (!dst && !src)
		return (0);
	if (d < s)
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
		while (size--)
			d[size] = s[size];
	return (dst);
}
