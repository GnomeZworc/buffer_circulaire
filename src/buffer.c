/*
** buffer.c for buffer in /home/boufid_n/rendu/2015/piscine_synt/jetpack2Tek3
**
** Made by Nicolas Boufidjeline
** Login   <boufid_n@epitech.eu>
**
** Started on  Thu Jul  7 17:33:08 2016 Nicolas Boufidjeline
** Last update Wed Jul 13 22:43:51 2016 Nicolas Boufidjeline
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "buffer.h"

int	g_error;

int	init_buffer(t_buffer *buff)
{
  buff->buff = malloc(BUFF_LEN);
  buff->l = 0;
  buff->e = 0;
  if (buff->buff == NULL)
    return (1);
  return (0);
}

int	fd_buffer(int fd, t_buffer *buff)
{
  int	pe;
  char	c;
  int	ret;

  ret = 0;
  pe = buff->e;
  if (pe == P_MAX)
    pe = -1;
  while (pe != buff->l - 1 && (ret = read(fd, &c, 1)))
    {
      ((char *)buff->buff)[buff->e] = c;
      buff->e++;
      if (buff->e == P_MAX + 1)
	buff->e = 0;
      if (c == '\n')
	return (0);
      pe = buff->e;
      if (pe == P_MAX)
	pe = -1;
    }
  if (ret == 0)
    return (1);
  return (0);
}

char	*buffer_char(t_buffer *buff)
{
  char	*tmp;
  char	c;

  if (buff->e == buff->l)
    return (NULL);
  if (find_n(buff))
    {
      tmp = NULL;
      while ((c = ((char *)buff->buff)[buff->l]) != '\n')
	{
	  tmp = addchar(tmp, c);
	  buff->l++;
	  if (buff->l == P_MAX + 1)
	    buff->l = 0;
	}
      tmp = addchar(tmp, '\n');
      buff->l++;
      if (buff->l == P_MAX + 1)
	buff->l = 0;
      return (tmp);
    }
  return (NULL);
}

int		char_buffer(char *txt, t_buffer *buff)
{
  int		len;
  size_t	size;
  size_t	i;

  if (txt == NULL || (len = strlen(txt)) > BUFF_LEN)
    return (-1);
  size = left_size(buff);
  if (size < strlen(txt))
    return (-1);
  i = 0;
  while (i != strlen(txt))
    {
      ((char *)buff->buff)[buff->e] = txt[i];
      buff->e++;
      if (buff->e == P_MAX + 1)
	buff->e = 0;
      i++;
    }
  return (0);
}

int	buffer_fd(int fd, t_buffer *buff)
{
  char	c;
  int	ret;

  ret = -1;
  c = ((char *)buff->buff)[buff->l];
  if (fd == -1)
    return (-1);
  while (buff->e != buff->l && (ret = write(fd, &c, 1)))
    {
      buff->l++;
      if (buff->l == P_MAX + 1)
	buff->l = 0;
      if (c == '\n')
	return (0);
      c = ((char *)buff->buff)[buff->l];
    }
  if (errno == EPIPE)
    g_error = 1;
  if (ret == -1)
    return (1);
  return (0);
}
