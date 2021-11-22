int	ft_isalpha(int arg)
{
	if ((arg >= 65 && arg <= 90) || (arg >= 97  && arg <= 122))
		return (arg);
	else
		return (0);
}
