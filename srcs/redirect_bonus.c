/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:27:46 by hekang            #+#    #+#             */
/*   Updated: 2021/07/01 17:16:24 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirect_in(const char *file)
{
	int	fd;
	char	*line;
	char	*result;

	line = NULL;
	result = NULL;
	fd = open(file, O_RDONLY);
	write(1, "heredoc> ", 9);
	get_next_line(0, &line);
	result = ft_strjoin(result, line);
	printf("%s\n", result);
	//gnl 사용하여 입력값이 limiter와 일치할때 멈춤.
	// if (fd < 0)
	// {
	// 	perror(file);
	// 	exit(1);
	// }
	// dup2(fd, STDIN_FILENO);
	// close(fd);
	return (0);
}

int		redirect_out(const char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
