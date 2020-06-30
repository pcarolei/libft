/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 08:03:53 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:12:59 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ht_insert(t_hashtable *ht, char *key, void *data)
{
	int		bucket;
	t_list	*bucket_list;
	t_list	*new_elem;

	if (ft_ht_get(ht, key))
		return (0);
	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	new_elem->content = data;
	new_elem->content_size = ft_hash_pjw(key);
	new_elem->next = NULL;
	bucket = ft_hash_pjw(key) % ht->buckets;
	bucket_list = ht->table[bucket];
	ft_lstaddl(&bucket_list, new_elem);	//TODO: переписать через другую функцию
	ht->size++;
	return (1);
}
