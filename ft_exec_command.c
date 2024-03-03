/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:15:59 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/06 11:34:08 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_command_to_pipe(char *command, char *env[], int *pfd)
{
	char	*pathname;
	char	**command_split;
	pid_t	pid;

	command_split = ft_split(command, ' ');
	pathname = ft_get_path(command, env);
	pid = fork();
	if (pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve(pathname, command_split, env);
	}
	ft_free_doublechar(&command_split);
	free(pathname);
}

void	ft_exec_command_from_pipe(char *command, char *env[], int *pfd)
{
	char	*pathname;
	char	**command_split;
	pid_t	pid;

	command_split = ft_split(command, ' ');
	pathname = ft_get_path(command, env);
	pid = fork();
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		execve(pathname, command_split, env);
	}
	ft_free_doublechar(&command_split);
	free(pathname);
}
