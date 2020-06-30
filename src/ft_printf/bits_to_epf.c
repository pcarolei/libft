/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_epf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:53:01 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:00:34 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	get_exponent_from_bits(char *bits, char *exp)
{
	int	i;

	i = 1;
	while (i < 16)
	{
		exp[i - 1] = bits[i];
		i++;
	}
}

static void	get_mantissa_from_bits(char *bits, char *mnt)
{
	int	i;

	i = 16;
	while (i < 80)
	{
		mnt[i - 16] = bits[i];
		i++;
	}
}

static void	get_decimal_exponent(t_ld_epf *epf)
{
	int	i;
	int	exp_dec;

	i = 0;
	exp_dec = 0;
	while (i < 15)
	{
		exp_dec += (epf->exp[14 - i] - '0') * ft_pow(2, i);
		i++;
	}
	epf->exp_dec = (exp_dec - 16383);
}

void		bits_to_epf(char *bits, t_ld_epf *epf)
{
	epf->sign = bits[0];
	get_exponent_from_bits(bits, epf->exp);
	get_mantissa_from_bits(bits, epf->mnt);
	get_decimal_exponent(epf);
	get_integer_part_bin(epf);
	get_fract_part_bin(epf);
}
