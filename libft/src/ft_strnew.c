/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:13:59 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/09 17:24:05 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
