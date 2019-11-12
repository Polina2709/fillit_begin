/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:44:29 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/06 20:05:35 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char buf[BUFF_SIZE];

    int fd = open("text.txt", O_RDONLY);
	 if (fd < 0)
	 {
		 printf("FILE NOT OPEN");
		 exit(2);
	 }
	 read(fd, buf, BUFF_SIZE);
	 buf[20] = '\0';
	 if (!(check(buf)))
	 {
		printf("%s\n", "We have more problems");
		exit(2);
	 }
	 save_coords(buf);
	 printf("%s", "Very goood");
	 return (0);
}