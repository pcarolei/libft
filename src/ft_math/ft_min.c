/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:47:22 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 08:56:42 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_min(long long int a, long long int b)
{
	if (a > b)
		return (b);
	return (a);
}
