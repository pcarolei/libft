/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:21:42 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 08:55:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lst_get_length(t_list *root)
{
	t_list	*ptr;
	int		i;

	if (!root)
		return (0);
	ptr = root;
	i = 0;
	while (ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
