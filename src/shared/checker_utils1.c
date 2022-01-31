/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:25:21 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/22 18:25:25 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_free_ope(char **str)
{
	ft_free_elem(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_ope_check(char *elem)
{
	char	**str;
	int		i;

	str = ft_split(elem, '\n');
	i = 0;
	while (str[i])
	{
		if (ft_intruction_check(str[i]) == 1)
		{
			i++;
			continue ;
		}
		else
			ft_free_ope(str);
	}
	ft_free_elem(str);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_select_op_1(t_stack **a, t_stack **b, char *line, t_stack *new)
{
	if (!ft_strcmp(line, "pb") && ft_stack_size(*a) > 0)
		ft_push(a, b, new);
	else if (!ft_strcmp(line, "pa") && ft_stack_size(*b) > 0)
		ft_push(b, a, new);
	else if (!ft_strcmp(line, "ss") && ft_stack_size(*b) > 1
		&& ft_stack_size(*a) > 1)
		ft_double_swap(a, b);
	else if (!ft_strcmp(line, "rr") && ft_stack_size(*b) > 1
		&& ft_stack_size(*a) > 1)
		ft_double_rotate(a, b);
	else if (!ft_strcmp(line, "rrr") && ft_stack_size(*b) > 1
		&& ft_stack_size(*a) > 1)
		ft_double_reverse_rotate(a, b);
}

void	ft_select_op(t_stack **a, t_stack **b, char *line)
{
	t_stack	*new;

	new = NULL;
	if (!ft_strcmp(line, "sa") && ft_stack_size(*a) > 1)
		ft_swap(a);
	else if (!ft_strcmp(line, "sb") && ft_stack_size(*a) > 1)
		ft_swap(b);
	else if (!ft_strcmp(line, "ra") && ft_stack_size(*a) > 1)
		ft_rotate(a);
	else if (!ft_strcmp(line, "rb") && ft_stack_size(*a) > 1)
		ft_rotate(b);
	else if (!ft_strcmp(line, "rra") && ft_stack_size(*a) > 1)
		ft_reverse_rototate(a, new);
	else if (!ft_strcmp(line, "rrb") && ft_stack_size(*a) > 1)
		ft_reverse_rototate(b, new);
	else
		ft_select_op_1(a, b, line, new);
	free_stack(&new);
}
