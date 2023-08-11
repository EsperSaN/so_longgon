/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:23:31 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 11:10:18 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_extention(char	*str, char *extention)
{
	int	len;
	int	ex_len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	ex_len = ft_strlen(extention);
	if (len < ex_len)
		return (0);
	len = len - 1;
	ex_len = ex_len - 1;
	while (extention[ex_len])
	{
		if (str[len] != extention[ex_len])
			return (0);
		len--;
		ex_len--;
	}
	return (1);
}

static int	is_double(char	*str, char c)
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

static char	*read_file(int fd)
{
	char	*buff;
	char	*ret;
	int		read_count;
	char	*tmp;

	buff = ft_calloc(sizeof(char), (READ_SIZE + 1));
	ret = ft_calloc(sizeof(char), 1);
	if (!ret || !buff)
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

char	**file_init(char	*maps)
{
	char	*line_of_data;
	char	**two_array;
	int		fd;

	if (!is_extention(maps, ".ber"))
		return (NULL);
	fd = open(maps, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_of_data = read_file(fd);
	if (!line_of_data)
		return (NULL);
	if (is_double(line_of_data, '\n') 
		|| !is_char_in_set(line_of_data, "CPE01\n") 
		|| *line_of_data == '\n' || is_element_exceed(line_of_data))
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
