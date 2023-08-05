/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:40:28 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/31 20:51:33 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i++])
		;
	return (i);
}

void	str_arr_free(t_win *window)
{
	int	i;

	i = 0;
	while (window->map_ptr.map[i])
	{
		free(window->map_ptr.map[i]);
		i++;
	}
	free(window->map_ptr.map);
}

int	ft_special_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

int	is_invalid_char(char c)
{
	if (ft_strchr("PEC10", c))
		return (0);
	write (1, "invalid char\n", 14);
	return (1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *) &str[i]);
	return (0);
}
