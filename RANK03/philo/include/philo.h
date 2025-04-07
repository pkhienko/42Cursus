/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:59 by pkhienko          #+#    #+#             */
/*   Updated: 2024/12/23 13:25:58 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define HELP_MSG "\t./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define NEGATIVE_SIGN "Error: Negative numbers are not allowed.\n"
# define NOT_DIGIT "Error: Argument is not a digit.\n"
# define INT_OVERFLOW "Error: Integer Overflow.\n"
# define PHILO_LIMIT "Error: Number of philosophers must be between 1 \
and 200.\n"
# define MSG_MALLOC "Error: Memory allocation failed.\n"
# define MSG_THREAD_CREATE "Error: Thread creation failed.\n"
# define MSG_THREAD_JOIN   "Error: Thread join failed.\n"
# define MSG_THREAD_DETACH "Error: Thread detach failed.\n"
# define MSG_MUTEX_INIT "Error: Mutex initialization failed.\n"
# define MSG_MUTEX_LOCK "Error: Mutex lock failed.\n"
# define MSG_MUTEX_UNLOCK "Error: Mutex unlock failed.\n"
# define MSG_MUTEX_DESTROY "Error: Mutex destroy failed.\n"
# define MSG_GETTIMEOFDAY "Error: gettimeofday failed.\n"
# define MSG_TIME "Error: Use timestamp greater than or equal to 60 ms.\n"

# define RST "\033[0m"  // Reset to default
# define BK "\033[1;30m"  // Black
# define R "\033[1;31m"  // Red
# define G "\033[1;32m"  // Green
# define Y "\033[1;33m"  // Yellow
# define BE "\033[1;34m"  // Blue
# define M "\033[1;35m"  // Magenta
# define C "\033[1;36m"  // Cyan
# define W "\033[1;37m"  // White

# define MAX_PHILO 200

# ifndef DEBUG_MODE
#  define DEBUG_MODE false
# endif

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_status_mutex
{
	bool	m_lock;
	bool	f_lock;
	bool	s_lock;
	bool	w_lock;
}	t_status_mutex;

typedef struct s_philo
{
	pthread_t		thread;
	t_mtx			meal_lock;
	time_t			last_meal;
	unsigned int	id;
	unsigned int	fork[2];
	unsigned int	eat_count;
	t_table			*table;	
}	t_philo;

typedef struct s_table
{
	t_philo			*philo;
	bool			stop_prog;
	int				must_eat;
	int				philo_nb;
	time_t			start_time;
	time_t			time_to_eat;
	time_t			time_to_die;
	time_t			time_to_sleep;
	pthread_t		stop_thread;
	t_mtx			stop_lock;
	t_mtx			write_lock;
	t_mtx			*fork_locks;
	t_status_mutex	status_mtx;

}	t_table;

typedef enum e_op
{
	CREATE_THREAD,
	CREATE_STOP_THREAD,
	JOIN_THREAD,
	JOIN_STOP_THREAD,
	DETACH_THREAD,
	INIT_MUTEX,
	LOCK_MUTEX,
	UNLOCK_MUTEX,
	DESTROY_MUTEX
}	t_op;

typedef enum e_status
{
	DIED,
	EATING,
	SLEEPING,
	THINKING,
	GET_FORK_1,
	GET_FORK_2
}	t_status;

typedef enum e_time_unit
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_unit;

// init_arg
bool	init_table(int ac, char **av, t_table *table);

// parsing
bool	is_valid_arg(int ac, char **av, t_table *table);

// simulator
void	*simulator_philo(void *data);

// stop_thread
void	*stop_simulator(void *data);
bool	is_simulator_stopped(t_table *table);

// thread_control
void	start_thread(t_table *table);
void	stop_thread(t_table *table);

// write_status
void	status_mode(t_philo *philo, bool stop_thread_signal, t_status mode);

// time
time_t	get_time(t_table *table, t_time_unit mode);
void	delay_start(t_table *table, time_t start_time);
void	thread_sleep(t_table *philo, time_t time_to_sleep);

// utils
long	ft_atol(char *nb);
void	ft_putstr_fd(char *s, int fd);
void	mutex_mode(t_table *table, t_mtx *mutex, t_op mode);
void	thread_mode(t_philo *philo, void *(*f)(void *), void *data, t_op mode);

// error_handle
void	error_exit(char *msg, int exit_code, int write_code, t_table *table);

#endif
