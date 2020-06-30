/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:24:14 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/15 21:53:38 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 *	@brief	Get square root of integer variable
 *
 *	@param	nb
 *	@return	res square root of nb
 *	$Contract:
 *		requires:	nb >= 0
 *		ensures:	res * res = nb
 */
int	ft_sqrt(int nb)
{
	int res;

	res = 1;
	FT_REQUIRES((nb) >= 0);
	if (nb == 1)
		return (1);
	if (nb == 2147395600)
		return (46340);
	while (res * res < nb && res < 46340)
		res++;
	FT_ENSURES((res * res) == (nb));
	return (res);
}
