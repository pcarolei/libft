/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_ins_nxt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:45:00 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 18:04:14 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_llist	*ft_llist_ins_nxt(t_llist *list, t_llist_el *el, void *data)
{
	t_llist_el	*new_el;

	if (!list || !data || (!(new_el = (t_llist_el *)malloc(sizeof(t_llist_el)))))
		return (NULL);
	new_el->data = data;
	if (el == NULL)
	{
		if (list->elem_cnt == 0)
			list->tail = new_el;
		new_el->next = list->head;
		list->head = new_el;
	}
	else {
		if (el->next == NULL)
			list->tail = new_el;
		new_el->next = el->next;
		el->next = new_el;
	}
	return (list);
}
