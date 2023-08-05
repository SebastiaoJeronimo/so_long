/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:36 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/28 18:30:53 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_number(int number, int fd)
{
	if (number > 9)
		print_number(number / 10, fd);
	number = (number % 10) + '0';
	write(fd, &number, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd && fd > 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	print_number(n, fd);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*char_s;

	char_s = (char *) s;
	i = 0;
	while (i < n)
	{
		char_s[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//aloca memoria para guardar uma copia da cadeia de caracteres src 
char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = malloc(ft_strlen(src) + 1);
	if (!ptr)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}
