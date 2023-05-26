/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:40:06 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 17:56:08 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    dprintf(STDERR_FILENO, "Exactly one argument required\n");
    return (1);
  }
  if (strchr(argv[1], '.')) {
    dprintf(STDERR_FILENO,
            "Only add class name as argument, not file extension\n");
    return (2);
  }
  char *cpp_name = strjoin(argv[1], ".cpp");
  char *hpp_name = strjoin(argv[1], ".hpp");
  if (!access(cpp_name, F_OK) || !access(hpp_name, F_OK)) {
    dprintf(STDERR_FILENO, "File already exists\n");
    free(cpp_name);
    free(hpp_name);
    return (3);
  }
  int cpp_fd = open(cpp_name, O_WRONLY | O_CREAT, 0644);
  if (cpp_fd < 0) {
    dprintf(STDERR_FILENO, "CPP File open failed\n");
    free(cpp_name);
    free(hpp_name);
    return (4);
  }
  int hpp_fd = open(hpp_name, O_WRONLY | O_CREAT, 0644);
  if (hpp_fd < 0) {
    dprintf(STDERR_FILENO, "HPP File open failed\n");
    free(cpp_name);
    free(hpp_name);
    close(cpp_fd);
    return (5);
  }
  create_hpp(hpp_fd, argv[1]);
  create_cpp(cpp_fd, argv[1]);
  close(cpp_fd);
  close(hpp_fd);
  return (0);
}
