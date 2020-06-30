/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:59:23 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/15 20:49:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 *	@brief initialize graph struct by pointer
 *
 *	@param graph		pointer to graph struct
 *	@param match		pointer to function that matches 2 vertices
 *	@param destroy	pointer to function that frees dynamically allocated data (vertex)
 *
 *	@return 			pointer to graph struct
 *	$Contract:
 *		requires:	graph != NULL
 *		ensures:	
 *		invariants:	
 */
t_graph	*ft_graph_init(t_graph *graph, BOOL (*match)(void *key1, void *key2),
											void (*destroy)(void *data))
{
	if (!graph)
		return (NULL);
	graph->v_cnt = 0;
	graph->e_cnt = 0;
	graph->match = match;
	graph->destroy = destroy;
	ft_llist_init(&graph->adj_lists, NULL, NULL);
	return (graph);
}
