/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:54:49 by aabdrash          #+#    #+#             */
/*   Updated: 2017/02/26 18:55:06 by aabdrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [File containing between 2 and 12 Tetriminos]");
	ft_putendl("        Note : If file contains more than 12 Tetriminos,");
	ft_putendl("               The program will run slowly.");
}
