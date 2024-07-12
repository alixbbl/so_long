/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:42:08 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/17 13:35:52 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i] && fd > 0)
	{
		ret = write(fd, &str[i], 1);
		if (ret < 0)
			ft_error("write error", NULL);
		i++;
	}
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	if (!str || !n)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		a;
	void		*ptr;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	a = nmemb * size;
	if (a / nmemb != size)
		return (0);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
