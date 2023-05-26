/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:58:24 by fsandel           #+#    #+#             */
/*   Updated: 2023/05/26 18:07:32 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *strjoin(char *f, char *s) {
  int len_f = strlen(f);
  char *joined = calloc(len_f + strlen(s) + 1, sizeof(char));
  strcpy(joined, f);
  strcat(joined, s);
  return (joined);
}