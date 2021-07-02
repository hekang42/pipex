/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:44:26 by hekang            #+#    #+#             */
/*   Updated: 2021/07/02 10:42:21 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

typedef struct		s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
	char * const	*envp;
}					t_cmd;

typedef struct		s_input
{
	const char		*f1;
	const char		*f2;
	const char		*cmd1;
	const char		*cmd2;
}					t_input;

int					redirect_in(const char *file);
int					redirect_out(const char *file, int argc);
void				heredoc(char **argv);

#endif
