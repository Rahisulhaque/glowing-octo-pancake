/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 10:21:55 by alcornea          #+#    #+#             */
/*   Updated: 2017/02/26 18:42:53 by aabdrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strlen(const char *str);
int				ft_isalpha(int c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);

int				ft_sqrt(int nb);

#endif
