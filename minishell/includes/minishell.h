/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:29 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 16:41:04 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <termios.h>
#define BUFFER_SIZE 1024

typedef struct s_node
{
	char			*command;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

void	ft_cd(char **argv);
void	ft_pwd(void);
void	ft_echo(char **argv);
void	ft_exit(void);
void	execute_command(char **argv);
void	read_input(char *buffer);
void	parse_input(char *input, char **argv);
void	auto_complete(char *input);
void	enable_raw_mode();
void	disable_raw_mode();