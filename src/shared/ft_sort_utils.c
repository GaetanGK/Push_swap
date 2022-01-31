/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:43:14 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/28 10:43:16 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_min(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_last(t_stack *a)
{
	t_stack	*last;

	last = a;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_min_print1(t_stack **a, t_stack **b, t_data *data, int k)
{
	int	i;
	int	j;

	i = ft_get_index((*a), k);
	j = (ft_stack_size((*a)) / 2);
	if (i < j)
		ft_shift_print(a, b, 2, data);
	else
		ft_shift_print(a, b, 3, data);
}

void	ft_sort_print(t_stack **a, t_stack **b, int k, t_data *data)
{
	int	i;
	int	j;

	i = ft_get_index_max((*b), k);
	j = ft_ronded_int((ft_stack_size((*b)) / 2));
	if (j > i && *b)
		ft_shift_print(a, b, 5, data);
	else if (*b)
		ft_shift_print(a, b, 6, data);
}

int	ft_ronded_int(float i)
{
	int	j;

	j = (int) i;
	if ((i - j) >= 0.5)
		return (j + 1);
	else
		return (j);
}
