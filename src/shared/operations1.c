/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:33:33 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/23 21:33:36 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_push_check(t_stack **a, t_stack **b)
{
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*b)->prev = NULL;
	(*b)->nbr = (*a)->nbr;
	(*b)->next = NULL;
	(*a) = (*a)->next;
	(*a)->prev = NULL;
}

void	ft_push(t_stack **a, t_stack **b, t_stack *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
		ft_push_check(a, b);
	else
	{
		if (*a)
		{
			tmp = (t_stack *)malloc(sizeof(t_stack));
			tmp->nbr = (*a)->nbr;
			tmp->next = NULL;
			tmp->prev = NULL;
			ft_add_front(b, tmp);
			(*a) = (*a)->next;
		}
	}
}

void	ft_double_swap(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_double_rotate(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_double_reverse_rotate(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	ft_reverse_rototate(a, tmp);
	ft_reverse_rototate(b, tmp);
}
