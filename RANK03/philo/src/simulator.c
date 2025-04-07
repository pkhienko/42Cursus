/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:09 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 16:11:26 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	think_routine(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	mutex_mode(philo->table, &philo->meal_lock, LOCK_MUTEX);
	time_to_think = (philo->table->time_to_die - (get_time(philo->table, MILLISECOND)
					- philo->last_meal - philo->table->time_to_eat)) / 2;
	mutex_mode(philo->table, &philo->meal_lock, UNLOCK_MUTEX);
	// error point need to be fixed
	// if (time_to_think < 0)
	// 	time_to_think = 0;
	// if (time_to_think > 600)
	// 	time_to_think = 200;
	time_to_think = 0;
	if (silent == false)
		status_mode(philo, false, THINKING);
	thread_sleep(philo->table, time_to_think);
}

static void	eat_sleep_routine(t_philo *philo)
{
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[0]], LOCK_MUTEX);
	status_mode(philo, false, GET_FORK_1);
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[1]], LOCK_MUTEX);
	status_mode(philo, false, GET_FORK_2);
	status_mode(philo, false, EATING);
	mutex_mode(philo->table, &philo->meal_lock, LOCK_MUTEX);
	philo->last_meal = get_time(philo->table, MILLISECOND);
	mutex_mode(philo->table, &philo->meal_lock, UNLOCK_MUTEX);
	thread_sleep(philo->table, philo->table->time_to_eat);
	if (is_simulator_stopped(philo->table) == false)
	{
		mutex_mode(philo->table, &philo->meal_lock, LOCK_MUTEX);
		philo->eat_count++;
		mutex_mode(philo->table, &philo->meal_lock, UNLOCK_MUTEX);
	}
	status_mode(philo, false, SLEEPING);
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[1]], UNLOCK_MUTEX);
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[0]], UNLOCK_MUTEX);
	thread_sleep(philo->table, philo->table->time_to_sleep);
	think_routine(philo, false);
}

static void	*one_thread(t_philo *philo)
{
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[0]], LOCK_MUTEX);
	status_mode(philo, false, GET_FORK_1);
	thread_sleep(philo->table, philo->table->time_to_die);
	status_mode(philo, false, DIED);
	mutex_mode(philo->table, &philo->table->fork_locks[philo->fork[0]], UNLOCK_MUTEX);
	return (NULL);
}

void	*simulator_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->must_eat == 0)
		return (NULL);
	mutex_mode(philo->table, &philo->meal_lock, LOCK_MUTEX);
	philo->last_meal = philo->table->start_time;
	mutex_mode(philo->table, &philo->meal_lock, UNLOCK_MUTEX);
	delay_start(philo->table, philo->table->start_time);
	if (philo->table->philo_nb == 1)
		return (one_thread(philo));
	while (is_simulator_stopped(philo->table) == false)
		eat_sleep_routine(philo);
	return (NULL);
}
