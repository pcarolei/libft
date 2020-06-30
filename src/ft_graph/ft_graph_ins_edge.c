/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ins_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:16:44 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 19:33:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_graph	*ft_graph_ins_edge(t_graph *graph, void *data1, void *data2)
{
	t_llist_el	*el;
	t_llist		*adj_lists;

	if (!graph || !data1 || data2)
		return (NULL);
	adj_lists = &graph->adj_lists;
	el = adj_lists->head;
	while (el != NULL)
	{
		if (graph->match(data2, ((t_adj_list *)el->data)->vertex))
			break ;
		el = el->next;
	}
	if (!el)
		return (NULL);
	el = adj_lists->head;
	while (el != NULL)
	{
		if (graph->match(data1, ((t_adj_list *)el->data)->vertex))
			break ;
		el = el->next;
	}
	if (!ft_llist_ins_nxt(&((t_adj_list *)el->data)->adjacent, (&((t_adj_list *)el->data)->adjacent)->tail, data2))
		return (NULL);
	graph->e_cnt++;
	return (graph);
}
