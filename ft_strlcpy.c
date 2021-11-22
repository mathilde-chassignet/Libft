unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (size == 0)
		return (1);
	while (i < size - 1 && dest[i] && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}
