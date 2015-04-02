/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:19:48 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/05 16:29:23 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;

	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	while (n--)
		*strdst++ = *strsrc++;
	return (dst);
}
