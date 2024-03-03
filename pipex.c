/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:13:43 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/30 14:07:18 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_doublechar(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free((*tab));
	return ;
}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid[2];
	int		pfd[2];
	int		fd[2];

	pid[0] = 0;
	pid[1] = 0;
	if (!ft_verif(argc, argv, env))
		return (0);
	fd[0] = open(argv[1], O_RDWR);
	if (fd[0] == -1)
		return (0);
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] == -1)
		return (0);
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	pipe(pfd);
	ft_exec_command_to_pipe(argv[2], env, pfd);
	ft_exec_command_from_pipe(argv[3], env, pfd);
	close(pfd[1]);
	close(pfd[0]);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
	return (0);
}
