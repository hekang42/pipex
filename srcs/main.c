/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:13:05 by hekang            #+#    #+#             */
/*   Updated: 2021/07/01 16:51:50 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void		cmd_init(const char *cmd, t_cmd *strt)
{
	char		**chunk;

	chunk = ft_split(cmd, ' ');
	strt->cmd[0] = ft_strjoin("/bin/", chunk[0]);
	strt->cmd[1] = ft_strjoin("/usr/local/bin/", chunk[0]);
	strt->cmd[2] = ft_strjoin("/usr/bin/", chunk[0]);
	strt->cmd[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	strt->cmd[4] = ft_strjoin("/sbin/", chunk[0]);
	strt->argv = (char *const *)chunk;
}

static void		run_cmd(const char *cmd, t_cmd *cmd_arg)
{
	int			i;
	extern char	**environ;

	i = 0;
	cmd_init(cmd, cmd_arg);
	while (i < 5)
		execve(cmd_arg->cmd[i++], cmd_arg->argv, environ);
	perror(cmd_arg->argv[0]);
}

int				main(int argc, char **argv)
{
	int			pipefd[2];
	pid_t		pid;
	t_cmd		cmd;
	int			status;

	if (argc != 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		run_cmd(argv[3], &cmd);
	}
	else if (pid == 0)
	{
		redirect_in(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_cmd(argv[2], &cmd);
	}
	return (0);
}
