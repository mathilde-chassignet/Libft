char	*ft_strrchr(char *str, int c)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	while (--len >= 0)
	{
		if (str[len] == c)
			return (&str[len]);
	}
	return (0);
}

