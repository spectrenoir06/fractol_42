/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:43:14 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/09 17:20:33 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2)
	{
		while (n--)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}
