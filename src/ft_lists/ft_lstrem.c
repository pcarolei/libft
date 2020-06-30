/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 01:00:53 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/12 08:15:29 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	**remove_head(t_list **root, void (*del)(void *, size_t))
{
	t_list	*nxt;

	nxt = (*root)->next;
	del((*root)->content, (*root)->content_size);
	free(*root);
	*root = nxt;
	return (root);
}

t_list			**ft_lstrem(t_list **root, t_list *list_to_rem, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*prv;

	if (!root || !(*root) || !list_to_rem)
		return (NULL);
	ptr = *root;
	if (*root == list_to_rem)
		return (remove_head(root, del));
	while (ptr)
	{
		if (ptr == list_to_rem)
		{
			prv->next = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			return (root);
		}
		prv = ptr;
		ptr = ptr->next;
	}
	return (NULL);
}
