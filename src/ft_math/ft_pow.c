/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 04:04:39 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/08 04:05:09 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int n, int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res *= n;
		pow--;
	}
	return (res);
}