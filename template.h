/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:33 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 17:50:24 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX 2147483648

size_t ft_strlen(const char *str);
void ft_putstr_fd(char *s, int fd);
void create_hpp(int fd, char *name);
void create_cpp(int fd, char *name);
char *ft_strjoin(char const *first, char const *second);
char *ft_strchr(char const *str, int c);

#endif