/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 15:07:23 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 18:22:29 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_graph_destroy(t_graph *graph)
{
	t_adj_list	*adj_list;
	t_llist		*adj_lists;

	if (!graph || !graph->destroy)
		exit(EXIT_FAILURE);
	adj_lists = &(graph->adj_lists);
	while (adj_lists->elem_cnt > 0)
	{
		if (ft_llist_rem_nxt(adj_lists, NULL, (void **)&adj_list))
		{
			ft_llist_dstr(&adj_list->adjacent);
			graph->destroy(adj_list->vertex);			
			free(adj_list);
		}
	}
	ft_llist_dstr(adj_lists);
	ft_bzero(graph, sizeof(t_graph));
}
