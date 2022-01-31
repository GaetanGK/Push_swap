/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:57 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/23 19:48:17 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_swap(t_stack **head)
{
	int		i;
	int		j;
	t_stack	*tmp;

	tmp = NULL;
	if ((*head) && (*head)->next)
	{
		tmp = *head;
		i = (*head)->nbr;
		j = (*head)->next->nbr;
		tmp = *head;
		(*head)->nbr = j;
		tmp = (*head);
		(*head)->next->nbr = i;
		(*head) = tmp;
	}
}

void	ft_rotate(t_stack **head)
{
	if (*head)
	{
		*head = (*head)->next;
		ft_add_back_stack(head);
	}
}

t_stack	*ft_reverse_rototate1(t_stack *head, t_stack *tmp)
{
	while (head->next)
		head = head->next;
	tmp->nbr = head->nbr;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_reverse_rototate2(t_stack **head)
{
	while ((*head))
	{
		if ((*head)->next->next == NULL)
			break ;
		*head = (*head)->next;
	}
	free((*head)->next);
	(*head)->next = NULL;
}

void	ft_reverse_rototate(t_stack **head, t_stack *tmp)
{
	t_stack	*a;

	a = NULL;
	tmp = NULL;
	if (*head)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			return ;
		tmp = ft_reverse_rototate1(*head, tmp);
		a = *head;
		ft_reverse_rototate2(head);
		*head = a;
		ft_add_front(head, tmp);
	}
}
