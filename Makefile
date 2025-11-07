CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit   # macOS




SRCS = src/main.c src/ft_validation.c   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
src/ft_start_work.c

OBJDIR = obj
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)



NAME = cub3D

 
 
all: $(NAME)

# $(MLXFLAGS) ->  -o $(NAME) # $(MLXFLAGS)
$(NAME): $(OBJS)  
	$(CC) $(CFLAGS) $(OBJS)   -o $(NAME)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
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
