/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:35:09 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/12 12:54:05 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

#define PHILOSOPHERS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_data
{
    int philosophers;
    int eat;
    int sleep;
    int die;
}   t_data;

typedef struct s_list
{
    int philosophers;
    int philos;
    int eat;
    int die;
    int sleep;
    int i;
    pthread_mutex_t *chopkits;
    struct s_list *next;
}   t_list;

int	ft_atoi(const char *str);
t_list  *ft_lstnew(int content, int left, int right);
t_list	*ft_lstlast(t_list *lst);
void	ft_lst_add_back(t_list **lst, t_list *new);
void    start(t_list **data);
#endif