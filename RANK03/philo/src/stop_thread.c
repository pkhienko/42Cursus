/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:11 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 16:15:38 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_simulator_stopped(t_table *table)
{
	mutex_mode(table, &table->stop_lock, LOCK_MUTEX);
	if (table->stop_prog == false)
	{
		mutex_mode(table, &table->stop_lock, UNLOCK_MUTEX);
		return (false);
	}
	mutex_mode(table, &table->stop_lock, UNLOCK_MUTEX);
	return (true);
}

static bool	is_dead(t_philo *philo)
{
	if (get_time(philo->table, MILLISECOND)
		- philo->last_meal >= philo->table->time_to_die)
	{
		mutex_mode(philo->table, &philo->table->stop_lock, LOCK_MUTEX);
		philo->table->stop_prog = true;
		mutex_mode(philo->table, &philo->table->stop_lock, UNLOCK_MUTEX);
		status_mode(philo, true, DIED);
		mutex_mode(philo->table, &philo->meal_lock, UNLOCK_MUTEX);
		return (true);
	}
	return (false);
}

static bool	kill_thread(t_table *table, int i, bool all_full)
{
	while (++i < table->philo_nb)
	{
		mutex_mode(table, &table->philo[i].meal_lock, LOCK_MUTEX);
		if (is_dead(&table->philo[i]) == true)
			return (true);
		if ((int)table->philo[i].eat_count < table->must_eat
			&& table->must_eat != -1)
			all_full = false;
		mutex_mode(table, &table->philo[i].meal_lock, UNLOCK_MUTEX);
	}
	if (all_full == true && table->must_eat != -1)
	{
		mutex_mode(table, &table->stop_lock, LOCK_MUTEX);
		table->stop_prog = true;
		mutex_mode(table, &table->stop_lock, UNLOCK_MUTEX);
		return (true);
	}
	return (false);
}

void	*stop_simulator(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->must_eat == 0)
		return (NULL);
	delay_start(table, table->start_time);
	while (true)
	{
		if (kill_thread(table, -1, true) == true)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
