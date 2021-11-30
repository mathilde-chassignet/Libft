/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:18:14 by mchassig          #+#    #+#             */
/*   Updated: 2021/11/24 16:10:37 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	lg;

	lg = n;
	if (lg < 0)
	{
		lg = -lg;
		write(fd, "-", 1);
	}
	if (lg > 9)
	{
		ft_putnbr_fd(lg / 10, fd);
		ft_putnbr_fd(lg % 10, fd);
	}
	else
	{
		lg += '0';
		write(fd, &lg, 1);
	}
}
