/*
** buffer.h for buffer in /home/boufid_n/rendu/2015/piscine_synt/jetpack2Tek3
**
** Made by Nicolas Boufidjeline
** Login   <boufid_n@epitech.eu>
**
** Started on  Thu Jul  7 17:09:26 2016 Nicolas Boufidjeline
// Last update Wed Jul 13 22:47:59 2016 Nicolas Boufidjeline
*/

#ifndef BUFFER_H_
# define BUFFER_H_

# define BUFF_LEN 1024
# define P_MAX BUFF_LEN-1

# include <string.h>

typedef struct	s_buffer
{
  void		*buff;
  int		l;
  int		e;
}		t_buffer;

/*
** buffer_utils.c
*/
void	freebuffer(t_buffer *);
int	find_n(t_buffer *);
char	*addchar(char *, char);
size_t	left_size(t_buffer *);
int	canread(t_buffer *);

/*
** buffer.c
*/
int	init_buffer(t_buffer *);
int	fd_buffer(int, t_buffer *);
char	*buffer_char(t_buffer *);
int	char_buffer(char *, t_buffer *);
int	buffer_fd(int, t_buffer *);

extern int	g_error;

#endif /* !BUFFER_H_ */
