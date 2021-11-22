#include <stdlib.h>

int	word_count(char const *s, char c)
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

int	letter_count(char const *s, char c, int i)
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

char	**free_split(char **dest, int j)
{
	while (j >= 0)
	{
		free(dest[j]);
		j--;
	}
	free(dest);
	return (NULL);
}

char	*ft_substr_split(char const *s, int *i, int ltr)
{
	char	*str;
	int		k;

	if (!(str = malloc(sizeof(char) * (ltr + 1))))
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

char	**ft_split(char const *s, char c)
{
	int		wrd;
	int		ltr;
	int		i;
	int		j;
	char	**dest;

	wrd = word_count(s, c);
	if (!(dest = malloc(sizeof(char*) * (wrd + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < wrd)
	{
		if ((ltr = letter_count(s, c, i)) != 0)
		{
			if (!(dest[j] = ft_substr_split(s, &i, ltr)))
				return (free_split(dest, j - 1));
			j++;
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}
