/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:03 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/09 10:35:05 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_get_indice_path(char *env[])
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5 * sizeof(char)) != 0)
	{
		i ++;
	}
	if (!env[i])
		i = -1;
	return (i);
}

char	*ft_search_path(char **command_split, char **path_list)
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	temp = ft_strjoin("/", command_split[0]);
	path = ft_strjoin(path_list[0], temp);
	while (path_list[i] && access(path, X_OK) == -1)
	{
		free(path);
		free(temp);
		temp = ft_strjoin("/", command_split[0]);
		path = ft_strjoin(path_list[i], temp);
		i ++;
	}
	free(temp);
	ft_free_doublechar(&command_split);
	if (!path_list[i])
	{
		ft_free_doublechar(&path_list);
		return (NULL);
	}
	ft_free_doublechar(&path_list);
	return (path);
}

char	*ft_get_path(char *command, char *env[])
{
	char	**path_list;
	char	*path;
	char	**command_split;
	int		indice_path;

	command_split = ft_split(command, ' ');
	indice_path = ft_get_indice_path(env);
	if (indice_path == -1)
	{
		return (NULL);
	}
	path_list = ft_split(env[indice_path] + 5, ':');
	path = ft_search_path(command_split, path_list);
	return (path);
}
