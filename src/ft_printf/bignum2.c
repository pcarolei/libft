/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:28:44 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:00:31 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*mult_by_10_n_times(char *num, int n)
{
	char	*res;

	res = num;
	while (n > 0)
	{
		res = bignum_multiply_by_n(res, 10);
		n--;
	}
	return (res);
}

char	*power_of_2(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (ft_char_to_str('1'));
	res = ft_char_to_str('2');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 2);
		i++;
	}
	return (res);
}

char	*power_of_5(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (ft_char_to_str('1'));
	res = ft_char_to_str('5');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 5);
		i++;
	}
	return (res);
}
