/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 04:55:33 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:01:04 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_float_to_str(long double num, int sign)
{
	char		bits[80];

	num_to_bits(num, bits);
	return (bits_to_numstr(bits, sign));
}
