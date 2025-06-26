/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:03 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 12:06:04 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->philo_nb;
	if (philo->id % 2 != 0)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->philo_nb;
		philo->fork[1] = philo->id;
	}
}

static void	init_philo(t_table *table, int i)
{
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_nb);
	if (!table->philo)
		error_exit(MSG_MALLOC, EXIT_FAILURE, STDERR_FILENO, table);
	table->fork_locks = (t_mtx *)malloc(sizeof(t_mtx) * table->philo_nb);
	if (!table->fork_locks)
		error_exit(MSG_MALLOC, EXIT_FAILURE, STDERR_FILENO, table);
	while (++i < table->philo_nb)
	{
		mutex_mode(table, &table->philo[i].meal_lock, INIT_MUTEX);
		table->philo[i].id = i;
		table->philo[i].table = table;
		table->philo[i].eat_count = 0;
		assign_forks(&table->philo[i]);
	}
	table->status_mtx.m_lock = true;
	i = -1;
	while (++i < table->philo_nb)
		mutex_mode(table, &table->fork_locks[i], INIT_MUTEX);
	table->status_mtx.f_lock = true;
	mutex_mode(table, &table->stop_lock, INIT_MUTEX);
	table->status_mtx.s_lock = true;
	mutex_mode(table, &table->write_lock, INIT_MUTEX);
	table->status_mtx.w_lock = true;
}

bool	init_table(int ac, char **av, t_table *table)
{
	if ((ac == 5 || ac == 6) && is_valid_arg(ac, av, table))
	{
		table->philo_nb = ft_atol(av[1]);
		if (table->philo_nb < 1 || table->philo_nb > MAX_PHILO)
			error_exit(PHILO_LIMIT, EXIT_FAILURE, STDERR_FILENO, table);
		table->time_to_die = ft_atol(av[2]);
		table->time_to_eat = ft_atol(av[3]);
		table->time_to_sleep = ft_atol(av[4]);
		if (table->time_to_die < 60 || table->time_to_eat < 60
			|| table->time_to_sleep < 60)
			error_exit(MSG_TIME, EXIT_FAILURE, STDERR_FILENO, table);
		table->must_eat = -1;
		table->stop_prog = false;
		table->status_mtx.m_lock = false;
		table->status_mtx.f_lock = false;
		table->status_mtx.s_lock = false;
		table->status_mtx.w_lock = false;
		if (ac == 6)
			table->must_eat = ft_atol(av[5]);
		init_philo(table, -1);
		return (true);
	}
	return (false);
}
