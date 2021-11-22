#include <stdlib.h>

char	*ft_strmalenpi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char		*dest;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
