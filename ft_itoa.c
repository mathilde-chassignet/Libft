/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:16:14 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/25 18:24:28 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	len;

	len = 0;
	while (n >= 1 || n <= -1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*nb;

	len = nbr_len(n);
	sign = 1;
	if (n <= 0)
	{
		sign = -1;
		len++;
	}
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	nb[0] = '-';
	if (n == 0)
		nb[0] = '0';
	nb[len] = '\0';
	while (--len >= 0 && (n >= 1 || n <= -1))
	{
		nb[len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (nb);
}
