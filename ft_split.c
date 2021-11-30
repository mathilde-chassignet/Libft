/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:19:50 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/30 13:34:38 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	wrd;

	if (s[0] == '\0')
		return (0);
	i = 1;
	wrd = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			wrd++;
		i++;
	}
	if (s[i - 1] != c)
		wrd++;
	return (wrd);
}

static int	letter_count(char const *s, char c, int i)
{
	int	ltr;

	ltr = 0;
	while (s[i] && s[i] != c)
	{
		ltr++;
		i++;
	}
	return (ltr);
}

static char	*ft_substr_split(char const *s, int *i, int ltr)
{
	char	*str;
	int		k;

	str = malloc(sizeof(char) * (ltr + 1));
	if (!str)
		return (NULL);
	k = 0;
	while (k < ltr)
	{
		str[k] = s[*i];
		k++;
		*i = *i + 1;
	}
	str[k] = '\0';
	return (str);
}

static char	**ft_free_split(char **dest, int j)
{
	while (j >= 0)
	{
		free(dest[j]);
		j--;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		wrd;
	int		ltr;
	int		i;
	int		j;
	char	**dest;

	wrd = word_count(s, c);
	dest = malloc(sizeof(char *) * (wrd + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (j < wrd)
	{
		ltr = letter_count(s, c, ++i);
		if (ltr != 0)
		{
			dest[j] = ft_substr_split(s, &i, ltr);
			if (!dest[j])
				return (ft_free_split(dest, j - 1));
			j++;
		}
	}
	dest[j] = NULL;
	return (dest);
}
