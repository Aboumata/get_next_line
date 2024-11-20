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
    {
        i++;
    }
    return (i);
}

char	*ft_strdup(const char *src)
{
    int		i;
    char	*ptr;
    size_t	len_src;

    len_src = ft_strlen(src);
    ptr = (char *)malloc(len_src + 1);
    if (ptr == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (src[i] != '\0')
    {
        ptr[i] = src[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;
    size_t	len_src;

    len_src = 0;
    while (src[len_src])
        len_src++;
    if (dstsize == 0)
        return (len_src);
    i = 0;
    while (src[i] != '\0' && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len_src);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t	i;
    size_t	len_src;
    size_t	len_dst;

    len_src = ft_strlen(src);
    if (dstsize == 0)
        return (len_src);
    len_dst = ft_strlen(dst);
    if (dstsize <= len_dst)
        return (dstsize + len_src);
    i = 0;
    while (src[i] != '\0' && (len_dst + i) < dstsize - 1)
    {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return (len_dst + len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t	len_s1;
    size_t	len_s2;
    size_t	size;
    char	*concat_strs;

    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
        return (ft_strdup(s2));
    if (s2 == NULL)
        return (ft_strdup(s1));
    len_s2 = ft_strlen(s2);
    len_s1 = ft_strlen(s1);
    size = len_s1 + len_s2 + 1;
    concat_strs = (char *)malloc(size);
    if (concat_strs == NULL)
        return (NULL);
    ft_strlcpy(concat_strs, s1, len_s1 + 1);
    ft_strlcat(concat_strs, s2, size);
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
