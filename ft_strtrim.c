/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:01 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/30 12:04:34 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && (ft_ischarset(s1[start], set)))
		start++;
	end = ft_strlen(s1);
	while (end > start && (ft_ischarset(s1[end - 1], set)))
		end--;
	s2 = malloc(sizeof(char) * (end - start + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
