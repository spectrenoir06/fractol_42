/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:55:07 by adoussau          #+#    #+#             */
/*   Updated: 2015/01/02 16:55:39 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_intlen(int i)
{
	int		ret;

	ret = 1;
	while (i /= 10)
		ret++;
	return (ret);
}
