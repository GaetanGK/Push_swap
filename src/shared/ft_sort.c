/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:38:17 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/28 13:38:21 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sort3(t_stack **a, t_stack **b, int k, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*b)
	{
		k = ft_get_max(*b);
		while (ft_check_upper_pivot((*b), k))
		{
			k = ft_get_max(*b);
			tmp = (*b)->next;
			while ((*b)->nbr != k && tmp && tmp->nbr == k)
				ft_shift_print(a, b, 7, data);
			while (((*b)->nbr != k) && *b)
				ft_sort_print(a, b, k, data);
			while (*b && (*b)->nbr == k)
			{
				tmp = *b;
				ft_shift_print(a, b, 4, data);
				k = ft_get_max(*b);
				free(tmp);
			}
		}
	}
}

void	ft_sort2(t_stack **a, t_stack **b, int k, t_data *data)
{
	int		i;
	t_stack	*tmp;

	tmp = NULL;
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
				tmp = *a;
				ft_shift_print(a, b, 1, data);
				free(tmp);
				k--;
			}
			else
				ft_min_print1(a, b, data, i);
		}
	}	
}

void	ft_sort1(t_stack **a, t_stack **b, int len, t_data *data)
{
	int		i;
	int		j;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = len;
	while (i >= ft_ronded_int(len / 4))
	{
		tmp2 = ft_stackdup(*a);
		j = ft_get_pivot(tmp2);
		while (ft_check_under_pivot((*a), j) && (*a))
		{
			if ((*a)->nbr <= j)
			{
				tmp1 = *a;
				ft_shift_print(a, b, 1, data);
				i--;
				free(tmp1);
			}
			else
				ft_min_print1(a, b, data, j);
		}
		free_stack(&tmp2);
	}
}

void	ft_sort(t_stack **a, t_stack **b, int k, t_data *data)
{
	int	i;

	i = 0;
	ft_sort1(a, b, k, data);
	ft_sort2(a, b, k, data);
	ft_sort3(a, b, i, data);
	free_stack(a);
	free_stack(b);
}
