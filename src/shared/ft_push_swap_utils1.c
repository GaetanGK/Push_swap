/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:50:06 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/21 16:50:07 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	res = NULL;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

static long long	operation(const char *str, long lenght,
								t_data *data, t_stack *tmp)
{
	long long	r;

	r = 0;
	while (str[lenght] >= 48 && str[lenght] <= 57)
	{
		r = r * 10 + str[lenght] - '0';
		lenght++;
	}
	while (str[lenght] != '\0')
	{
		if (!(str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t'
				|| str[lenght] == '\r' || str[lenght] == '\f'
				|| str[lenght] == '\v'))
		{
			ft_putstr_fd("Error\n", 2);
			ft_error(data, tmp);
		}
		lenght++;
	}
	return (r);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

long long	my_atoi(const char *str, t_data *data, t_stack *tmp)
{
	long	len;
	int		sign;

	len = 0;
	sign = 1;
	if (!((str[0] >= 48 && str[0] <= 57) || str[0] == '-'
			|| str[0] == '+'))
	{
		ft_putstr_fd("Error\n", 2);
		ft_error(data, tmp);
	}
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t'
		|| str[len] == '\r' || str[len] == '\f' || str[len] == '\v')
		len++;
	if (str[len] == '-' || str[len] == '+')
	{
		if (str[len] == '-')
			sign *= -1;
		len++;
	}
	return (sign * (operation(str, len, data, tmp)));
}
