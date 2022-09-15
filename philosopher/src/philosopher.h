/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo < ytoro-mo@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:53:45 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/09/14 16:45:32 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_prg_args
{
	int				n_philos;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_t_m_e;
	unsigned long	elapse_time;
}t_prg_args;

typedef struct s_philo
{
	int				ate;
	int				id;
	t_prg_args		*args;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	unsigned long	actual_time;
}t_philo;

int				ft_atoi(char *str);
void			ft_args_init(t_prg_args	*args, char **av);
void			ft_philos_init(t_philo *philos, t_prg_args	*args);
void			ft_philos_init_2(t_philo *philos, t_prg_args	*args,
					pthread_mutex_t	*mute);
unsigned long	ft_elapse_time(t_philo	*philos);
unsigned long	ft_actual_time(void);
void			*ft_philos_task_manager(void *p);

#endif