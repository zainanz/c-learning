/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:11:23 by zali              #+#    #+#             */
/*   Updated: 2025/06/24 16:13:32 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_string
{
	char	*ptr;
	int		size;
	int		index;
}			t_string;

// Utils Both Server
void		ft_putnbr(int n);
void		set_server_sigaction(void *handler, int sig_handler);
int			ft_atoi(char *str);
void		safe_kill(int sender_pid, int signo);

// String Struct
t_string	*string_init(int size);
void		append_to_string(char c);
void		string_end(void);

// Server Handler Utils
void		malloc_error(void);
void		msg_recieved(pid_t pid);
void		send_ack(pid_t pid);
int			char_handler(int signo, int sender_pid);
int			len_handler(int signo, int sender_pid);

#endif
