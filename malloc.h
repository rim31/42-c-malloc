/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:56:58 by djoly             #+#    #+#             */
/*   Updated: 2018/01/11 16:37:13 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

typedef struct          s_header
{
    size_t              size;
    int                 free;
    struct s_header     *next;

    size_t              total_size;
    struct s_header     *next_area;
    int                 type;
}                       t_header;

/*
**    structure pour stocker toutes les structures
*/
typedef struct          s_zone{
      struct s_header   *header;
      struct s_zone     *next;
      size_t            size;
      size_t            count;
}                       t_zone;

typedef struct          s_env
{
      t_zone            *small;
      t_zone            *tiny;
      t_zone            *large;
}                       t_env;
/*
**    Global variables.
*/
t_header                *g_base;
t_env                   *global_env;

void free(void *ptr);
void *malloc(size_t size);
void *ft_realloc(void *ptr, size_t size);
void ft_show_alloc_mem(void);
void ft_putchar(char c);
void ft_putnbr(int n);
size_t ft_strlen(const char *s);
void ft_putstr(char const *str);


#endif