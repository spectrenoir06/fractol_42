# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adoussau <antoine@doussaud.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 17:50:09 by adoussau          #+#    #+#              #
#    Updated: 2015/02/03 19:39:58 by adoussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

HDRDIR	= header
SRCDIR	= src
OBJDIR	= obj
CUDASRC	= cudasrc
CUDAHDR	= cudaheader
CUDAOBJ	= cudaobj
LIBHDR	= libft/includes
LIBDIR	= libft/
LIBFT	= $(LIBDIR)libft.a

SRC		=	main.c			\
			color.c			\
			cpu_frac.c		\
			gpu_frac.c		\
			hook.c			\
			init.c			\
			lib2d.c


UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX = mlx/libmlx_Linux.a
endif

ifeq ($(UNAME_S),Darwin)
	MLX = mlx/libmlx_intel-mac.a
endif

ifeq ($(UNAME_S),Darwin)
	CSRC	=	mandelbrot.cu	\
				julia.cu		\
				douady.cu
	SCUDA			=	$(patsubst %.cu,$(CUDAOBJ)/%.o,$(CSRC))

	CC				= /Developer/NVIDIA/CUDA-7.0/bin/nvcc
	CUDA			= /Developer/NVIDIA/CUDA-7.0
	NVCC_C			= -ccbin /usr/bin/clang -m64 -Xcompiler -arch -Xcompiler x86_64 -Xcompiler -stdlib=libstdc++
	NVCC_FRAMEWORK	= -Xlinker -framework,OpenGL -Xlinker -framework,AppKit
	NVCC_LIB		= -Xlinker -rpath -Xlinker /Developer/NVIDIA/CUDA-7.0/lib
	NVCC_VCODE		= -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=\"sm_35,compute_35\"
	NVCC_FLAGS		= -Xcompiler -Wextra
else
	CC = gcc
endif


OBJ		=	$(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

NORMINETTE	= ~/project/colorminette/colorminette

FLAGS			= -Wall -Werror -Wextra -iquote header #-framework OpenGL -framework AppKit
LIB				= -I /opt/X11/include/

$(shell mkdir -p $(OBJDIR) $(CUDAOBJ))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(SCUDA)
	$(CC) -O3 $(NVCC_C) $(NVCC_FRAMEWORK) $(NVCC_LIB) -o $(NAME) $(OBJ) $(LIBFT) $(SCUDA) $(LIB) $(MLX) -L/usr/X11/lib -lX11 -lXext

$(LIBFT):
	make -C $(LIBDIR) libft.a

$(CUDAOBJ)/%.o: $(CUDASRC)/%.cu
	$(CC) -O3 $(NVCC_C) $(NVCC_VCODE) $(NVCC_FLAGS) -I $(CUDA)/include -I header -I $(CUDAHDR) -o $@ -c $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -O3 $(FLAGS) $(LIB) -I libft/includes -iquote $(LIBDIR) -iquote $(CUDAHDR) -o $@ -c $<

.PHONY: clean fclean re norme

norme:
	@make -C libft/ norme
	@$(NORMINETTE) $(SRCDIR)/ $(HDRDIR)/

clean:
	rm -f $(OBJ) $(SCUDA)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean
	make
