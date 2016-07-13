/*
** buffer_utils.c for buffer_utils in /home/boufid_n/rendu/2015/
**
** Made by Nicolas Boufidjeline
** Login   <boufid_n@epitech.eu>
**
** Started on  Fri Jul  8 00:27:44 2016 Nicolas Boufidjeline
** Last update Wed Jul 13 22:47:38 2016 Nicolas Boufidjeline
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "buffer.h"

int		canread(t_buffer *buff)
{
  return (buff->l != buff->e);
}

void		freebuffer(t_buffer *buff)
{
  free(buff->buff);
}

size_t		left_size(t_buffer *buff)
{
  size_t	size;

  if (buff->l > buff->e)
    size = buff->l - buff->e - 1;
  if (buff->l == buff->e)
    size = P_MAX;
  if (buff->l < buff->e)
    size = P_MAX - (buff->e - buff->l);
  return (size);
}

int	find_n(t_buffer *buff)
{
  int	l;

  l = buff->l;
  while (l != buff->e)
    {
      if (((char *)buff->buff)[l] == '\n')
	return (1);
      l++;
      if (l == P_MAX + 1)
	l = 0;
    }
  return (0);
}

char	*addchar(char *tmp, char c)
{
  char	*ret;
  int	len;

  len = 0;
  if (tmp != NULL)
    len += strlen(tmp);
  if ((ret = malloc(len + 2)) == NULL)
    return (NULL);
  ret[0] = '\0';
  if (tmp != NULL)
    strcat(ret, tmp);
  strncat(ret, &c, 1);
  free(tmp);
  return (ret);
}
