/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:17:40 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 05:08:12 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_darr	*ft_darr_init(t_darr *arr, size_t item_size, size_t max_cnt, void (*destroy)(void *data))
{
	if (!arr || !item_size || !max_cnt || !destroy)
		return (NULL);
	if (!(arr->data = malloc(item_size * max_cnt)))
		return (NULL);
	arr->item_size = item_size;
	arr->cur_cnt = 0;
	arr->max_cnt = max_cnt;
	arr->destroy = destroy;
	return (arr);
}
