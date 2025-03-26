/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:14 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 12:06:44 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time(t_table *table, t_time_unit mode)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		error_exit(MSG_GETTIMEOFDAY, EXIT_FAILURE, STDERR_FILENO, table);
	if (mode == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (mode == MILLISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (mode == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	return (-1);
}

void	thread_sleep(t_table *table, time_t time_to_sleep)
{
	time_t	wake_time;

	wake_time = get_time(table, MILLISECOND) + time_to_sleep;
	while (get_time(table, MILLISECOND) < wake_time)
	{
		if (is_simulator_stopped(table) == true)
			break ;
		usleep(100);
	}
}

void	delay_start(t_table *table, time_t start_time)
{
	while (get_time(table, MILLISECOND) < start_time)
		usleep(100);
}
