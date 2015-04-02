/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:25:05 by adoussau          #+#    #+#             */
/*   Updated: 2015/01/02 14:25:46 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_malloc(size_t n)
{
	void	*ret;

	if (!(ret = malloc(n)))
	{
		ft_putstr_fd("Malloc error: Program quited.", 2);
		exit (2);
	}
	return (ret);
}
