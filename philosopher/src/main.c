/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:54:00 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/14 16:51:43 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_prg_args	*args;
	t_philo		*philos;
	pthread_t	*thr;
	int			i;

	args = malloc(sizeof(t_prg_args));
	if (!args)
		return (0);
	ft_args_init(args, av);
	philos = malloc(sizeof(t_philo) * args->n_philos);
	if (!philos)
		return (0);
	ft_philos_init(philos, args);
	thr = malloc(sizeof(pthread_t) * args->n_philos);
	if (!thr)
		return (0);
	i = -1;
	while (++i < philos->args->n_philos)
	{
		pthread_create(&thr[i], NULL, ft_philos_task_manager, &philos[i]);
		usleep(100);
	}
	return (0);
}

void	*ft_philos_task_manager(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		usleep(10);
	philo->actual_time = ft_actual_time();
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->id - 1]);
		
	}
	return (0);
}
