# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 07:53:44 by pcarolei          #+#    #+#              #
#    Updated: 2020/06/30 05:46:04 by pcarolei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PLACE AT THE TOP OF YOUR MAKEFILE
#---------------------------------
# Progress bar defs
#--------------------------------
#  words = count the number of words
ifneq ($(words $(MAKECMDGOALS)),1) # if no argument was given to make...
.DEFAULT_GOAL = all # set the default goal to all
#  http://www.gnu.org/software/make/manual/make.html
#  $@ = target name
#  %: = last resort recipe
#  --no-print-directory = don't print enter/leave messages for each output grouping
#  MAKEFILE_LIST = has a list of all the parsed Makefiles that can be found *.mk, Makefile, etc
#  -n = dry run, just print the recipes
#  -r = no builtin rules, disables implicit rules
#  -R = no builtin variables, disables implicit variables
#  -f = specify the name of the Makefile
%:                   # define a last resort default rule
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST)) # recursive make call,
else
ifndef ECHO
#  execute a dry run of make, defining echo beforehand, and count all the instances of "COUNTTHIS"
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
#  eval = evaluate the text and read the results as makefile commands
N := x
#  Recursively expand C for each instance of ECHO to count more x's
C = $(words $N)$(eval N := x $N)
#  Multipy the count of x's by 100, and divide by the count of "COUNTTHIS"
#  Followed by a percent sign
#  And wrap it all in square brackets
ECHO = echo -ne "\r [`expr $C '*' 100 / $T`%]"
endif
#------------------
# end progress bar
#------------------

#	Libft Makefile

#	Programs
AR ?= ar
CC ?= clang
ARFLAGS = rc
RANLIB ?= ranlib
#	Compiler settings
CFLAGS = -c -Wall -Werror -Wextra -I$(INC_DIR)
TEST_FLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
#	Name of compiled library
LIBFT := libft.a
#	Source files
INC_DIR := ./includes
SRC_DIR := ./src
HEADERS := $(INC_DIR)/ft_bool.h \
		  $(INC_DIR)/ft_conv.h \
		  $(INC_DIR)/ft_ctype.h \
		  $(INC_DIR)/ft_darr.h \
		  $(INC_DIR)/ft_io.h \
		  $(INC_DIR)/ft_lists.h \
		  $(INC_DIR)/ft_math.h \
		  $(INC_DIR)/ft_memctl.h \
		  $(INC_DIR)/ft_printf.h \
		  $(INC_DIR)/ft_regex.h \
		  $(INC_DIR)/ft_strings.h \
		  $(INC_DIR)/ft_utils.h \
		  $(INC_DIR)/ft_assert.h \
		  $(INC_DIR)/ft_graph.h \
		  $(INC_DIR)/libft.h
		  # $(INC_DIR)/ft_hashtable.h \

CONV		:= $(SRC_DIR)/ft_conv
CTYPE		:= $(SRC_DIR)/ft_ctype
DARR		:= $(SRC_DIR)/ft_darr
# HASHTABLE	:= $(SRC_DIR)/ft_hashtable
IO			:= $(SRC_DIR)/ft_io
LISTS		:= $(SRC_DIR)/ft_lists
MATH		:= $(SRC_DIR)/ft_math
MEMCTL		:= $(SRC_DIR)/ft_memctl
PRINTF		:= $(SRC_DIR)/ft_printf
REGEX		:= $(SRC_DIR)/ft_regex
STRINGS		:= $(SRC_DIR)/ft_strings
UTILS		:= $(SRC_DIR)/ft_utils
GRAPH		:= $(SRC_DIR)/ft_graph

# $(HASHTABLE)/ft_ht_destroy.c \
# $(HASHTABLE)/ft_ht_get.c \
# $(HASHTABLE)/ft_ht_init.c \
# $(HASHTABLE)/ft_ht_insert.c \
# $(HASHTABLE)/ft_ht_remove.c \

