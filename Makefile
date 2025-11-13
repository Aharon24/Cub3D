CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iinclude
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd





SRCS = src/main.c src/ft_validation.c   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
src/ft_start_work.c src/ft_parsing.c src/ft_set_up_path.c src/ft_set_up_path_2.c 

 
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = cub3D

all: $(NAME)

$(NAME):$(LIBFT) $(OBJS)  
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME) $(MLXFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 


clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

 
.PHONY: all clean fclean re bonus
