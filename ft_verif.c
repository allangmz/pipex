/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:33:57 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/09 10:46:48 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_verif_command(char *command, char *env[])
{
	char	*pathname;
	char	**command_split;

	command_split = ft_split(command, ' ');
	pathname = ft_get_path(command, env);
	if (pathname == NULL)
	{
		write(2, "Pipex : command not found : s", 27);
		write(2, command_split[0], ft_strlen(command_split[0]));
		write(2, "\n", 1);
		free(pathname);
		ft_free_doublechar(&command_split);
		return (0);
	}
	ft_free_doublechar(&command_split);
	free(pathname);
	return (1);
}

int	ft_verif_arg(int argc)
{
	if (argc > 5)
	{
		write(2, "Pipex : to many arguments : ", 28);
		write(2, "\n", 1);
		return (0);
	}
	if (argc < 5)
	{
		write(2, "Pipex : to few arguments : ", 27);
		write(2, "\n", 1);
		return (0);
	}
	return (1);
}

int	ft_verif_infile(char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		write(2, "Pipex : no such file or directory: ", 35);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (0);
	}
	return (1);
}

int	ft_verif(int argc, char *argv[], char *env[])
{
	if (!ft_verif_arg(argc))
		return (0);
	if (!ft_verif_command(argv[2], env))
		return (0);
	if (!ft_verif_command(argv[3], env))
		return (0);
	if (!ft_verif_infile(argv))
		return (0);
	return (1);
}
