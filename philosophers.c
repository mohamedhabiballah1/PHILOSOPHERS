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

void    *routine(void *arg)
{
    printf("Philosopher %d is in the room\n", i);
    return (0);
}

void    philosophers(t_list *data)
{
    pthread_t t[data->philosophers];
    pthread_mutex_t chopkits[data->philosophers];
    
    data->i = 1;
    while (data->i <= data->philosophers)
    {
        if (pthread_mutex_init(&chopkits[data->i], NULL) != 0)
            write(2, "Error\n", 6);
        data->i++;
    }
    data->i = 1;
    while (data->i <= data->philosophers)
    {
        if (pthread_create(&t[data->i], NULL, routine, &data->i) != 0)
            write(2, "Error\n", 6);
        data->i++;
    }
    data->i = 1;
    while (data->i <= data->philosophers)
    {
        if (pthread_join(t[data->i], NULL) != 0)
            write(2, "Error\n", 6);
        data->i++;
    }
}

int main(int ac, char **av)
{
    t_list data;

    if (ac > 4 && ac < 7)
    {
        data.philosophers = ft_atoi(av[1]);
        data.die = ft_atoi(av[2]);
        data.eat = ft_atoi(av[3]);
        data.sleep = ft_atoi(av[4]);
        philosophers(&data);
    }
    return (0);
}