/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <mchassig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:15:10 by mchassig          #+#    #+#             */
/*   Updated: 2022/06/06 12:40:31 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoinx(unsigned int nb_str, ...)
{
	va_list			ap;
	unsigned int	i;
	char			**tab_str;
	unsigned int	size;
	char			*new_str;

	tab_str = malloc(sizeof(char *) * nb_str);
	if (!tab_str || nb_str == 0)
		return (free(tab_str), NULL);
	va_start(ap, nb_str);
	size = 0;
	i = -1;
	while (++i < nb_str)
	{
		tab_str[i] = va_arg(ap, char *);
		size += ft_strlen(tab_str[i]);
	}
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (free(tab_str), va_end(ap), NULL);
	new_str[0] = '\0';
	i = -1;
	while (++i < nb_str)
		new_str = ft_strcat(new_str, tab_str[i]);
	return (va_end(ap), free(tab_str), new_str);
}
