/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:37 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/20 17:32:40 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	if (num != 0 && total_size / num != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	char	*concat_strs;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	size = ft_strlen(s2) + ft_strlen(s1) + 1;
	concat_strs = (char *)malloc(size);
	if (concat_strs == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		concat_strs[i++] = *s1++;
	while (*s2)
		concat_strs[i++] = *s2++;
	concat_strs[i] = '\0';
	return (concat_strs);
}

char	*ft_strchr(const char *string, int c)
{
	int				i;
	unsigned char	c_char;

	c_char = (unsigned char)c;
	i = 0;
	while (string[i] != '\0')
	{
		if ((unsigned char)string[i] == c_char)
			return ((char *)string + i);
		i++;
	}
	if (c_char == '\0')
		return ((char *)string + i);
	return (NULL);
}
