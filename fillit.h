/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:03:39 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/11/06 20:32:52 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>

typedef	struct	s_tetri	t_tetri;
struct s_tetri
{
	char				name;
	int					coords[8];
	struct s_tetri		*next;
};

int 	check(char *line);
int		check_place(char *line);
t_tetri    save_coords(char *line);
t_tetri    find_min_coords(t_tetri result);
t_tetri     replace_coords(t_tetri result, int min_x, int min_y);

#endif
