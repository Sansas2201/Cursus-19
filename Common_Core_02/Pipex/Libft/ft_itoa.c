/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <abarbieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:25:10 by abarbieu          #+#    #+#             */
/*   Updated: 2023/08/17 13:14:45 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_count(long int n)
{
	n = n / 10;
	return (n);
}

static char	*ft_convert(char *result, long int n, int len)
{
	int	i;

	i = 0;
	result[len - 1] = '\0';
	len--;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (len > 0)
	{
		result[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (i == 1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	temp;
	char		*result;

	n = ((long int)n);
	len = 0;
	temp = n;
	if (temp < 0)
	{
		len++;
		temp *= -1;
	}
	while ((temp / 10) >= 1)
	{
		len++;
		temp = ft_count(temp);
	}
	len += 2;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	ft_convert(result, n, len);
	return (result);
}
