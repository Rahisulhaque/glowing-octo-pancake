/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhaque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:11:18 by rhaque            #+#    #+#             */
/*   Updated: 2017/09/20 16:11:22 by rhaque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [File containing between 2 and 12 Tetriminos]");
	ft_putendl("        Note : If file contains more than 12 Tetriminos,");
	ft_putendl("               The program will run slowly.");
}
