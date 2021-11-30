/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:04:27 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/26 17:09:31 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dest && !src)
		return (dest);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (len-- > 0)
		{
			tmp_dest[len] = tmp_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
