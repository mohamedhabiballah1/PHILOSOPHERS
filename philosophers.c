/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:35:05 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/23 13:38:02 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t  get_time(t_list *lst)
{
    size_t res;
    size_t current;
    t_data *data = ft_data(lst);
    
    gettimeofday(&lst->current, NULL);
    //res = data->beggin.tv_sec + 1000000;
    res = data->beggin.tv_usec / 1000;
    //res /= 1000;
    //current = lst->current.tv_sec + 1000000;
    current = lst->current.tv_usec / 1000;
    //current /= 1000;
    return (res - current);
}

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

void    think(t_list *lst)
{
    printf("Philosopher %d is thinking\n", lst->philos);
    //usleep((lst->t_sleep / 2) * 1000);
}

void    ft_sleep(t_list *lst)
{
    printf("Philosopher %d is sleeping\n", lst->philos);
    usleep(lst->t_sleep * 1000);
    think(lst);
}

void    forks(t_list *lst)
{
    t_data *data;
    int     n;
    
    data = ft_data(lst);
    n = lst->philos;
    pthread_mutex_lock(&data->chopkits[lst->right]);
    printf("Philosopher %d has taken a fork\n", n);
    pthread_mutex_lock(&data->chopkits[lst->left]);
    printf("Philosopher %d has taken a fork\n", n);
    usleep(lst->t_eat * 1000);
    printf("Philosopher %d is eating\n", n);
    pthread_mutex_unlock(&data->chopkits[lst->right]);
    pthread_mutex_unlock(&data->chopkits[lst->left]);
    ft_sleep(lst);
}

void    *routine(void *arg)
{
    t_list *lst = (void *) arg;
    int i = 0;
    
    if ((lst->philos % 2) == 0)
        usleep((lst->t_sleep / 2) * 1000);
    while (i != 3)
    {
        forks(lst);
        //usleep(1500);
        i++;
    }
    return (0);
}

void    philosophers(t_list *lst)
{
    t_data *data = ft_data(lst);
    t_list *tmp;
    pthread_mutex_t chopkits[lst->philosophers];
    pthread_t *t_id;
    int i;

    i = 0;
    tmp = lst;
    data->chopkits = malloc(sizeof(pthread_mutex_t) * data->philosophers);
    gettimeofday(&data->beggin, NULL);
    //printf("%zu\n", get_time(tmp));
    while (i < tmp->philosophers)
    {
        if(pthread_mutex_init(&data->chopkits[i], NULL) != 0)
            write(1, "Error\n", 6);
        i++;
    }
    i = 0;
    while (tmp)
    {
        if (pthread_mutex_init(&tmp->write, NULL) != 0)
                write(1, "Error\n", 6);
        tmp = tmp->next;
    }
    tmp = lst;
    while (tmp)
    {
        if (pthread_create(&tmp->t_id, NULL, routine, tmp) != 0)
                write(1, "Error\n", 6);
        tmp = tmp->next;
    }
    tmp = lst;
    while (tmp)
    {
        if (pthread_join(tmp->t_id, NULL) != 0)
                write(1, "Error\n", 6);
        tmp = tmp->next;
    }
}

long long current_timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
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
        j = 0;
        k = 1;
        while (i <= ft_atoi(av[1]))
        {
            if (i == ft_atoi(av[1]))
                ft_lst_add_back(&lst, ft_lstnew(i, 0, j, av));
            else
                ft_lst_add_back(&lst, ft_lstnew(i, k, j, av));
            i++;
            k++;
            j++;
        }
        data = ft_lstnews(ft_atoi(av[1]));
        ft_lst_add_backs(&lst, data);
        printf("milliseconds: %lld\n", current_timestamp());
        //philosophers(lst);
    }
    return (0);
}