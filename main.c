/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:58 by aboumata          #+#    #+#             */
/*   Updated: 2024/11/20 17:33:05 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
int main ()
{
    int fd;
    char txt[256];
    ssize_t read_buff;
    fd = open("example.txt", O_RDONLY | O_CREAT);
    while ((read_buff = read(fd, txt, 10)))
    {
        txt[read_buff] = '\0';
        printf("buff: %s\n", txt);
    }
    return 0;
}