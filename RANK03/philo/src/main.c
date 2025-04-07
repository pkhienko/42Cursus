/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:05 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 12:37:05 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	t_table	*table;

	table = NULL;
	if (ac == 5 || ac == 6)
	{
		table = (t_table *)malloc(sizeof(t_table));
		if (!table)
			error_exit(MSG_MALLOC, EXIT_FAILURE, STDERR_FILENO, table);
		table->philo = NULL;
		table->fork_locks = NULL;
		if (!init_table(ac, av, table))
			error_exit(HELP_MSG, EXIT_FAILURE, STDERR_FILENO, table);
		start_thread(table);
	}
	else
		error_exit(HELP_MSG, EXIT_FAILURE, STDERR_FILENO, table);
	stop_thread(table);
}
