# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruteflow <bruteflow@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2019/03/28 14:52:23 by bruteflow        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= scop

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

FRM_DIR	= ./frameworks/
SDL_INC	= $(FRM_DIR)SDL2.framework/Headers

LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a
LIBGLEWINC = ./frameworks/glew/include
LIBGLEW = ./frameworks/glew/lib/libGLEW.a

OD :=	./obj

OBJ	=	clean.o \
		color_1.o \
		ft_2d_str_count.o \
		ft_atof.o \
		get_next_line.o \
		init.o \
		key_functions_1.o \
		key_functions_2.o \
		key_functions_3.o \
		key_functions_4.o \
		key_functions_5.o \
		load_tga.o \
		main_errors.o \
		main_gl_buffers.o \
		main_loop.o \
		main_matrix.o \
		main_parser.o \
		main_render.o \
		main_shader.o \
		main.o \
		matrix_math_1.o \
		matrix_math_2.o \
		parser_indices.o \
		vector_math_1.o \
		vector_math_2.o

LIB = $(LIB_LIB) $(LIBGLEW)

HEADERS	= $(INC_DIR)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SDL		= -F $(FRM_DIR) -framework SDL2 -framework OpenGL
INC_OPT = -I $(LIB_INC) -I $(INC_DIR) -I $(SDL_INC) -I$(LIBGLEWINC)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c
OPTIMA	= -O3

RMF 	= rm -f
RMD		= rm -rf

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OD)
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C $(LIB_DIR)
	@mkdir -p ~/Library
	@mkdir -p ~/Library/Frameworks

	@rm -rf ~/Library/Frameworks/SDL2.framework
	@cp -R -i ./frameworks/SDL2.framework ~/Library/Frameworks

	$(CC) $(SDL) $(LIB) $^ $(OUT_OPT) $(NAME) $(OPTIMA)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	$(RMD) $(OBJ_DIR)
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re