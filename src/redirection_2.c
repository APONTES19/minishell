/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:24:19 by lucasmar          #+#    #+#             */
/*   Updated: 2022/10/08 16:33:36 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_red_temp(t_ms *ms, int start, int end, char **path)
{
	ms->k = start;
	ms->m = 0;
	ms->t = '\'';
	while (ms->k <= end)
	{
		if (ms->line[ms->k] == '\'')
			ft_red_temp_aux1(ms);
		if (ms->line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_temp_aux1(ms);
		}
		if (ft_strchr("| ><", ms->line[ms->k]) == NULL)
			ms->m++;
		ms->k++;
	}
	ft_red_temp_aux2(ms, start, end, path);
}

void	ft_red_temp_aux1(t_ms *ms)
{
	ms->k++;
	ms->m++;
	while(ms->line[ms->k] != ms->t)
	{
		ms->m++;
		ms->k++;
	}
}

void	ft_red_temp_aux2(t_ms *ms, int start, int end, char **path)
{
	ms->t = '\'';
	*path = (char *) malloc(ms->m * sizeof(char*));
	ms->k = start;
	ms->m = 0;
	while (ms->k <= end)
	{
		if (ms->line[ms->k] == '\'')
			ft_red_temp_aux3(ms, path);
		if (ms->line[ms->k] == '\"')
		{
			ms->t = '\"';
			ft_red_temp_aux3(ms, path);
		}
		if (ft_strchr("| ><", ms->line[ms->k]) == NULL)
		{
			(*path)[ms->m] = ms->line[ms->k];
			ms->m++;
		}
		ms->k++;
	}
	(*path)[ms->m] = '\0';
	ft_red_copy_line(ms, start, end);
}

void	ft_red_temp_aux3(t_ms *ms, char **path)
{
	(*path)[ms->m] = ms->line[ms->k];
	ms->m++;
	ms->k++;
	while(ms->line[ms->k] != ms->t)
	{
		(*path)[ms->m] = ms->line[ms->k];
		ms->m++;
		ms->k++;
	}
}

void	ft_red_copy_line(t_ms *ms, int start, int end)
{
	ms->k = 0;
	ms->m= 0;
	while(ms->line[ms->k])
	{
		if (!(ms->k <= end && ms->k >= start))
			ms->m++;
		ms->k++;
	}
	ms->temp = (char *) malloc (ms->m * sizeof(char *));
	ms->k = 0;
	ms->m = 0;
	while(ms->line[ms->k])
	{
		if (!(ms->k <= end && ms->k >= start))
		{
			if(ms->m == 0 && ms->line[ms->k] == '|')
				ms->k++;
			ms->temp[ms->m] = ms->line[ms->k];
			ms->m++;
	
		}
		ms->k++;
	}
	ms->temp[ms->m] = '\0';
	ft_free_point(ms->line);
	ms->line = ft_strdup(ms->temp);
	ft_free_point(ms->temp);
	printf("%s\n", ms->line);
}
