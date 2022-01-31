/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:40:55 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/28 14:41:00 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_get_pivot(t_stack *tmp)
{
	int		i;
	int		j;
	int		len;
	t_stack	*res;

	i = 0;
	j = 0;
	res = NULL;
	len = ft_stack_size(tmp);
	res = ft_swap_sort(tmp);
	if (len <= 12)
		i = ft_ronded_int(len / 2);
	else if (len > 12 && len < 200)
		i = ft_ronded_int(len / 4);
	else if (len >= 200)
		i = ft_ronded_int(len / 8);
	j = ft_nbr_select(&res, i);
	return (j);
}

int	ft_check_under_pivot(t_stack *a, int i)
{
	while (a)
	{
		if (a->nbr <= i)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_check_upper_pivot(t_stack *a, int i)
{
	while (a)
	{
		if (a->nbr == i)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_get_min(t_stack *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

int	ft_get_max(t_stack *b)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = NULL;
	if (b)
	{
		max = b->nbr;
		tmp = b;
		while (b)
		{
			if (b->nbr >= max)
				max = b->nbr;
			b = b->next;
		}
		b = tmp;
	}
	return (max);
}
