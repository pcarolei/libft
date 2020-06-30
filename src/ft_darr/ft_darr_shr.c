/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_shr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:07:47 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 04:44:52 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_darr			*ft_darr_shr(t_darr *arr, size_t dec)
{
	void	*old_data;

	if ((dec == 0) && (arr != NULL))
		return (arr);
	if ((!arr || (dec < 0) || (arr->max_cnt - dec <= 0)) && (!(old_data = NULL)))
		return (NULL);
	ft_swap_vptr(&(arr->data), &old_data);
	if (!(arr->data = malloc(arr->item_size * (arr->max_cnt - dec))))
		return (NULL);
	ft_memcpy(arr->data, old_data, arr->max_cnt - dec);
	arr->destroy(old_data);
	return (arr);
}
