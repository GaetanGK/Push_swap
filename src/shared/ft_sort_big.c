/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:53:39 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/30 17:53:40 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort_big3(t_stack **a, t_stack **b, int k, t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	while (*b)
	{
		k = ft_get_max(*b);
		while (ft_check_upper_pivot(*b, k))
		{
			k = ft_get_max(*b);
			tmp = (*b)->next;
			while ((*b)->nbr != k && tmp && tmp->nbr == k)
				ft_shift_print(a, b, 7, data);
			while (((*b)->nbr != k) && *b)
				ft_sort_print(a, b, k, data);
			while (*b && (*b)->nbr == k)
			{
				tmp1 = *b;
				ft_shift_print(a, b, 4, data);
				k = ft_get_max(*b);
				free(tmp1);
			}
		}
	}	
}

void	ft_sort_big2(t_stack **a, t_stack **b, int k, t_data *data)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp1;

	while (*a && !ft_issorted(a, k))
	{
		i = ft_get_min(*a);
		tmp = (*a)->next;
		while ((*a)->nbr != i && tmp && tmp->nbr == i)
			ft_shift_print(a, b, 8, data);
		while (ft_stack_size(*a) && ft_check_under_pivot((*a), i))
		{
			if ((*a)->nbr == i)
			{
				tmp1 = *a;
				ft_shift_print(a, b, 1, data);
				free(tmp1);
				k--;
			}
			else
				ft_min_print1(a, b, data, i);
		}
	}
}

void	ft_sort_big1(t_stack **a, t_stack **b, int k, t_data *data)
{
	int		i;
	int		j;
	t_stack	*tmp;
	t_stack	*tmp1;

	i = k;
	while (i >= ft_ronded_int(k / 8))
	{
		tmp1 = ft_stackdup(*a);
		j = ft_get_pivot(tmp1);
		while (ft_check_under_pivot((*a), j) && (*a))
		{
			if ((*a)->nbr <= j)
			{
				tmp = *a;
				ft_shift_print(a, b, 1, data);
				i--;
				free(tmp);
			}
			else
				ft_min_print1(a, b, data, j);
		}
		free_stack(&tmp1);
	}
}

void	ft_sort_big(t_stack **a, t_stack **b, int k, t_data *data)
{
	int	i;

	i = 0;
	ft_sort_big1(a, b, k, data);
	ft_sort_big2(a, b, k, data);
	ft_sort_big3(a, b, i, data);
	free_stack(a);
	free_stack(b);
}
