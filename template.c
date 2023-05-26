/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:33:22 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 17:50:30 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

#include <stdio.h>

static char to_upper(char c) {
  if (c >= 'a' && c <= 'z')
    return (c - 'a' + 'A');
  else
    return (c);
}

static char *include_guard(char *name) {
  char *guard = malloc(ft_strlen(name) + 5 + 1);
  int i = 0;
  while (name && name[i]) {
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

void create_hpp(int fd, char *name) {
  char *guard = include_guard(name);
  dprintf(fd, "#ifndef %s\n", guard);
  dprintf(fd, "#define %s\n", guard);
  dprintf(fd, "\n");
  dprintf(fd, "class %s {\n", name);
  dprintf(fd, " public:\n");
  dprintf(fd, "  %s();\n", name);
  dprintf(fd, "  ~%s();\n", name);
  dprintf(fd, "  %s(%s const& obj);\n", name, name);
  dprintf(fd, "  %s& operator=(const %s& obj);\n", name, name);
  dprintf(fd, "\n");
  dprintf(fd, " private:\n");
  dprintf(fd, "};\n");
  dprintf(fd, "\n");
  dprintf(fd, "#endif  // %s\n", guard);
  free(guard);
}

void create_cpp(int fd, char *name) {
  dprintf(fd, "#include \"%s.hpp\"\n", name);
  dprintf(fd, "\n");
  dprintf(fd, "%s::%s() {}\n", name, name);
  dprintf(fd, "\n");
  dprintf(fd, "%s::~%s() {}\n", name, name);
  dprintf(fd, "\n");
  dprintf(fd, "%s::%s(%s const& obj) { *this = obj; }\n", name, name, name);
  dprintf(fd, "\n");
  dprintf(fd, "%s& %s::operator=(const %s& obj) {\n", name, name, name);
  dprintf(fd, "  (void)obj;\n");
  dprintf(fd, "  return *this;\n");
  dprintf(fd, "}\n");
}