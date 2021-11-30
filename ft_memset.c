/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:30:07 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/24 11:06:59 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)ptr;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
