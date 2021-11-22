int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (arg);
	else
		return (0);
}
