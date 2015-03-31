/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:10:45 by aalliot           #+#    #+#             */
/*   Updated: 2015/01/02 15:10:57 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_sub(char *str, int start, int l)
{
	if (!str)
		return ;
	str += start;
	while (l-- && *str)
	{
		ft_putchar(*str++);
	}
}
