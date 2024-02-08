ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME = push_swap

ifeq ($(MAKECMDGOALS), bonus)
	NAME = checker
endif

UNAME = $(shell uname)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC	= 	$Sps_ab.c \
		$Sps_a.c \
		$Sps_algo.c \
		$Sps_allocate.c \
		$Sps_array.c \
		$Sps_b.c \
		$Sps_bestmv.c \
		$Sps_checkup.c \
		$Sps_compare.c \
		$Sps_parsing.c \
		$Sps_presort.c \
		$Sps_stack.c \
		$Sps_update.c \
		$Spush_swap.c

ifeq ($(MAKECMDGOALS), bonus)
	SRC = $Sch_ab_bonus.c \
		$Sch_a_bonus.c \
		$Sch_b_bonus.c \
		$Schecker_bonus.c \
		$Sch_parsing_bonus.c \
		$Sch_stack_bonus.c \
		$Sch_update_bonus.c \
		$Sch_utils_bonus.c \
		$Sget_next_line.c \
		$Sget_next_line_utils.c
endif

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	gcc

ifneq ($(UNAME), Darwin)
CC	=	clang
endif

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIB	= 	true

LIB		= 	$Llibft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PTF	= 	true

PTF		= 	$Plibftprintf.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MLX	= 	false

MLX		= 	$Mlibmlx_$(UNAME).a

endif