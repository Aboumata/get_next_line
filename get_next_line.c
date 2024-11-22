/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:42 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/20 16:45:54 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *buffer, char *chunk)
{
	char	*temporary;

	if (buffer == NULL)
		return (chunk);
	if (chunk == NULL)
		return (buffer);
	temporary = ft_strjoin(buffer, chunk);
	if (temporary == NULL)
		return (NULL);
	free(buffer);
	free(chunk);
	return (temporary);
}

char	*read_files(int fd, char *buffer)
{
	char	*chunk;
	ssize_t	read_bytes;

	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (chunk == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, chunk, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(chunk), free(buffer), NULL);
		chunk[read_bytes] = '\0';
		buffer = free_join(buffer, chunk);
		if (buffer == NULL)
			return (free(chunk), NULL);
		if (ft_strchr(chunk, '\n'))
			break ;
	}
	free(chunk);
	return (buffer);
}

char	*extract_lines(char *buffer)
{
	char	*lines;
	int		i;

	if (buffer == NULL || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	lines = ft_calloc(i + 2, sizeof(char));
	if (lines == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		lines[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		lines[i++] = '\n';
	lines[i] = '\0';
	return (lines);
}

char	*next_line(char *buffer)
{
	char		*left;
	int i int	j;

	if (!buffer || !*buffer)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	left = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (left == NULL)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
	{
		left[j] = buffer[i];
		i++;
		j++;
	}
	left[j] = '\0';
	free(buffer);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*txt_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_files(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	txt_line = extract_lines(buffer);
	if (txt_line == NULL)
		return (free(buffer), NULL);
	buffer = next_line(buffer);
	return (txt_line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("your_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
