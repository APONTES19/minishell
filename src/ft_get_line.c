/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:31:52 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/22 17:40:21 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_get_line(t_ms *ms)
{
	ft_get_head_line(ms);
	ms->line = readline(ms->head);
	if (ms->line == NULL)
	{
		printf("CTRL+D\n");
		ft_free_crtl_d(ms);
	}
	if (ft_strncmp_m(ms->line, "") == 0)
	{
		ft_free_point(ms->head);
		ft_free_point(ms->line);
		ft_get_line(ms);
		return ;
	}
	else if (ms->line[0] == ' ')
		ft_check_space(ms);
	ft_free_point(ms->head);
}

void	ft_get_head_line(t_ms *ms)
{
	char	*temp;
	char	*s;
	char	*temp1;
	char	*temp2;

	temp = ft_strdup("\x1b[38;2;255;255;0mMinishell\x1b[0m:");
	if (temp == NULL)
		temp = ft_strdup("");
	s = (char *) malloc(1024 * sizeof(char));
	getcwd(s, 1024);
	if (s == NULL)
		s = ft_strdup("-->");
	temp1 = ft_strjoin("\x1b[38;2;255;69;0m", s);
	ft_free_point(s);
	temp2 = ft_strjoin(temp1, "\x1b[0m$ ");
	ft_free_point(temp1);
	if (temp2 == NULL)
		temp2 = ft_strdup("\x1b[38;2;255;255;0mMinishell\x1b[0m:");
	ms->head = ft_strjoin(temp, temp2);
	ft_free_point(temp);
	ft_free_point(temp2);
}
