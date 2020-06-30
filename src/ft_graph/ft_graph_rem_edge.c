/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_rem_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:40:41 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 19:59:48 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_llist	*remove_vrtx(t_llist *list, void **data)
{
	t_llist_el	*prev;
	t_llist_el	*target;

	if (!list->match)
		exit(EXIT_FAILURE);
	prev = NULL;
	target = list->head;
	while (target != NULL)
	{
		if (list->match(*data, target->data))
			break ;
		prev = target;
		target = target->next;
	}
	if (target == NULL)
		return (NULL);
	return (ft_llist_rem_nxt(list, prev, data));
}

t_graph			*ft_graph_rem_edge(t_graph *graph, void *data1, void **data2)
{
	t_llist		*adj_lists;
	t_llist_el	*el;

	if (!graph || !data1 || !data2)
		return (NULL);
	adj_lists = &graph->adj_lists;
	el = adj_lists->head;
	while (el != NULL)
	{
		if (graph->match(data1, ((t_adj_list *)(el->data))->vertex))
			break ;
		el = el->next;
	}
	if (el == NULL)
		return (NULL);
	if (!remove_vrtx(&((t_adj_list *)(el->data))->adjacent, data2))
		return (NULL);
	graph->e_cnt--;
	return (graph);
}
