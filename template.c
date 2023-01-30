/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:33:22 by fsandel           #+#    #+#             */
/*   Updated: 2023/01/30 11:41:25 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

void	create_hpp(int fd, char *name)
{
	ft_putstr_fd("#pragma once\n\n", fd);
	ft_putstr_fd("class ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("\n{\n\tpublic:\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("();\n\t\t~", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("();\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("(", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" &obj);\n\t\t", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("& operator=(const ", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("& obj);\n\tprivate:\n\n};", fd);
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
	ft_putstr_fd(" &obj)\n{\n\t*this = obj;\n}\n", fd);
}