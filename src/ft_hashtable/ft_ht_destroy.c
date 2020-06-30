/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 08:06:19 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:06:36 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_ht_destroy(t_hashtable *ht)
{
	int		i;
	t_list	*bucket_list;

	i = 0;
	while (i < ht->buckets)
	{
		bucket_list = (ht->table[i]);
		ft_lstdel(&bucket_list, ht->destroy);
		i++;
	}
	free(ht->table);
}
