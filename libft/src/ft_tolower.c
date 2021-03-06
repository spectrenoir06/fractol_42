/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:11:16 by adoussau          #+#    #+#             */
/*   Updated: 2014/11/05 13:38:53 by adoussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c);
}
