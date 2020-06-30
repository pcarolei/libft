/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_is_member.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:42:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 19:43:11 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

BOOL	ft_llist_is_member(t_llist *list, void *data)
{
	t_llist_el	*el;

	if (!list->match)
		exit(EXIT_FAILURE);
	el = list->head;
	while (el != NULL)
	{
		if (list->match(el->data, data))
			return (TRUE);
		el = el->next;
	}
	return (FALSE);
}
