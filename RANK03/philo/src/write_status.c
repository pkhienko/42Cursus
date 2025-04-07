/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:18 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 14:01:21 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_status(t_philo *philo, char *str)
{
	printf("%ld	%u\t%s\n", get_time(philo->table, MILLISECOND)
		- philo->table->start_time, philo->id + 1, str);
}

static void	print_debug_mode(t_philo *philo, t_status mode)
{
	time_t	cur_time;

	cur_time = get_time(philo->table, MILLISECOND) - philo->table->start_time;
	if (mode == DIED)
		printf(C "%ld	%s%03u\tdied\n" RST, cur_time, R, philo->id + 1);
	else if (mode == EATING)
		printf(C "%ld	%s%03u\tis eating\n" RST, cur_time, G, philo->id + 1);
	else if (mode == SLEEPING)
		printf(C "%ld	%s%03u\tis sleeping\n" RST, cur_time, M, philo->id + 1);
	else if (mode == THINKING)
		printf(C "%ld	%s%03u\tis thinking\n" RST, cur_time,
			BE, philo->id + 1);
	else if (mode == GET_FORK_1)
		printf(C "%ld	%s%03u\thas taken a fork %s[%s%d%s]\n" RST, cur_time,
			Y, philo->id + 1, M, R, philo->fork[0] + 1, M);
	else if (mode == GET_FORK_2)
		printf(C "%ld	%s%03u\thas taken a fork %s[%s%d%s]\n" RST, cur_time,
			Y, philo->id + 1, M, R, philo->fork[1] + 1, M);
}

void	status_mode(t_philo *philo, bool stop_thread_signal, t_status mode)
{
	mutex_mode(philo->table, &philo->table->write_lock, LOCK_MUTEX);
	if (is_simulator_stopped(philo->table) == true
		&& stop_thread_signal == false)
	{
		mutex_mode(philo->table, &philo->table->write_lock, UNLOCK_MUTEX);
		return ;
	}
	if (DEBUG_MODE == true)
		print_debug_mode(philo, mode);
	else if (mode == DIED)
		print_status(philo, R "died" RST);
	else if (mode == EATING)
		print_status(philo, "is eating");
	else if (mode == SLEEPING)
		print_status(philo, "is sleeping");
	else if (mode == THINKING)
		print_status(philo, "is thinking");
	else if (mode == GET_FORK_1 || mode == GET_FORK_2)
		print_status(philo, "has taken a fork");
	mutex_mode(philo->table, &philo->table->write_lock, UNLOCK_MUTEX);
}
