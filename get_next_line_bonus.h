/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:18:16 by sarajime          #+#    #+#             */
/*   Updated: 2023/10/30 10:59:09 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_and_stash(int fd, char	*stash);
char	*ft_line(char *stash);
char	*ft_clean_stash(char	*stash);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int num_bytes);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);	

#endif
