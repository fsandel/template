/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:33:22 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 14:29:44 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

static char to_upper(char c)
{
  if (c >= 'a' && c <= 'z')
    return (c - 'a' + 'A');
  else
    return (c);
}

static char *include_guard(char *name)
{
  char  *guard = malloc(ft_strlen(name) + 5 + 1);
  int i = 0;
  while (name && name[i])
  {
    guard[i] = to_upper(name[i]);
    i++;
  }
  guard[i++] = '_';
  guard[i++] = 'H';
  guard[i++] = 'P';
  guard[i++] = 'P';
  guard[i++] = '_';
  guard[i++] = 0;
  return (guard);
}

void	create_hpp(int fd, char *name)
{
  char  *guard = include_guard(name);
	ft_putstr_fd("#ifndef ", fd);
  ft_putstr_fd(guard, fd);
  ft_putstr_fd("\n#define ", fd);
  ft_putstr_fd(guard, fd);
	ft_putstr_fd("\n\nclass ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("\n{\n\tpublic:\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("();\n\t\t~", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("();\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("(", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" const &obj);\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("& operator=(const ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("& obj);\n\tprivate:\n\n};", fd);
  ft_putstr_fd("\n\n#endif //", fd);
  ft_putstr_fd(guard, fd);
  free(guard);
}
void	create_cpp(int fd, char *name)
{
	ft_putstr_fd("#include \"", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(".hpp\"\n\n", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("::", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("()\n{\n}\n\n", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("::~", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("()\n{\n}\n\n",fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("& ",fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("::operator=(const ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("&obj)\n{\n\t//add rule for copy assignment constructor\n\treturn (*this);\n}\n\n", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("::", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("(", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" const &obj)\n{\n\t*this = obj;\n}\n", fd);
}