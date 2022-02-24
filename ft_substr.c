/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:33:50 by mchassig          #+#    #+#             */
/*   Updated: 2022/02/24 17:33:56 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		if ((ft_strlen(s) - start) < len)
			len = ft_strlen(s) - start;
	}
	else
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	i = -1;
	if (start <= ft_strlen(s))
		while (++i < len && s[start + i])
			dest[i] = s[start + i];
	return (dest);
}
