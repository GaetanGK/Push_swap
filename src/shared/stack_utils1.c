/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:12:47 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/22 01:12:49 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_add_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_add_back_stack(t_stack **head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = NULL;
	tmp1 = *head;
	tmp2 = (*head)->prev;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->prev = tmp1;
	tmp1->next->next = NULL;
}

void	ft_add_front(t_stack **head, t_stack *tmp)
{
	tmp->next = (*head);
	tmp->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = tmp;
	(*head) = tmp;
}

int	ft_get_index_max(t_stack *a, int k)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->nbr >= k)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int	ft_get_index(t_stack *a, int k)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->nbr <= k)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}
