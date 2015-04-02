/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:55:01 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/11 12:45:09 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*dst;
	char		*ret;

	if (!len)
		return ("");
	if (!s || !*s)
		return (NULL);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ret = dst;
	while (len--)
		*dst++ = s[start++];
	*dst = 0;
	return (ret);
}
