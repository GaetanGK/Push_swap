/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:49:44 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/27 16:49:46 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_shift_print2(t_stack **a, t_stack **b, int i, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (i == 6 && ft_stack_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", data->fd);
		ft_reverse_rototate(b, tmp);
	}
	else if (i == 7 && ft_stack_size(*b) > 1)
	{	
		ft_putstr_fd("sb\n", data->fd);
		ft_swap(b);
	}
	else if (i == 8 && ft_stack_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", data->fd);
		ft_swap(a);
	}
}

void	ft_shift_print1(t_stack **a, t_stack **b, int i, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (i == 3 && ft_stack_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", data->fd);
		ft_reverse_rototate(a, tmp);
	}
	else if (i == 4)
	{
		ft_putstr_fd("pa\n", data->fd);
		ft_push(b, a, tmp);
	}
	else if (i == 5 && ft_stack_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", data->fd);
		ft_rotate(b);
	}
	else
		ft_shift_print2(a, b, i, data);
}

void	ft_shift_print(t_stack **a, t_stack **b, int i, t_data *data)
{
	t_stack	*tmp;

	tmp = NULL;
	if (i == 1)
	{
		ft_putstr_fd("pb\n", data->fd);
		ft_push(a, b, tmp);
	}
	else if (i == 2)
	{
		ft_putstr_fd("ra\n", data->fd);
		ft_rotate(a);
	}
	else
		ft_shift_print1(a, b, i, data);
	free(tmp);
}

void	ft_swap_nbr(t_stack *a, t_stack *b)
{
	int	i;

	i = a->nbr;
	a->nbr = b->nbr;
	b->nbr = i;
}

t_stack	*ft_swap_sort(t_stack *head)
{
	t_stack	*start;
	t_stack	*tmp;
	t_stack	*min;

	start = NULL;
	start = head;
	tmp = NULL;
	min = NULL;
	while (start->next)
	{
		min = start;
		tmp = start->next;
		while (tmp)
		{
			if (min->nbr > tmp->nbr)
				min = tmp;
			tmp = tmp->next;
		}
		ft_swap_nbr(start, min);
		start = start->next;
	}
	return (head);
}
