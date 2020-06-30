/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 03:40:26 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 03:47:48 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline void	*ft_darr_get(t_darr *arr, size_t n)
{
	if ((n > arr->max_cnt) || (!arr))
		return (NULL);
	return(arr->data + (arr->item_size * n));
}
