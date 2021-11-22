/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 13:59:26 by mchassig          #+#    #+#             */
/*   Updated: 2021/07/15 17:06:55 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lenDest;

	i = 0;
	lenDest = ft_strlen1(dest);
	j = lenDest;
	if (size <= lenDest)
		return (size + ft_strlen1(src));
	while (src[i] && i < size - lenDest - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ft_strlen1(src) + lenDest);
}
