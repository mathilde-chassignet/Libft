#include <stdlib.h>

int	ft_strlen_join(char const *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len;
	int	i;
	int	j;
	char	*dest;

	len = ft_strlen_join(s1) + ft_strlen_join(s2);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	i = 0;
	j = 0;
	while (s1[j])
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	return (dest);
}
