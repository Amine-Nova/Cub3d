/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:14:20 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 11:46:21 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t wide)
{
	char	*f;
	char	o;
	size_t	i;

	i = 0;
	f = (char *)b;
	o = (char)c;
	while (i < wide)
	{
		f[i] = o;
		i++;
	}
	return (f);
}
