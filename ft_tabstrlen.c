/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchassig <mchassig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:09:09 by mchassig          #+#    #+#             */
/*   Updated: 2022/06/06 12:16:33 by mchassig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tabstrlen(char **strs)
{
	if (*strs)
		return (ft_tabstrlen(strs + 1) + 1);
	return (0);
}
