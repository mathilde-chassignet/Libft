int	ft_isalnum(int arg)
{
	if ((arg >= 65 && arg <= 90) || (arg >= 97  && arg <= 122)
	|| (arg >= 48 && arg <= 57))
		return (1);
	else
		return (0);
}
