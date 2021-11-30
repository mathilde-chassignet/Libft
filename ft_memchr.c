/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:26:12 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/24 11:36:41 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	size_t		i;
	const char	*tmp;

	i = 0;
	tmp = (const char *)ptr;
	while (i < n)
	{
		if (tmp[i] == (char)c)
			return ((char *)tmp + i);
		i++;
	}
	return (0);
}
