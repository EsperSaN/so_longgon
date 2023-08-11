/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:35:51 by pruenrua          #+#    #+#             */
/*   Updated: 2023/08/11 16:37:20 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	plz_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	min_int_welcome(int *n, char *a, unsigned int *len)
{
	if (*n == -2147483648)
	{
		a[*len - 1] = '8';
		*n = 214748364;
		*len = *len - 1;
	}
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	len;

	len = plz_count(n);
	a = ft_calloc((len + 1), sizeof(char));
	if (!a)
		return (0);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		a[0] = '-';
	}
	min_int_welcome(&n, a, &len);
	while (n && len > 0)
	{
		a[len-- - 1] = ('0' + (n % 10));
		n = n / 10;
	}
	return (a);
}
