/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:49:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/13 15:35:54 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


void	ft_error(int number, t_ms *ms)
{
	if (number == 0)
		ft_printf("Invalid arguments\n");
	if (number == 1)
		ft_printf("quote is missing\n");
	if (number == 2)
		ft_printf("invalid character: %c\n", ms->line[ms->i]);
	if (number == 3)
		ft_printf("syntax error near "
			"unexpected token `%c'\n", ms->line[ms->i]);
	if (number == 4)
		ft_printf("syntax error near "
			"unexpected token `%c%c'\n", ms->line[ms->i], ms->line[ms->i + 1]);
	if (number == 5)
		ft_printf("malloc error\n");
	if (number == 6)
		ft_printf("envp error\n");
	if (number == 8)
		ft_printf("split error\n");
	if (number == 9)
		ft_printf("pipe error\n");
	if (number == 12)
		ft_printf("Erro no PID arguments\n");
	if (number == 13)
	{
		ft_printf("Erro na Execução do comando com a execve\n");
		exit(3);
	}

}

void	ft_error_2(int number, t_cmd *cmd, t_ms *ms)
{
	if (number == 07)
	{
		ft_printf("%s: command not found\n", cmd[0].arg_cmd[0]);
		if (ms->p == (ms->n_pipe -1))
			ft_base_free(ms, cmd);
	}
}

void	ft_base_free(t_ms *ms, t_cmd *cmd)
{
	printf ("limpando a base\n");
	int i;
	int j;

	j = 0;
	while(j < ms->n_pipe)
	{
		if(ms->n_pipe > 1)
		{
			free(cmd[0].base_list_cmd[j]);
			cmd[0].base_list_cmd[j] = NULL;
		}
	    i = 0;
	    while(cmd[j].arg_cmd[i])
	    {
	        free(cmd[j].arg_cmd[i]);
			cmd[j].arg_cmd[i] = NULL;
	        i ++;
	    }
	    free(cmd[j].arg_cmd);
	    cmd[j].arg_cmd =NULL;
	    j ++;
	}
	if(ms->n_pipe > 1)
		free(cmd[0].base_list_cmd);
	free(cmd);
}

void	ft_exit(t_ms *ms, t_cmd *cmd)
{
	ft_base_free(ms, cmd);
	free (ms->path_cmd);
	ms->path_cmd = NULL;
}
