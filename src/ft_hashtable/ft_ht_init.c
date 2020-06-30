/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 08:03:13 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:03:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ht_init(t_hashtable *ht, int buckets, void (*destroy)(void *data, size_t size))
{
	int	i;

	if (!(ht->table = (t_list **)malloc(buckets * sizeof(t_list *))))
		return (0);
	ht->size = 0;
	ht->buckets = buckets;
	ht->destroy = destroy;
	i = 0;
	while (i < buckets)
	{
		ht->table[i] = ft_lstnew(NULL, 0);
		i++;
	}
	return (1);
}
