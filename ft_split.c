/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <mchassig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:19:50 by mchassig          #+#    #+#             */
/*   Updated: 2022/06/07 13:23:54 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**get_dest(char const *s, char c, int size)
{
	char	**dest;
	char	*str;
	int		len;
	
	while (*s && *s == c)
		s++;
	if (!*s)
	{
		dest = malloc(sizeof(char *) * (size + 1));
		if (!dest)
			return (NULL);
		dest[size] = NULL;
		return (dest);
	}
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = ft_substr(s, 0, len);
	if (!str)
		return (NULL);
	dest = get_dest(&s[len], c, size + 1);
	if (!dest)
		return (free(str), NULL);
	dest[size] = str;
	return (dest);		
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (get_dest(s, c, 0));
}