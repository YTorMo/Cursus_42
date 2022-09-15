/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:04 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/14 13:30:43 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_args_init(t_prg_args	*args, char **av)
{
	args->n_philos = ft_atoi(av[1]);
	args->t_t_d = ft_atoi(av[2]);
	args->t_t_e = ft_atoi(av[3]);
	args->t_t_s = ft_atoi(av[4]);
	args->n_t_m_e = ft_atoi(av[5]);
}

void	ft_philos_init(t_philo *philos, t_prg_args	*args)
{
	pthread_mutex_t	*fork;
	int				i;

	i = -1;
	fork = malloc(sizeof(pthread_mutex_t) * args->n_philos);
	if (!fork)
		return ;
	while (++i < args->n_philos)
		if (pthread_mutex_init(&fork[i], 0))
			return ;
	ft_philos_init_2(philos, args, fork);
}

void	ft_philos_init_2(t_philo *philos, t_prg_args	*args,
	pthread_mutex_t	*fork)
{
	int	i;

	i = -1;
	while (++i < args->n_philos)
	{
		philos->ate = 0;
		philos->id = i + 1;
		philos->args = args;
		philos->forks = fork;
	}
}
