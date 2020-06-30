/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 00:17:52 by pcarolei          #+#    #+#             */
/*   Updated: 2020/06/18 16:57:54 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASSERT_H
# define FT_ASSERT_H

# include <libft.h>

# ifndef STDERR
# define STDERR 2
# endif

# ifdef FT_NDEBUG
# define FT_ASSERT(condition)
# else
# define FT_ASSERT(condition) \
if (!(condition)) \
{\
	ft_printf_fd(STDERR, "\nfailure in %s() in file %s on line %d\n", __func__, __FILE__, __LINE__);\
	exit(0);\
}
# define FT_REQUIRES(preconditions) FT_ASSERT(preconditions)
# define FT_ENSURES(postconditions) FT_ASSERT(postconditions)
# define FT_INV_CHECK(invariant_check) FT_ASSERT(invariant_check)

# endif

#endif
