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

char	*free_join(char *s1, char *s2)
{
	char	*joined_str;

	if (!s1 && !s2)
		return (NULL);
	joined_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (joined_str);
}

char	*read_files(int fd, char *buffer, char *saved)
{
	ssize_t	bytes_read;
	char	*temp;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = free_join(saved, buffer);
		if (!temp)
			return (free(saved), NULL);
		saved = temp;
		if (ft_strchr(saved, '\n'))
			break ;
	}
	if (bytes_read < 0)
		return (free(saved), NULL);
	return (saved);
}

char	*extract_line(char *saved)
{
	char	*line;
	size_t	i;

	if (!saved || !*saved)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_saved(char *saved)
{
	char	*remaining;
	size_t	i;
	size_t	j;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
		return (free(saved), NULL);
	remaining = (char *)ft_calloc(ft_strlen(saved) - i, sizeof(char));
	if (!remaining)
		return (free(saved), NULL);
	i++;
	j = 0;
	while (saved[i])
		remaining[j++] = saved[i++];
	remaining[j] = '\0';
	free(saved);
	if (!*remaining)
		return (free(remaining), NULL);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	saved = read_files(fd, buffer, saved);
	free(buffer);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	if (!line)
		return (free(saved), saved = NULL);
	saved = update_saved(saved);
	return (line);
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
