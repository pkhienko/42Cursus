/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:16 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 12:06:17 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	mutex_mode(t_table *table, t_mtx *mutex, t_op mode)
{
	if (mode == INIT_MUTEX)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			error_exit(MSG_MUTEX_INIT, EXIT_FAILURE, 2, table);
	}
	else if (mode == LOCK_MUTEX)
	{
		if (pthread_mutex_lock(mutex) != 0)
			error_exit(MSG_MUTEX_LOCK, EXIT_FAILURE, 2, table);
	}
	else if (mode == UNLOCK_MUTEX)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			error_exit(MSG_MUTEX_UNLOCK, EXIT_FAILURE, 2, table);
	}
	else if (mode == DESTROY_MUTEX)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			error_exit(MSG_MUTEX_DESTROY, EXIT_FAILURE, 2, table);
	}
}

void	thread_mode(t_philo *philo, void *(*f)(void *), void *data, t_op mode)
{
	if (mode == CREATE_THREAD)
	{
		if (pthread_create(&philo->thread, NULL, f, data) != 0)
			error_exit(MSG_THREAD_CREATE, EXIT_FAILURE, 2, philo->table);
	}
	else if (mode == CREATE_STOP_THREAD)
	{
		if (pthread_create(&philo->table->stop_thread, NULL, f, data) != 0)
			error_exit(MSG_THREAD_CREATE, EXIT_FAILURE, 2, philo->table);
	}
	else if (mode == JOIN_THREAD)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			error_exit(MSG_THREAD_JOIN, EXIT_FAILURE, 2, philo->table);
	}
	else if (mode == JOIN_STOP_THREAD)
	{
		if (pthread_join(philo->table->stop_thread, NULL) != 0)
			error_exit(MSG_THREAD_JOIN, EXIT_FAILURE, 2, philo->table);
	}
	else if (mode == DETACH_THREAD)
	{
		if (pthread_detach(philo->thread) != 0)
			error_exit(MSG_THREAD_DETACH, EXIT_FAILURE, 2, philo->table);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

long	ft_atol(char *nb)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (*nb == '+' || *nb == '-')
	{
		if (*nb == '-')
			sign = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		res = (res * 10) + (*nb - '0');
		nb++;
	}
	return (res * sign);
}
