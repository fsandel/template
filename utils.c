/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:37:17 by fsandel           #+#    #+#             */
/*   Updated: 2023/01/30 13:04:43 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*cstr;

	cstr = (char *)str;
	i = 0;
	while (i < n)
	{
		cstr[i] = c;
		i++;
	}
	return (cstr);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (!size || !nitems || ((INT_MAX / size) < nitems))
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

char	*ft_strjoin(char const *first, char const *second)
{
	char	*joined;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	joined = ft_calloc((ft_strlen(first) + ft_strlen(second) + 1), 1);
	if (!joined)
		return (NULL);
	while (first[i1])
	{
		joined[i1] = first[i1];
		i1++;
	}
	while (second[i2])
	{
		joined[i1 + i2] = second[i2];
		i2++;
	}
	joined[i1 + i2] = '\0';
	return (joined);
}

char	*ft_strchr(char const *str, int c)
{
	int				length;
	unsigned char	chr;
	char			*strr;

	strr = (char *)str;
	chr = (unsigned char)c;
	length = ft_strlen(strr);
	while (*strr != chr)
	{
		if ((length) == 0)
			return (NULL);
		strr++;
		length--;
	}
	return (strr);
}
