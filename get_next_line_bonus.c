/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:29:31 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/24 23:29:35 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_safe(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*read_lines(int fd, char *buf, char **backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		buf[read_line] = '\0';
		if (*backup == NULL)
			*backup = ft_strdup("");
		if (*backup == NULL)
			return (NULL);
		char_temp = *backup;
		*backup = ft_strjoin(char_temp, buf);
		free_safe(&char_temp);
		if (*backup == NULL)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (*backup && **backup == '\0')
		return (free_safe(backup), NULL);
	return (*backup);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (backup == NULL)
		return (NULL);
	if (*backup == '\0')
		free_safe(&backup);
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backups[MAX_FDS];

	if (fd < 0 || fd >= MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = read_lines(fd, buf, &backups[fd]);
	free_safe(&buf);
	if (line == NULL)
	{
		free_safe(&backups[fd]);
		return (NULL);
	}
	backups[fd] = extract(line);
	return (line);
}
