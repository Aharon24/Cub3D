CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -Iinclude
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd





SRCS = src/main.c src/ft_validation.c   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
src/ft_start_work.c src/ft_parsing.c
 
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)


NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)  
	$(CC) $(CFLAGS) $(OBJS)   -o $(NAME) $(MLXFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


 
$(OBJDIR):
	mkdir -p $(OBJDIR)


clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C   clean

fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	$(MAKE) -C  fclean

re: fclean all

 
.PHONY: all clean fclean re bonus
