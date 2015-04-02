/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:45:14 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/06 15:36:11 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void*)malloc(sizeof(void) * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return ((void*)ptr);
}
