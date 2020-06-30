/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rem_nxt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:59:57 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/18 09:58:50 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
 *	if (el == NULL) then we are deleting head of linked list
 *	if data arg provided then we save data from deleted list there
*/

/**
 *	@brief 
 *
 *	@param list
 *	@param el
 *	@param data
 *
 *	@return 
 *	$Contract:
 *		requires:	list != NULL, list->elem_cnt != NULL
 *		ensures:	list without elemen el
 *		invarians:	list->elem_cnt >= 0
 */
t_llist	*ft_llist_rem_nxt(t_llist *list, t_llist_el *el, void **data)
{
	t_llist_el	*old_elem;

	FT_INV_CHECK(list->elem_cnt >= 0);
	ft_printf("list->elem_cnt = %d\n", list->elem_cnt);
	FT_REQUIRES((list != NULL) && (list->elem_cnt > 0));
	if (el == NULL)
	{
		*data = list->head->data;
		old_elem = list->head;
		list->head = list->head->next;
		list->tail = (list->elem_cnt == 1) ? (NULL) : (list->tail);
	}
	else
	{
		if (el->next == NULL)
			return (NULL);
		*data = el->next->data;
		old_elem = el->next;
		el->next = el->next->next;
		list->tail = (el->next == NULL) ? (el) : (list->tail);
	}
	list->elem_cnt--;
	//TODO FT_ENSURES();
	FT_INV_CHECK(list->elem_cnt >= 0);
	return (list);
}
