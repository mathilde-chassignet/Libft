/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:22:32 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/30 14:22:36 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		k = 0;
		while (str[i + k] == to_find[k] && str[i + k] && (i + k) < len)
			k++;
		if (!to_find[k])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
