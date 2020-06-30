/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:39:33 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 15:05:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_darr_del(t_darr *arr)
{
	if (!arr)
		return ;
	arr->destroy(arr->data);
	ft_bzero(arr, sizeof(t_darr));
}
