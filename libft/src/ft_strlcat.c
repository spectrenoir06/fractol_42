/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:37:06 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/06 11:26:27 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		nsv;
	size_t		buff;
	size_t		size2;

	nsv = size;
	size2 = ft_strlen(src);
	buff = ft_strlen(dst) + size2;
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (nsv + size2);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = 0;
	return (buff);
}
