/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:07 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 12:06:08 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_nbrlen(char *s)
{
	int	i;
	int	size;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			size++;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		size++;
		i++;
	}
	return (size);
}

static bool	is_only_digit(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i])
		return (false);
	return (true);
}

static bool	is_signed(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			return (false);
	}
	return (true);
}

bool	is_valid_arg(int ac, char **av, t_table *table)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!is_only_digit(av[i]))
			error_exit(NOT_DIGIT, EXIT_FAILURE, STDERR_FILENO, table);
		if (!is_signed(av[i]))
			error_exit(NEGATIVE_SIGN, EXIT_FAILURE, STDERR_FILENO, table);
		if (ft_nbrlen(av[i]) > 10 || ft_atol(av[i]) > INT_MAX)
			error_exit(INT_OVERFLOW, EXIT_FAILURE, STDERR_FILENO, table);
	}
	return (true);
}
