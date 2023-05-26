/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:33:22 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 18:14:09 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *include_guard(char *name) {
  char *guard = calloc(strlen(name) + 5 + 1, sizeof(char));
  if (!guard) return (NULL);
  int i = 0;
  while (name && name[i]) {
    guard[i] = toupper(name[i]);
    i++;
  }
  strcat(guard, "_HPP_");
  return (guard);
}

void create_hpp(int fd, char *name) {
  char *guard = include_guard(name);
  if (!guard) return ;
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