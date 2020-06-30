/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:10:40 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 05:24:48 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARR_H
# define FT_DARR_H

typedef struct				s_darr
{
	void	*data;
	size_t	item_size;
	size_t	cur_cnt;
	size_t	max_cnt;
	void	(*destroy)(void *data);
}							t_darr;

t_darr			*ft_darr_init(t_darr *arr, size_t item_size, size_t max_cnt, void (*destroy)(void *data));
void			ft_darr_del(t_darr *arr);
t_darr			*ft_darr_ext(t_darr *arr, size_t inc);
t_darr			*ft_darr_shr(t_darr *arr, size_t dec);
t_darr			*ft_darr_join(t_darr *arr1, t_darr *arr2);
void			*ft_darr_get(t_darr *arr, size_t n);
void			ft_darr_set(t_darr *arr, size_t n, void *elem_data);
t_darr			*ft_darr_add(t_darr *arr, void *data, size_t item_size);

#endif
