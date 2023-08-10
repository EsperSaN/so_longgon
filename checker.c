/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:10:25 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/08 21:14:17 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_all_data(int fd)
{
	char	*buff;
	char	*ret;
	int		read_count;
	char	*tmp;

	buff = ft_calloc(sizeof(char), (READ_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = ft_calloc(sizeof(char), 1);
	if (!ret)
		return (NULL);
	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buff, READ_SIZE);
		if (read_count == -1)
		{
			free(ret);
			free(buff);
			return (NULL);
		}
		buff[read_count] = '\0';
		tmp = ret;
		ret = ft_strjoin(ret, buff);
		free(tmp);
	}
	free(buff);
	return (ret);
}

int	is_char_in_set(char	*maps_line, char	*allowlist)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	find = 0;
	while (maps_line[i])
	{
		j = 0;
		find = 0;
		while (allowlist[j])
		{
			if (maps_line[i] == allowlist[j])
				find = 1;
			j++;
		}
		if (find == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_double(char	*str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c && *(str++) && *(str++) == c)
			return (1);
		str++;
	}
	return (0);
}

char	**file_init(char	*maps)
{
	char	*line_of_data;
	char	**two_array;
	int		fd;

	if (!is_extention(maps, ".ber"))
	{
		ft_putstr_fd("Error Check your maps extention\n", 2);
		return (NULL);
	}
	fd = open(maps, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_of_data = get_all_data(fd);
	if (!line_of_data)
		return (NULL);
	if (is_double(line_of_data, '\n')
		|| !is_char_in_set(line_of_data, "CPE01\n") || *line_of_data == '\n'
		|| is_element_exceed(line_of_data))
	{
		free(line_of_data);
		return (NULL);
	}
	two_array = ft_split(line_of_data, '\n');
	free(line_of_data);
	if (!two_array)
		return (NULL);
	return (two_array);
}

int	is_all_char(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	double_a_check(char	**maps, int col_n)
{
	int	width;
	int	hight;
	int	len;

	if (!maps)
		return (1);
	width = ft_strlen(maps[0]);
	hight = 0;
	while (maps[hight])
	{
		len = ft_strlen(maps[hight]);
		if (len != width || !is_char_in_set(maps[hight], "CPE01\n"))
			return (1);
		hight++; 
	}
	if (!is_all_char(maps[0], '1') || !is_all_char(maps[hight - 1], '1'))
		return (1);
	hight = 0;
	while (maps[hight])
	{
		if (maps[hight][0] != '1' || maps[hight][width - 1] != '1')
			return (1);
		hight++;
	}
	if (!flood_fill_checker(maps, col_n))
		return (1);
	return (0);
}

void	print_map(char **maps)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x])
		{
			printf("[%c]", maps[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
