/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_pjw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:28:09 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 07:28:18 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_hash_pjw(char *str)
{
	unsigned int	val;
	unsigned int	tmp;

	val = 0;
	while (*str)
	{
		val = (val << 4) + (*str);
		if ((tmp = (val & 0xf0000000)) != 0)
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		str++;
	}
	return (val);
}
