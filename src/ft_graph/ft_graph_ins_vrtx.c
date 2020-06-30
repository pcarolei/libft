/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ins_vrtx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:23:36 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/17 16:13:20 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 *	@brief 
 *
 *	@param graph
 *	@param data
 *
 *	@return 
 *	$Contract:
 *		requires:	graph != NULL
 *					data != NULL
 *					graph->match != NULL
 *		ensures:	//TODO
 *		invariants: //TODO
 */
t_graph	*ft_graph_ins_vrtx(t_graph *graph, void *data)
{
	t_llist_el	*el;
	t_adj_list	*adj_list;
	t_llist		*adj_lists;

	FT_REQUIRES((graph != NULL) && (data != NULL) && (graph->match != NULL));
	adj_lists = &(graph->adj_lists);
	el = adj_lists->head;
	while (el != NULL)
	{
		if (graph->match(data, ((t_adj_list *)el->data)->vertex))
			return (graph);
		el = el->next;
	}
	if (!(adj_list = (t_adj_list *)malloc(sizeof(t_adj_list))))
		return (NULL);
	adj_list->vertex = data;
	ft_llist_init(&adj_list->adjacent, NULL, graph->match);
	if (!(ft_llist_ins_nxt(adj_lists, adj_lists->tail, adj_list)))
		return (NULL);
	graph->v_cnt++;
	return (graph);
}
