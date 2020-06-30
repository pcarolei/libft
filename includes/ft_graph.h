/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:44:22 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/17 15:53:53 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include <libft.h>

/**
 *	@brief adjacenty list struct
 *	vertex		-	pointer to vertex data struct
 *	adjacent	-	linked list of adjacent vertices adjacent to vertex
 */
typedef struct	s_adj_list
{
	void		*vertex;
	t_llist		adjacent;
}				t_adj_list;

/**
 *	@brief graph data structure
 *
 *	v_cnt		-	number of vertices in the graph
 *	e_cnt		-	number of edges in the graph
 *	adj_lists	-	linked list of adj_list structures
 *	match		-	function that matches 2 vertices
 *	destroy		-	function that frees dynamically allocated data (vertex)
 *	$Contract:
 *		invariants:	v_cnt >= 0
 *					e_cnt >= 0
 *					//TODO
 */
typedef struct	s_graph
{
	int			v_cnt;
	int			e_cnt;
	t_llist		adj_lists;
	BOOL		(*match)(void *key1, void *key2);
	void		(*destroy)(void *data);
}				t_graph;

t_graph			*ft_graph_init(t_graph *graph, BOOL (*match)(void *key1, void *key2),
											void (*destroy)(void *data));
void			ft_graph_destroy(t_graph *graph);
t_graph			*ft_graph_ins_vrtx(t_graph *graph, void *data);
t_graph			*ft_graph_rem_vrtx(t_graph *graph, void **data);
t_graph			*ft_graph_ins_edge(t_graph *graph, void *data1, void *data2);
t_graph			*ft_graph_rem_edge(t_graph *graph, void *data1, void **data2);

#endif
