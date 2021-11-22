#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char		*dest;
	unsigned int	i;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
