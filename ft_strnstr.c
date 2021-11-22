char	*ft_strnstr(char *str, char *to_find, int len)
{
	int	i;
	int	k;

	i = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		k = 0;
		while (str[i + k] == to_find[k] && str[i + k] && k < len)
			k++;
		if (!to_find[k] || k == len)
			return (&str[i]);
		i++;
	}
	return (0);
}
