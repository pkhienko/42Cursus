/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:13 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 13:39:40 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_thread(t_table *table)
{
	int	i;

	table->start_time = get_time(table, MILLISECOND) + (table->philo_nb * 20);
	i = -1;
	while (++i < table->philo_nb)
		thread_mode(&table->philo[i], simulator_philo,
			(void *)&table->philo[i], CREATE_THREAD);
	if (table->philo_nb > 1)
		thread_mode(&table->philo[0], stop_simulator,
			(void *)table, CREATE_STOP_THREAD);
}

void	stop_thread(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
		thread_mode(&table->philo[i], NULL, NULL, JOIN_THREAD);
	if (table->philo_nb > 1)
		thread_mode(&table->philo[0], NULL, NULL, JOIN_STOP_THREAD);
	error_exit(NULL, EXIT_SUCCESS, STDOUT_FILENO, table);
}
