/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 02:01:53 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 04:25:38 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	size_t	i;
	char	tmp;

	if (!a || !b)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		tmp = ((char *)a)[i];
		((char *)a)[i] = ((char *)b)[i];
		((char *)b)[i] = tmp;
		i++;
	}
}
