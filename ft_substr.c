/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:09 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/30 12:11:07 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sublen(size_t slen, unsigned int start, size_t len)
{
	if (start <= slen)
	{
		if ((slen - start) < len)
			return (slen - start);
		else
			return (len);
	}
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_sublen(ft_strlen(s), start, len);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (start <= ft_strlen(s))
	{
		while (i < len && s[start])
		{
			dest[i] = s[start];
			i++;
			start++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
