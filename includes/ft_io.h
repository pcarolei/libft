/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:27:17 by pcarolei          #+#    #+#             */
/*   Updated: 2020/06/12 16:21:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# define BUFF_SIZE 32

typedef struct	s_fd_list
{
	int					fd;
	char				*fd_str;
	char				*tmp;
	struct s_fd_list	*next;
}				t_fd_list;

# define STDIN	0
# define STDOUT	1
# define STDERR	2

int				get_next_line(const int fd, char **line);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
