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
#define BUFFER_SIZE 10

char *ft_free_buffer(char *read_byte, char* buffer)
{
    char *temporary;

    temporary = ft_strjoin(read_byte, buffer);
    free(read_byte);
    return (temporary);
}

char *read_lines(int fd, char* read_line)
{
    char *buffer;
    ssize_t read_byte;

    if (read_line == NULL)
        return (NULL);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    read_byte = 1;
    while (read_byte > 0)
    {
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte <= 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_byte] = '\0';
        read_line =  ft_free_buffer(read_line, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (read_line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 ||  BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_lines(fd, buffer);
    if (buffer == NULL)
        return (NULL);

    return ;
}
