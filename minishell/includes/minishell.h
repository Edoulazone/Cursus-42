/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:29 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 15:14:48 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>

void	ft_cd(char **argv);
void	ft_pwd(void);
void	ft_echo(char **argv);
void	ft_exit(void);
void	execute_command(char **argv);
char	*read_input(void);
void	parse_input(char *input, char **argv);
void	auto_complete(char *input);