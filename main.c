/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:40:06 by fsandel           #+#    #+#             */
/*   Updated: 2023/01/30 13:03:36 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

int	main(int argc, char *argv[])
{
	char	*hpp_name;
	char	*cpp_name;
	int		cpp_fd;
	int		hpp_fd;

	if (argc != 2)
	{
		ft_putstr_fd("pls add exactly one argument\n", 2);
		return (-1);
	}
	if (ft_strchr(argv[1], '.'))
	{
		ft_putstr_fd("please make sure to only add class name not file name\n", 2);
		return (-2);
	}
	cpp_name = ft_strjoin(argv[1], ".cpp");
	hpp_name = ft_strjoin(argv[1], ".hpp");
	if (!access(cpp_name, F_OK) || !access(hpp_name, F_OK))
	{
		ft_putstr_fd("file already exists, pls use another name or delete file\n", 2);
		free(cpp_name);
		free(hpp_name);
		return (-3);
	}
	cpp_fd = open(cpp_name, O_WRONLY | O_CREAT, 0644);
	if (cpp_fd < 0)
	{
		ft_putstr_fd("cpp open failed\n", 2);
		free(cpp_name);
		free(hpp_name);
		return (-4);
	}
	hpp_fd = open(hpp_name, O_WRONLY | O_CREAT, 0644);
	if (hpp_fd < 0)
	{
		ft_putstr_fd("hpp open failed", 2);
		free(cpp_name);
		free(hpp_name);
		close(cpp_fd);
		return (-5);
	}
	create_hpp(hpp_fd, argv[1]);
	create_cpp(cpp_fd, argv[1]);
	close(cpp_fd);
	close(hpp_fd);
	return (0);
}