SRCS := $(CTYPE)/ft_isalnum.c \
$(CTYPE)/ft_isalpha.c \
$(CTYPE)/ft_isascii.c \
$(CTYPE)/ft_isdigit.c \
$(CTYPE)/ft_isprint.c \
$(CTYPE)/ft_isspace.c \
$(CTYPE)/ft_toupper.c \
$(CTYPE)/ft_tolower.c \
\
$(CONV)/ft_atoi.c \
$(CONV)/ft_itoa.c \
$(CONV)/ft_itoa_base.c \
$(CONV)/ft_char_to_str.c \
$(CONV)/ft_ctlchar_to_str.c \
\
$(GRAPH)/ft_graph_init.c \
$(GRAPH)/ft_graph_destroy.c \
$(GRAPH)/ft_graph_ins_vrtx.c \
$(GRAPH)/ft_graph_rem_vrtx.c \
$(GRAPH)/ft_graph_ins_edge.c \
$(GRAPH)/ft_graph_rem_edge.c \
\
$(DARR)/ft_darr_add.c \
$(DARR)/ft_darr_del.c \
$(DARR)/ft_darr_ext.c \
$(DARR)/ft_darr_get.c \
$(DARR)/ft_darr_init.c \
$(DARR)/ft_darr_join.c \
$(DARR)/ft_darr_set.c \
$(DARR)/ft_darr_shr.c \
\
$(MATH)/ft_abs.c \
$(MATH)/ft_sqrt.c \
$(MATH)/ft_iterative_factorial.c \
$(MATH)/ft_recursive_factorial.c \
$(MATH)/ft_max.c \
$(MATH)/ft_min.c \
$(MATH)/ft_pow.c \
$(MATH)/ft_sign.c \
$(MATH)/ft_complex.c \
\
$(MEMCTL)/ft_swap.c \
$(MEMCTL)/ft_free2.c \
$(MEMCTL)/ft_bzero.c \
$(MEMCTL)/ft_memalloc.c \
$(MEMCTL)/ft_memccpy.c \
$(MEMCTL)/ft_memchr.c \
$(MEMCTL)/ft_memcmp.c \
$(MEMCTL)/ft_memcpy.c \
$(MEMCTL)/ft_memdel.c \
$(MEMCTL)/ft_memmove.c \
$(MEMCTL)/ft_memrchr.c \
$(MEMCTL)/ft_memset.c \
\
$(IO)/ft_gnl.c \
$(IO)/ft_putchar.c \
$(IO)/ft_putchar_fd.c \
$(IO)/ft_putendl.c \
$(IO)/ft_putendl_fd.c \
$(IO)/ft_putnbr.c \
$(IO)/ft_putnbr_fd.c \
$(IO)/ft_putstr.c \
$(IO)/ft_putstr_fd.c \
\
$(STRINGS)/ft_strcat.c \
$(STRINGS)/ft_strchr.c \
$(STRINGS)/ft_strclr.c \
$(STRINGS)/ft_strcmp.c \
$(STRINGS)/ft_strcpy.c \
$(STRINGS)/ft_strdel.c \
$(STRINGS)/ft_strdup.c \
$(STRINGS)/ft_strequ.c \
$(STRINGS)/ft_striter.c \
$(STRINGS)/ft_striteri.c \
$(STRINGS)/ft_strjoin.c \
$(STRINGS)/ft_strjoinfree.c \
$(STRINGS)/ft_strlcat.c \
$(STRINGS)/ft_strlen.c \
$(STRINGS)/ft_strmap.c \
$(STRINGS)/ft_strmapi.c \
$(STRINGS)/ft_strncat.c \
$(STRINGS)/ft_strncmp.c \
$(STRINGS)/ft_strncpy.c \
$(STRINGS)/ft_strnequ.c \
$(STRINGS)/ft_strnew.c \
$(STRINGS)/ft_strnstr.c \
$(STRINGS)/ft_strrchr.c \
$(STRINGS)/ft_strreplace.c \
$(STRINGS)/ft_strsplit.c \
$(STRINGS)/ft_strstr.c \
$(STRINGS)/ft_strsub.c \
$(STRINGS)/ft_strtrim.c \
$(STRINGS)/ft_strtrimc.c \
$(STRINGS)/ft_str_char_prepend.c \
$(STRINGS)/ft_str_rev.c \
$(STRINGS)/ft_str_tolower.c \
$(STRINGS)/ft_strcharcnt.c \
\
$(LISTS)/ft_llist_dstr.c \
$(LISTS)/ft_llist_init.c \
$(LISTS)/ft_llist_ins_nxt.c \
$(LISTS)/ft_llist_rem_nxt.c \
$(LISTS)/ft_llist_is_member.c \
$(LISTS)/ft_lst_get_length.c \
$(LISTS)/ft_lstadd.c \
$(LISTS)/ft_lstaddl.c \
$(LISTS)/ft_lstdel.c \
$(LISTS)/ft_lstdelone.c \
$(LISTS)/ft_lstiter.c \
$(LISTS)/ft_lstmap.c \
$(LISTS)/ft_lstnew.c \
$(LISTS)/ft_lstrem.c \
\
$(REGEX)/ft_regex.c \
\
$(UTILS)/ft_get_number_len.c \
$(UTILS)/ft_get_hex_len.c \
$(UTILS)/ft_swap_vptr.c \
$(UTILS)/ft_hash_pjw.c \
\
$(PRINTF)/ft_float_to_str.c \
$(PRINTF)/ft_printf.c \
$(PRINTF)/handler.c \
$(PRINTF)/handler2.c \
$(PRINTF)/handler3.c \
$(PRINTF)/handler4.c \
$(PRINTF)/handler5.c \
$(PRINTF)/handler_flags.c \
$(PRINTF)/handler_flags2.c \
$(PRINTF)/handler_flags3.c \
$(PRINTF)/handler_flags4.c \
$(PRINTF)/handler_precision_num.c \
$(PRINTF)/handler_precision_s.c \
$(PRINTF)/handler_width.c \
$(PRINTF)/num_to_bits.c \
$(PRINTF)/parse_date.c \
$(PRINTF)/parse_date2.c \
$(PRINTF)/parser.c \
$(PRINTF)/bignum.c \
$(PRINTF)/bignum2.c \
$(PRINTF)/bits_to_epf.c \
$(PRINTF)/bits_to_epf2.c \
$(PRINTF)/bits_to_numstr.c \
$(PRINTF)/bits_to_numstr2.c \
$(PRINTF)/colorize.c \
$(PRINTF)/colorize2.c \
$(PRINTF)/dec_to_hex_str.c \
$(PRINTF)/float_round.c

OBJ_DIR := ./obj
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(patsubst %.c,%.o,$(SRCS)))

#	Phony targets (target which is not a filename)
.PHONY: all clean fclean re
#	delete any target whose build sequence completes with a non-zero return status
.DELETE_ON_ERROR:

all: $(OBJS) $(HEADERS) $(LIBFT)
	@$(ECHO) All done

$(LIBFT):
	$(AR) $(ARFLAGS) $(LIBFT) $(OBJS)
	$(RANLIB) $(LIBFT)
	@$(ECHO) Linking done

#	Шаблонные правила(pattern rules)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(ECHO) Compiling $@
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@find . -name \*.o -type f -delete
	@echo "Clean done!"

fclean: clean
	@rm -rf $(LIBFT)
	@echo "Full clean done!"

re: fclean all

endif
