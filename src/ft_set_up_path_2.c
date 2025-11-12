#include "cub3D.h"

void    ft_split_check(char *line, t_cube **st)
{
    char **arr;
	char c;

	c = 0;
	printf("%s\n",line);
    arr = ft_split(line, ' ');
	if ((ft_strlen(arr[0]) == 1) && arr[0][0] == 'C')
	    ft_check_floor_ceiling(st,arr[1],arr[0][0]);
	else if ((ft_strlen(arr[0]) == 1) && arr[0][0] == 'F')
	    ft_check_floor_ceiling(st,arr[1],arr[0][0]);
	else if ((ft_strncmp(arr[0],"NO",2)== 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1],st);
	else if ((ft_strncmp(arr[0],"SO",2)== 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1],st);
	else if ((ft_strncmp(arr[0],"WE",2)== 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1],st);
	else if ((ft_strncmp(arr[0],"EA",2)== 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1],st);
	else
	{
		(*st)->path_check = 1;
		ft_error_file_path();
		printf("%s777\n",line);
		///free map **
		return ;
	}
    ///free(arr);
    ///free(line);
}

int	ft_check_valid_map(char *str , t_cube *st)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
			i++;
		else if(str[i] == 'S' || str[i] == 'N' || str[i] == 'W' || str[i] == 'E' || str[i] == ' ' || str[i] == '\n')
			i++;
		else if (str[i] == 's' || str[i] == 'n' || str[i] == 'w' || str[i] == 'e' || str[i] == ' ' || str[i] == '\n')
			i++;
		else
		{
			st->main_map_check = 1;
			return (0);
		}
	}
	return (1);
} 


// void	ft_creat_main_map(int i, t_cube **st)
// {
// 	int	j;
// 	int	len;

// 	len = 0;
// 	j = 0;
// 	//
// 	while ((*st)->c_map[i])
// 	{
// 		if (ft_check_valid_map((*st)->c_map[i],*st) == 0)
// 		{
// 			printf("in if");
// 			printf("Error\n");
// 			printf("wrong map in map you can use (0,1,N,W,S,E or n,w,s,e and ' ')\n line %d",i);
// 			return ;
// 		}
// 		j++;
// 		i++;
// 	}
// 	// (*st)->Normalayz_map = malloc (sizeof(char *) * (j + 1));
// 	// i = 0;
// 	// j = 0;
// 	// while ((*st)->c_map[i])
// 	// {
// 	// 	(*st)->Normalayz_map[j] = ft_strdup((*st)->c_map[i]);
// 	// 	i++;
// 	// 	j++;
// 	// }
// 	// (*st)->Normalayz_map[j] = NULL;
// 	// j = 0;
// 	// while ((*st)->Normalayz_map[j])
// 	// {
// 	// 	printf("map ! - > %s\n",(*st)->Normalayz_map[j]);
// 	// 	j++;
// 	// }
	
// }
/////x


/////

void	ft_check_floor_ceiling(t_cube **st, char *str, char letter)
{
	char **line;
	int i;
	int j;


//??????????????????????????????????????
	i = 0;
	line = ft_split(str,',');
	// while(line[i])
	// {
	// 	if (line[i][j] >= '1')
	// 	printf("%s\n",line[i]);
	// 	i++;
	// }
	//i = 0;
	while(line[i])
		i++;
	if (i != 3)
	{
		printf("Error\n");
		printf("you must write 3 number or numbers should be separated ',' ! ->  %s" ,str);
		(*st)->color_check = 1;
		return ;
	}
	if (letter == 'C')
	{
		(*st)->co.c_1 = ft_atoi(line[0]);
		(*st)->co.c_2 = ft_atoi(line[1]);
		(*st)->co.c_3 = ft_atoi(line[2]);
		if (ft_chesk_color_number((*st)->co.c_1,(*st)->co.c_2,(*st)->co.c_3) == -1)
		{
			(*st)->color_check = 1;
			return ;
		}
	}
	else if(letter == 'F')
	{
		(*st)->co.f_1 = ft_atoi(line[0]);
		(*st)->co.f_2 = ft_atoi(line[1]);
		(*st)->co.f_3 = ft_atoi(line[2]);
		if (ft_chesk_color_number((*st)->co.f_1,(*st)->co.f_2,(*st)->co.f_3) == -1)
		{
			(*st)->color_check = 1;
			return ;
		}
	}

}
