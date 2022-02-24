/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:48:32 by mchassig          #+#    #+#             */
/*   Updated: 2021/12/21 17:18:18 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharn(char c, int *n)
{
	write(1, &c, 1);
	*n += 1;
}

void	ft_putstrn(char *str, int *n)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			ft_putcharn(str[i], n);
	else
		ft_putstrn("(null)", n);
}

void	ft_putnbrn_base(unsigned long long int nb, char *base, int *n)
{
	unsigned long long int	base_size;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (nb > (base_size - 1))
		ft_putnbrn_base(nb / base_size, base, n);
	ft_putcharn(base[nb % base_size], n);
}

void	ft_selectconv(va_list ap, char s, int *n, long long int i)
{
	if (s == 'c')
		ft_putcharn(va_arg(ap, int), n);
	else if (s == 's')
		ft_putstrn(va_arg(ap, char *), n);
	else if (s == 'p')
	{
		ft_putstrn("0x", n);
		ft_putnbrn_base(va_arg(ap, long long int), "0123456789abcdef", n);
	}
	else if (s == 'd' || s == 'i')
	{
		i = va_arg(ap, int);
		if (i < 0)
		{
			i = -i;
			ft_putcharn('-', n);
		}
		ft_putnbrn_base(i, "0123456789", n);
	}
	else if (s == 'u')
		ft_putnbrn_base(va_arg(ap, unsigned int), "0123456789", n);
	else if (s == 'x')
		ft_putnbrn_base(va_arg(ap, unsigned int), "0123456789abcdef", n);
	else if (s == 'X')
		ft_putnbrn_base(va_arg(ap, unsigned int), "0123456789ABCDEF", n);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		n;

	va_start(ap, s);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[++i] == '%')
				ft_putcharn(s[i], &n);
			ft_selectconv(ap, s[i], &n, 0);
		}
		else
			ft_putcharn(s[i], &n);
		i++;
	}
	va_end(ap);
	return (n);
}
