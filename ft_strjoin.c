/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:20:38 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/29 21:03:15 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dest, char const *s, int i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	dest = ft_cpy(dest, s1, 0);
	dest = ft_cpy(dest, s2, ft_strlen(s1));
	return (dest);
}
