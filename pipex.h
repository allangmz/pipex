/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:10:40 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/09 09:28:16 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

int		ft_verif(int argc, char *argv[], char *env[]);
void	ft_exec_command_to_pipe(char *command, char *env[], int *pfd);
void	ft_exec_command_from_pipe(char *command, char *env[], int *pfd);
int		ft_get_indice_path(char *env[]);
void	ft_free_doublechar(char ***tab);
char	*ft_get_path(char *command, char *env[]);
char	*ft_search_path(char **command_split, char **path_list);	

#endif
