/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <abarbieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:40:43 by abarbieu          #+#    #+#             */
/*   Updated: 2023/08/16 08:15:36 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	lst;

	if (argc != 5)
		exit (0);
	else
	{
		lst.fd_in = open_file(argv[1], 0);
		lst.fd_out = open_file(argv[4], 1);
	}
	if (pipe(lst.pipefd) == -1)
	{
		perror("Pipe : ");
		exit (1);
	}
	if (is_empty(argv[2], 0) == 0 && is_whitespace(argv[2]) == 0 \
		&& lst.fd_in >= 0)
		first_cmd(argv[2], env, &lst);
	close(lst.pipefd[1]);
	if (is_empty(argv[3], 1) == 0 && is_whitespace(argv[3]) == 0 \
		&& lst.fd_out != -2)
		second_cmd(argv[3], env, &lst);
	close(lst.fd_out);
	waitpid(lst.child, 0, 0);
	waitpid(lst.child_2, 0, 0);
	exit (0);
}
