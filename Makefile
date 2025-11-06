CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit   # macOS




SRCS = src/main.c src/ft_validation.c  
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
