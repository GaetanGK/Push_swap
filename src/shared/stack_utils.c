/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:09:53 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/22 00:09:55 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*ft_stack_insert(t_data *data, char **elem, t_stack *new)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		new = malloc(sizeof(t_stack));
		if (new == NULL)
			return (NULL);
		new->next = NULL;
		new->prev = NULL;
		new->nbr = my_atoi(elem[i], data, new);
		if (!(new->nbr >= -2147483648 && new->nbr <= 2147483647))
		{
			ft_putstr_fd("Error\n", 2);
			ft_error(data, new);
		}
		ft_add_back(&data->stack_a, new);
		new = NULL;
		i++;
	}
	return (data->stack_a);
}

int	ft_stack_size(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	ft_sort_check(t_data *data, char **line)
{
	if (ft_issorted(&data->stack_a, data->len) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_str(line);
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	free(data);
	exit(1);
}

int	ft_issorted(t_stack **a, int len)
{
	t_stack	*tmp;

	if (ft_stack_size(*a) != len)
		return (0);
	(void)len;
	tmp = (*a);
	while (tmp && tmp->next)
	{
		if ((tmp)->next != NULL && ((tmp)->nbr < (tmp)->next->nbr))
			(tmp) = (tmp)->next;
		else
			return (0);
	}
	return (1);
}

int	ft_nbr_select(t_stack **head, int i)
{
	t_stack	*tmp;
	int		j;

	j = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		if (j == i)
			return (tmp->nbr);
		j++;
		tmp = tmp->next;
	}
	return (1);
}
