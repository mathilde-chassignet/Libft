/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <mchassig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:29:03 by mchassig          #+#    #+#             */
/*   Updated: 2022/06/06 12:34:54 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_strslen(char **tab_str)
{
	if (!*tab_str)
		return (0);
	return (ft_strlen(*tab_str) + ft_strslen(tab_str + 1));
}

char	*ft_tabjoin(char **tab_str, char *sep)
{
	int		len;
	char	*dest;

	if (!tab_str || !*tab_str || !sep)
		return (NULL);
	len = ft_strslen(tab_str) + ft_strlen(sep) * (ft_tabstrlen(tab_str) - 1);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	while (tab_str[0] && tab_str[1])
	{
		dest = ft_strcat(dest, tab_str[0]);
		dest = ft_strcat(dest, sep);
		(tab_str)++;
	}
	dest = ft_strcat(dest, *tab_str);
	return (dest);
}