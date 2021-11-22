#include <stdlib.h>

int	ft_ischarset(char c, char const *set)
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

	start = 0;
	while (s1[start] && (ft_ischarset(s1[start], set)))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && (ft_ischarset(s1[end - 1], set)))
		end--;
	if (!(s2 = malloc(sizeof(char) * (end - start + 1))))
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
