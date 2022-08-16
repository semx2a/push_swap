# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/02/28 18:55:35 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	:= push_swap

BNAME	:= checker

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PATHS::

ODIR	:= objs

BODIR	:= objs_bonus

SDIR	:= srcs

BDIR	:= bonus

IDIR	:= inc

LDIR 	:= libft

PFDIR	:= ft_printf

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SRCS	:= push_swap.c ps_stack.c ps_utils.c ps_allocate.c ps_parsing.c\
ps_presort.c ps_a.c ps_b.c ps_ab.c ps_algo.c ps_compare.c ps_array.c\
ps_update.c ps_checkup.c ps_bestmv.c\

OBJS	= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BONUS::

BSRCS	:= checker_bonus.c ch_a_bonus.c ch_ab_bonus.c ch_b_bonus.c\
ch_parsing_bonus.c ch_stack_bonus.c ch_update_bonus.c ch_utils_bonus.c\
get_next_line.c get_next_line_utils.c

BOBJS	= $(addprefix $(BODIR)/,$(BSRCS:.c=.o))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		:= gcc

WFLAGS	:= -MMD -Wall -Wextra -Werror

GFLAG	:= -g3

SANFLAG	:= -fsanitize=address

AR		:= ar

ARFLAGS	:= rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HEADERS::

INC		:= push_swap.h get_next_line.h

LINC	= $(addprefix $(LDIR)/, $(IDIR))

PFINC	= $(addprefix $(PFDIR)/, $(IDIR))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIBFT	:= true

LIB		:= libft.a

LIBFT_COMPLETE	= $(addprefix $(LDIR)/, ${LIB})

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PRINTF	:= true

PRINTF	:= libftprintf.a

PRINTF_COMPLETE	= $(addprefix $(PFDIR)/, $(PRINTF))

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
GREEN		=	\033[0;92m
BGREEN		=	\033[1;92m
ORANGE  	=	\033[0;33m
NO_COLOR	=	\033[m
PURPLE		=	\033[0;35m
BPURPLE		=	\033[1;35m
BCYAN		=	\033[1;36m
ICYAN		=	\033[3;36m

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARAMS::

INCLUDE_FLAGS	=	$(addprefix -I , $(IDIR))

ifeq ($(IS_LIBFT),true)
	INCLUDE_FLAGS	+=	$(addprefix -I , $(LINC))
endif

ifeq ($(IS_PRINTF), true)
	INCLUDE_FLAGS	+= $(addprefix -I , $(PFINC))
endif

DEPS	= $(OBJS:.o=.d)
BDEPS	= $(BOBJS:.o=.d)

vpath %.c $(SDIR)\
		$(BDIR)
vpath %.o $(ODIR)\
		$(BODIR)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MANDATORY::

all:		header lib h2 message $(NAME)

$(ODIR)/%.o:	%.c 
	@$(CC) $(WFLAGS) $(GFLAGS) $(SANFLAG) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(GREEN)compilation:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(NAME):	 $(OBJS)	
	@$(CC) $(WFLAGS) $(GFLAGS) $(SANFLAG) $(OBJS) $(LIBFT_COMPLETE) $(PRINTF_COMPLETE) -o $(NAME)
	@echo "$(GREEN)mandatory exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(OBJS):	| $(ODIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "$(GREEN)objs folder:\t\t\t\t\t\t[OK]$(NO_COLOR)"

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BONUS::

bonus:		header lib h3 message_b $(BNAME)

$(BODIR)/%.o:	%.c 
	@$(CC) $(WFLAGS) $(GFLAGS) $(SANFLAG) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(GREEN)bonus compilation:\t\t\t\t\t[OK]$(NO_COLOR)"

$(BNAME):		$(BOBJS)
	@$(CC) $(GFLAGS) $(SANFLAG) $(BOBJS) $(LIBFT_COMPLETE) $(PRINTF_COMPLETE) -o $(BNAME)
	@echo "$(GREEN)bonus exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(BOBJS):	| $(BODIR)

$(BODIR):
	@mkdir -p $(BODIR)
	@echo "$(GREEN)objs_bonus folder:\t\t\t\t\t[OK]$(NO_COLOR)"

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

lib:
	@make -C $(LDIR) --quiet
	@make -C $(PFDIR) --quiet

lib_debug:
	@make -C $(LDIR) --quiet debug
	@make -C $(PFDIR) --quiet debug

update: header fclean
	@git pull

push:	header fclean
	@echo "$(GREEN)"
	@git add .
	@git commit --quiet
	@git push --quiet
	@echo "$(GREEN)git push:\t\t\t\t\t\t[OK]$(NO_COLOR)"

clean:	header
ifneq ($(wildcard ./$(ODIR)),)
	@make -C $(LDIR) --quiet clean	
	@make -C $(PFDIR) --quiet clean
	@rm -rf $(ODIR)
	@rm -rf $(BODIR)
	@echo "$(ORANGE)objs folder:\t\t\t\t\t\t[RM]$(NO_COLOR)"
else
	@make -C $(LDIR) --quiet clean
	@make -C $(PFDIR) --quiet clean
	@rm -f $(wildcard *.o)
	@rm -f $(wildcard *.d)
	@echo "$(ORANGE)obj files:\t\t\t\t\t\t[RM]$(NO_COLOR)"
endif

fclean:	header clean
	@make -C $(LDIR) --quiet fclean
	@make -C $(PFDIR) --quiet fclean
	@rm -f $(NAME)
	@rm -f $(BNAME)
	@echo "$(ORANGE)$(NAME) executable:\t\t\t\t\t[RM]$(NO_COLOR)"

header:
	@echo "$(BPURPLE)"
	@echo "   ______________________________________________________"
	@echo "  /\     __________    ________    ___   ___    _______  \ "
	@echo " /  \   /\         \  /\   __  \  /\  \ /\  \  /\  ____\  \ "
	@echo "/    \  \ \  \ _/\  \ \ \   __  \ \ \  \ /_ /_ \ \  _\_/_  \ "
	@echo "\     \  \ \__\_/ \__\ \ \__\-\__\ \ \__\  \__\ \ \______\  \ "
	@echo " \     \  \/__/  \/__/  \/__/ /__/  \/__/ \/__/  \/______/   \ "
	@echo "  \     \_________ ___________________________________________\ "
	@echo "   \    /                                                     / "
	@echo "    \  /                   $(SCYAN) S E O Z C A N \
$(NO_COLOR)$(BPURPLE)            ____   / "
	@echo "     \/______________________________________________/\   \_/ "
	@echo "                                                     \ \___\ "
	@echo "                                                      \/___/ "
	@echo "$(NO_COLOR)"

h2:
	@echo "\n$(BPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::PUSH_SWAP::\n$(NO_COLOR)"

h3:
	@echo "\n$(BPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::::CHECKER::\n$(NO_COLOR)"

message:
	@make -q $(NAME) && echo "$(BGREEN)All files are already up to date$(NO_COLOR)" || true

message_b:
	@make -q $(BNAME) && echo "$(BGREEN)All bonus files are already up to date$(NO_COLOR)" || true

re:		header fclean all 

-include $(DEPS)
-include $(BDEPS)

.PHONY:	all bonus clean fclean re push update o_dir h1 h2 header 
