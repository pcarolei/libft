/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:28:09 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 18:04:58 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_llist	*ft_llist_init(t_llist *list, void (*destroy)(void *data), BOOL (*match)(void *key1, void *key2))
{
	if (!list)
		return (NULL);
	list->elem_cnt = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
	list->match = match;
	return (list);
}
