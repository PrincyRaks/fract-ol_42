/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:48 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/13 16:11:44 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    print_error(char *s)
{
    ft_putstr_fd(s, 2);
    exit(1);
}

// int is_realnumber(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (ft_strchr(str, "."))
//     }
// }