/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:27:46 by hekang            #+#    #+#             */
/*   Updated: 2021/07/02 14:03:53 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		clear_temp(void)
{
	char **argv;

	argv = malloc(sizeof(char *) * 3);
	argv[0] = "-f";
	argv[1] = "./temp";
	argv[2] = NULL;
	if (fork() == 0)
		execve("/bin/rm", (char *const *)argv, NULL);
}

void		heredoc(char **argv)
{
	char	*limiter;
	char	*line;
	int		fd;

	line = NULL;
	limiter = argv[2];
	fd = open("./temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(STDOUT_FILENO, "heredoc> ", 9);
	while (get_next_line(0, &line) != 0)
	{
		if (!ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		write(STDOUT_FILENO, "heredoc> ", 9);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	close(fd);
	redirect_in("./temp");
	clear_temp();
}
