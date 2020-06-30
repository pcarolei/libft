/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 05:24:19 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 05:25:18 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_darr	*ft_darr_join(t_darr *arr1, t_darr *arr2)
{
	void	*old_arr1_data;
	void	*old_arr2_data;
	t_darr	*res;

	if ((arr1->item_size != arr2->item_size) || (arr1->destroy != arr2->destroy))
		exit(EXIT_FAILURE);
	if (((!arr1 || !arr2) && ((old_arr1_data = NULL) && (old_arr1_data = NULL))) && 
		(!arr1->data || !arr2->data))
		return (NULL);
	ft_swap_vptr(&(arr1->data), &(old_arr1_data));
	ft_swap_vptr(&(arr2->data), &(old_arr2_data));
	if (!(res = (t_darr *)malloc(sizeof(t_darr))))
		return (NULL);
	res = ft_darr_init(res, arr1->item_size, 2*(arr1->cur_cnt + arr2->cur_cnt), arr1->destroy);
	ft_memcpy(res, arr1->data, arr1->cur_cnt);
	ft_memcpy(res, arr2->data, arr2->cur_cnt);
	return (res);
}
