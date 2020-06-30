/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 03:59:02 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 03:59:51 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

inline void	ft_darr_set(t_darr *arr, size_t n, void *elem_data)
{
	void	*n_elem_ptr;

	if (!arr || (n >= arr->max_cnt) || !elem_data)
		exit(EXIT_FAILURE);
	n_elem_ptr = ft_darr_get(arr, n);
	ft_memcpy(n_elem_ptr - arr->item_size, elem_data, arr->item_size);
}
