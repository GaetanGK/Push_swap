/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:35:12 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/27 16:35:14 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_double_shift_print(t_stack **a, t_stack **b, t_data *data)
{
	ft_shift_print(a, b, 8, data);
	ft_shift_print(a, b, 3, data);
}

void	ft_shift_3(t_stack **a, t_stack **b, int len, t_data *data)
{
	int		i;
	t_stack	*last;

	i = ft_min(*a);
	last = ft_last(*a);
	while (ft_issorted(a, len) == 0)
	{
		if ((*a)->nbr < (*a)->next->nbr && last->nbr == i)
			ft_shift_print(a, b, 3, data);
		else if ((*a)->nbr > (*a)->next->nbr && last->nbr == i)
			ft_double_shift_print(a, b, data);
		else if ((*a)->next->nbr == i)
		{
			if ((*a)->nbr < last->nbr)
				ft_shift_print(a, b, 8, data);
			else if ((*a)->nbr > last->nbr)
				ft_shift_print(a, b, 2, data);
		}
		else if ((*a)->nbr == i && (*a)->next->nbr > last->nbr)
		{
			ft_shift_print(a, b, 8, data);
			ft_shift_print(a, b, 2, data);
		}
	}
}

void	ft_min_sort1(t_stack **a, t_stack **b, int len, t_data *data)
{
	int		i;
	int		j;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = len;
	while (i > 3)
	{
		j = ft_min(*a);
		tmp1 = (*a)->next;
		if ((*a)->nbr != j && tmp1 && tmp1->nbr == j)
			ft_shift_print(a, b, 8, data);
		while (j != (*a)->nbr)
			ft_min_print1(a, b, data, j);
		if (j == (*a)->nbr)
		{
			tmp2 = *a;
			ft_shift_print(a, b, 1, data);
			free(tmp2);
			i--;
		}
	}
}

void	ft_sort_min(t_stack **a, t_stack **b, int len, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->nbr > (*a)->next->nbr)
		ft_shift_print(a, b, 8, data);
	if (len <= 3)
		ft_shift_3(a, b, len, data);
	else if (len > 3)
	{
		ft_min_sort1(a, b, len, data);
		ft_shift_3(a, b, 3, data);
		while (*b)
		{
			tmp = *b;
			ft_shift_print(a, b, 4, data);
			free (tmp);
		}
		free_stack(b);
	}
	free_stack(a);
}

t_stack	*ft_stackdup(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp1 = malloc(sizeof(t_stack));
	ft_bzero(tmp1, sizeof(t_stack));
	tmp = tmp1;
	while (head)
	{
		tmp1->nbr = head->nbr;
		if (head->next)
		{
			tmp1->next = malloc(sizeof(t_stack));
			ft_bzero(tmp1->next, sizeof(t_stack));
			tmp1 = tmp1->next;
		}
		head = head->next;
	}
	tmp1 = tmp;
	return (tmp1);
}
