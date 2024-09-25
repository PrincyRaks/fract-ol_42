/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:48 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 14:54:06 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

int	is_doubledigit(char *str)
{
	int	j;

	j = 0;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '.')
		return (0);
	while (*str)
	{
		if (*str != '.' && !ft_isdigit(*str))
			return (0);
		if (*str == '.')
			j++;
		if (j > 1)
			return (0);
		str++;
	}
	return (1);
}

static int	count_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (*tab != NULL)
	{
		i++;
		tab++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	char	**num_s;
	double	result;
	double	neg;
	int		len_tab;

	if (!str)
		return (0.);
	neg = 1.;
	num_s = ft_split(str, '.');
	if (!num_s)
		return (0.);
	result = (double)ft_atoi(num_s[0]);
	if (*(num_s[0]) == '-')
	{
		result = -result;
		neg = -1.;
	}
	len_tab = count_tab(num_s);
	if (len_tab == 2)
		result += (double)(ft_atoi(num_s[1]) / pow(10, ft_strlen(num_s[1])));
	free_tab(num_s, len_tab);
	return (result * neg);
}
