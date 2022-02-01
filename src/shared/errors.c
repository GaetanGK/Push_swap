/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:54:05 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/21 16:54:09 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_duplicate_check(char **elem)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (elem[++i])
	{
		str = ft_strdup(elem[i]);
		j = 0;
		while (elem[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(str, elem[j]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				free_str(&str);
				return (1);
			}
			else
				j++;
		}
		free_str(&str);
	}
	return (0);
}

int	ft_if_str_exist(char **str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	return (1);
}

int	ft_alpha_num_check(char **elem)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_if_str_exist(elem))
		return (1);
	while (elem[i])
	{
		j = 0;
		while (elem[i][j])
		{
			if (ft_isalpha(elem[i][j]) == 1 || elem[i][j] == '.'
				|| ((elem[i][j]) == '-' && (elem[i][j + 1]) == '\0')
				|| ((elem[i][j]) == '+' && (elem[i][j + 1]) == '\0'))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(t_data *data, t_stack *tmp)
{
	free_stack(&tmp);
	free_stack(&data->stack_a);
	free_data(data);
	exit (1);
}

void	ft_error2(t_data *data, t_stack *tmp)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(&tmp);
	free_stack(&data->stack_a);
	free_data(data);
	exit (1);
}
