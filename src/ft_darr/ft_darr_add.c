/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 19:08:37 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 05:15:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_darr			*ft_darr_add(t_darr *arr, void *data, size_t item_size)
{
	void	*tmp;
	size_t	old_max;

	if (item_size != arr->item_size)
		exit(EXIT_FAILURE);
	if (!arr || !data || !arr->data)
		return (NULL);
	if (arr->max_cnt > arr->cur_cnt)
	{
		tmp = ft_darr_get(arr, arr->cur_cnt);
		ft_memcpy(tmp + item_size, data, item_size);
		return (arr);
	}
	old_max = arr->max_cnt;
	ft_darr_ext(arr, arr->max_cnt);
	ft_darr_set(arr, old_max + 1, data);
	return (arr);
}
