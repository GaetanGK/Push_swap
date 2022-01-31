/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:36:14 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/21 13:36:16 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_str(char **str)
{
	if (*str)
		free(*str);
}

void	free_data(t_data *data)
{
	if (data)
		free(data);
}

void	ft_free_elem(char **elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		free(elem[i]);
		i++;
	}
	free(elem);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			(*stack) = tmp;
		}
		free(*stack);
		*stack = NULL;
	}
}
