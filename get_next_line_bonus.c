/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:17:48 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/31 11:40:16 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_and_stash(int fd, char	*stash)
{
	char	*buff;
	int		num_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	num_bytes = 1;
	while (!ft_strchr(stash, '\n') && num_bytes != 0)
	{
		num_bytes = read(fd, buff, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[num_bytes] = '\0';
		stash = ft_strjoin(stash, buff, num_bytes);
	}
	free (buff);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1 + (stash[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char	*stash)
{
	int		i;
	int		j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i++])
	{
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line (stash[fd]);
	stash[fd] = ft_clean_stash (stash[fd]);
	return (line);
}
/*int	main(void)
{
	char	*linea;

	int fd1, fd2;
	fd1 = open("f1.txt",
		O_RDONLY);
	fd2 = open("f2.txt",
		O_RDONLY);
	linea = get_next_line(fd1);
	printf("%s\n", linea);
	linea = get_next_line(fd2);
	printf("%s\n", linea);
	linea = get_next_line(fd1);
	printf("%s\n", linea);
	linea = get_next_line(fd2);
	printf("%s\n", linea);
	close(fd1);
	linea = get_next_line(fd1);
	printf("%s\n", linea);
	fd1 = open("f1.txt",
		O_RDONLY);
	linea = get_next_line(fd1);
	printf("%s\n", linea);
	linea = get_next_line(fd1);
	printf("%s\n", linea);
}*/
