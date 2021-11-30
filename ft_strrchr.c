/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:22:55 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/25 21:26:37 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + len);
	while (--len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)str + len);
	}
	return (0);
}
