/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:02:36 by lucasmar          #+#    #+#             */
/*   Updated: 2022/09/30 18:52:46 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct minishell
{
	int		*fd;
	int		pipe;
	int		p;
	int		n_pipe;
	int		pipe_d;
	char	*line;
	int		n_$;
	int		redirection;
	int		i;
	int		j;
	int		k;
	char	**path_list;
	char	*path_cmd;
	char	*path_outfile;
	char	*path_infile;
	int		fd_out;
	int		fd_in;
	char	*temp;
	int		pid;
	int		pid1;
	int		quote;
	int		std_out;
	int		std_in;
	int		exit_s;
	int		cd;
	char	*oldpwd;
	char	*head;
	char	**envp;
}	t_ms;

typedef struct comand
{
	char	**arg_cmd;
	char	**base_list_cmd;
}	t_cmd;



typedef struct sort
{
	int	*sort;
	int	*catch;
	int	i;
	int	j;
	int k;
}	t_sort;



extern t_ms	g_ms;
#endif
