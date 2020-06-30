/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:24:46 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/17 15:58:09 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H

//	old(42) linked list implementation
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
//	other funcs
t_list			**ft_lstrem(t_list **root, t_list *list_to_rem, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstaddl(t_list **alst, t_list *new);
int				ft_lst_get_length(t_list *lst);

//	New linked list implementation

/*
 *	Linked list element structure
 *
 *	args:
 *	data	-	void ptr to data
 *	next	-	pointer to next list element structure
*/
typedef struct			s_llist_el
{
	void				*data;
	struct s_llist_el	*next;
}						t_llist_el;

/*
 *	Linked list structure
 *
 *	args:
 *	elem_cnt	-	linked list elements count
 *	head		-	first element of linked list
 *	tail		-	last element of linked list
 *	match		-	function that matches linked list element data
 *	del			-	function that frees dynamically allocated data 
 *	$Contract:
 *		invariants:	elem_cnt >= 0
*/
typedef struct	s_llist
{
	size_t		elem_cnt;
	t_llist_el	*head;
	t_llist_el	*tail;
	BOOL		(*match)(void *, void *);
	void		(*destroy)(void *);
}				t_llist;

t_llist			*ft_llist_init(t_llist *list, void (*destroy)(void *data), BOOL (*match)(void *key1, void *key2));
void			ft_llist_dstr(t_llist *list);
t_llist			*ft_llist_ins_nxt(t_llist *list, t_llist_el *el, void *data);
t_llist			*ft_llist_rem_nxt(t_llist *list, t_llist_el *el, void **data);
BOOL			ft_llist_is_member(t_llist *list, void *data);

#endif
