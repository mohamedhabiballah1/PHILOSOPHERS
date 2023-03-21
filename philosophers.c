/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:35:05 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/12 13:08:10 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_check_params(char **av)
{
    if (ft_atoi(av[1]) <= 0)
        return(1);
    else if (ft_atoi(av[2]) <= 0)
        return(1);
    else if (ft_atoi(av[3]) <= 0)
        return(1);
    else if (ft_atoi(av[4]) <= 0)
        return(1);
    return (0);
}

void    philosophers(t_list *lst)
{
    t_data *data = ft_data(lst);
    t_list *tmp;
    pthread_mutex_t chopkits[lst->philosophers];
    int i;

    i = 0;
    tmp = lst;
    //printf("%d\n", data ->philosophers);
    while (i <= 2)//tmp->philosophers)
    {
        puts("hello");
        pthread_mutex_init(&data->chopkits[i], NULL);
            //write(1, "Error\n", 6);
        i++;
    }
}

int main(int ac, char **av)
{
    t_list *lst = NULL;
    t_data *data;

    int i;
    int j;
    int k;
    int m;

    if (ac > 4 && ac < 7)
    {
        if (ft_check_params(av) != 0)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        i = 1;
        j = 1;
        k = 2;
        m = 0;
        while (i <= ft_atoi(av[1]))
        {
            if (i == ft_atoi(av[1]))
                ft_lst_add_back(&lst, ft_lstnew(i, 1, j));
            else
                ft_lst_add_back(&lst, ft_lstnew(i, k, j));
            i++;
            k++;
            j++;
        }
        lst->philosophers = ft_atoi(av[1]);
        lst->t_die = ft_atoi(av[2]);
        lst->t_eat = ft_atoi(av[3]);
        lst->t_sleep = ft_atoi(av[4]);
        data = ft_lstnews(ft_atoi(av[1]));
        ft_lst_add_backs(&lst, data);
        philosophers(lst);
    }
    return (0);
}