/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:01 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 13:39:47 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	mutex_destroy_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_nb)
		mutex_mode(philo->table, &philo[i].meal_lock, DESTROY_MUTEX);
}

static void	mutex_destroy_fork(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
		mutex_mode(table, &table->fork_locks[i], DESTROY_MUTEX);
}

void	error_exit(char *msg, int exit_code, int write_code, t_table *table)
{
	if (msg)
		ft_putstr_fd(msg, write_code);
	if (table)
	{
		if (table->philo)
		{
			if (table->status_mtx.m_lock == true)
				mutex_destroy_philo(table->philo);
			free(table->philo);
		}
		if (table->fork_locks)
		{
			if (table->status_mtx.f_lock == true)
				mutex_destroy_fork(table);
			if (table->status_mtx.s_lock == true)
				mutex_mode(table, &table->stop_lock, DESTROY_MUTEX);
			if (table->status_mtx.w_lock == true)
				mutex_mode(table, &table->write_lock, DESTROY_MUTEX);
			free(table->fork_locks);
		}
		free(table);
	}
	exit(exit_code);
}
