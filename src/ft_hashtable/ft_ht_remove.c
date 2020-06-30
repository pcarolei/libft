/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 08:05:00 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:05:23 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_ht_remove(t_hashtable *ht, char *key)
{
	int		bucket;
	t_list	*bucket_list;
	t_list	*cur;

	bucket = ft_hash_pjw(key) % ht->buckets;
	bucket_list = ht->table[bucket];
	cur = bucket_list->next;
	while (cur)
	{
		if (cur->content_size == (size_t)(ft_hash_pjw(key)))
		{
			ft_lstrem(&bucket_list, cur, ht->destroy);
			ht->size--;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}
