/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_rem_vrtx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 18:39:47 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/17 15:41:26 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_graph		*ft_graph_rem_vrtx(t_graph *graph, void **data)
{
	t_llist		*adj_lists;
	t_llist_el	*el;
	t_llist_el	*temp;
	t_llist_el	*prev;
	t_adj_list	*adj_list;

	if (!graph || !data)
		return (NULL);
	prev = NULL;
	temp = NULL;
	adj_lists = &(graph->adj_lists);
	el = adj_lists->head;
	while (el != NULL)
	{
		if (ft_llist_is_member(&((t_adj_list *)(el->data))->adjacent, *data))
		{
			ft_printf("returns at line %d\n", __LINE__);
			return (NULL);
		}
		if (graph->match(*data, ((t_adj_list *)(el->data))->vertex) == TRUE)
			temp = el;
		if (!temp)
			prev = el;
		el = el->next;
	}
	if (!temp)
	{
		ft_printf("returns at line %d\n", __LINE__);
		return (NULL);
	}
	if ((&(((t_adj_list *)(temp->data))->adjacent))->elem_cnt > 0)
	{
		ft_printf("returns at line %d\n", __LINE__);
		return (NULL);
	}
	if (!ft_llist_rem_nxt(adj_lists, prev, (void **)&adj_list))
	{
		ft_printf("returns at line %d\n", __LINE__);
		return (NULL);
	}
	*data = adj_list->vertex;
	free(adj_list);
	graph->v_cnt--;
	return (graph);
}
