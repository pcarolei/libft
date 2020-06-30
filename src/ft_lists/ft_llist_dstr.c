/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:34:50 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 18:02:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_llist_dstr(t_llist *list)
{
	void	*data;

	if (!list || !list->destroy)
		exit(EXIT_FAILURE);
	while (list->elem_cnt > 0)
	{
		if (ft_llist_rem_nxt(list, NULL, (void **)&data))
			list->destroy(data);
	}
	ft_bzero(list, sizeof(t_llist));
}
