/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:57 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/06 21:47:40 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_place(char *line)
{
	int count;
	int index;

	index = 0;
	count = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '#')
		{
			if (line[index] == line[index + 1])
				count++;
			if (line[index] == line[index + 5])
				count++;
		}
		index++;
	}
	if (count == 3 || count == 4)
		return (1);
	return (0);
}

int		check(char *line)
{
	int		index;
	int		indend;
	int		count_t;

	count_t = 0;
	indend = 4;
	if (line[20] == '\n' || line[20] == '\0')
		line[20] = '\0';
	else
		return (0);
	while (line[index] != '\0')
	{
		if (line[index] != '.' && line[index] != '#' && line[index] != '\n')
			return (0);
		if ((index != indend) && line[index] == '\n')
			return (0);
		if ((indend == index) && (line[indend] == '\n'))
			indend += 5;
		if (line[index] == '#')
			count_t += 1;
		index++;
	}
	if (count_t != 4)
		return (0);
	return (check_place(line) == 1 ? 1 : 0);
}
