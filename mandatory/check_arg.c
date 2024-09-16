/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:48 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/16 15:22:33 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    print_error(char *s)
{
    ft_putstr_fd(s, 2);
    exit(1);
}

int is_doubledigit(char *str)
{
    int j;

    j = 0;
    if (*str == '+' || *str == '-')
        str++;
    while (*str || *str == '.')
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

double  ft_atof(char *str)
{
    if (!str)
        return (0.);
    char    **num_s;
    double  result;
    int     neg;

    neg = 1;
    num_s = ft_split(str, '.');
    result = (double)ft_atoi(num_s[0]);
    if (result < 0)
    {
        result = -result;        
        neg = -1;
    }
    result += (double)(ft_atoi(num_s[1]) / pow(10, ft_strlen(num_s[1])));
    return (result * neg);
}
