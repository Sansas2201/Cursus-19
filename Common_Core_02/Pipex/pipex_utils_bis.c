/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <abarbieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:26:03 by abarbieu          #+#    #+#             */
/*   Updated: 2023/08/14 15:36:07 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_file(char *argv, int in_or_out)
{
	write(2, "zsh: no such file or directory: ", 32);
	ft_putstr_fd(argv, 2);
	write(2, "\n", 1);
	if (in_or_out == 1)
		exit(-1);
}

int	check_in(char *argv)
{
	int	acc;

	acc = access(argv, F_OK);
	if (acc == -1)
		return (-1);
	if (acc == 0)
		acc = access(argv, R_OK);
	if (acc == 0)
		return (0);
	else
	{
		write(2, "zsh: permission denied: ", 24);
		ft_putstr_fd(argv, 2);
		write(2, "\n", 1);
		return (-2);
	}
}

int	check_out(char *argv)
{
	int	acc;

	acc = access(argv, F_OK);
	if (acc == -1)
		return (0);
	else if (acc == 0)
		acc = access(argv, W_OK);
	if (acc == 0)
		return (0);
	else
	{
		write(2, "zsh: permission denied: ", 24);
		ft_putstr_fd(argv, 2);
		write(2, "\n", 1);
		return (-2);
	}
}

void	command_not_found(char *argv)
{
	if (argv[0] == '/')
		write(2, "zsh: no such file or directory: ", 32);
	else
		write(2, "zsh: command not found: ", 24);
	ft_putstr_fd(argv, 2);
	write(2, "\n", 1);
}
