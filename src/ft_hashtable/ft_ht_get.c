/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 08:05:29 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:05:55 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_ht_get(t_hashtable *ht, char *key)
{
	int				bucket;
	unsigned int	hash;
	t_list			*bucket_list;
	t_list			*cur;

	hash = ft_hash_pjw(key);
	bucket = hash % ht->buckets;
	bucket_list = (ht->table[bucket]);
	cur = bucket_list;
	while (cur)
	{
		if (cur->content_size == (size_t)hash)
			return (cur->content);
		cur = cur->next;
	}
	return (NULL);
}
