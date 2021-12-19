CC=gcc
SRCS=src/main.c\
	src/zoom.c\
	src/draw.c\
	src/key_press.c\
	src/libft_func.c\
	src/julia.c\
	src/mandelbrot.c\
	src/burning.c\
	src/atoi_double.c

OBJS		=$(SRCS:.c=.o)
NAME		=fractol
CFLAG		=-Wall -Wextra -Werror
MINI_DIR	=mlx/
MINI_NAME	=mlx/libmlx.a
LIBFLAG		=-Lmlx -lmlx -framework OpenGL -framework Appkit
RM			=rm -f
DEPSFLAGS = -MMD -MF $(@:.o=.d)

deps := $(patsubst %.o,%.d,$(OBJS))

%.o: %.c 
	$(CC) $(CFLAG) -c -o $@ $< $(DEPSFLAGS)

all: $(NAME)

$(NAME): $(MINI_NAME) $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(LIBFLAG)
-include $(deps)

$(MINI_NAME):
	@make -C $(MINI_DIR)

clean:
	@$(RM) $(OBJS) $(MINI_NAME) $(deps)
	@make clean -C $(MINI_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

