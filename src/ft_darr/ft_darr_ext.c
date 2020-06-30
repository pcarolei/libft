/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:44:22 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 05:10:44 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_darr	*ft_darr_ext(t_darr *arr, size_t inc)
{
	void	*old_data;
	size_t	old_cnt;

	if (!arr || (inc < 0))
		return (NULL);
	if (inc == 0)
		return (arr);
	old_cnt = arr->cur_cnt;
	old_data = arr->data;
	arr->max_cnt += inc;
	if (!(arr->data = malloc(arr->max_cnt * arr->item_size)))
		return (NULL);
	if (old_cnt) // вдруг в массиве не было элементов
		ft_memcpy(arr->data, old_data, old_cnt * arr->item_size);
	arr->destroy(old_data);
	return (arr);
}
