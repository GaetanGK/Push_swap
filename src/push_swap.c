/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:00:07 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/12/17 15:00:12 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_fill_elem(t_data *data, int argc, char **argv)
{
	if (!ft_strcmp(argv[1], "-s"))
	{
		data->fd = open("swap.log", O_CREAT | O_RDWR | O_TRUNC, 666);
		if (data->fd == -1)
			ft_putstr_fd("Error file!", 1);
		if (argc == 3)
			data->elem = ft_split(argv[2], ' ');
		else
			data->elem = &argv[2];
	}
	else
	{
		data->fd = 1;
		if (argc == 2)
			data->elem = ft_split(argv[1], ' ');
		else
			data->elem = &argv[1];
	}
	return (data->elem);
}

void	ft_push_swap(t_data *data, int argc, char **argv)
{
	t_stack	*tmp;

	tmp = NULL;
	data->elem = ft_fill_elem(data, argc, argv);
	if (ft_duplicate_check(data->elem))
		ft_error(data, tmp);
	if (ft_alpha_num_check(data->elem))
		ft_error2(data, tmp);
	data->stack_a = ft_stack_insert(data, data->elem, tmp);
	if (data->stack_a == NULL || ft_issorted(&data->stack_a,
			ft_stack_size(data->stack_a)) == 1)
		ft_error(data, tmp);
	data->len = ft_stack_size(data->stack_a);
	free_stack(&tmp);
	if (data->len < 11)
		ft_sort_min(&(data->stack_a), &(data->stack_b), data->len, data);
	else if (data->len > 10 && data->len < 200)
		ft_sort(&(data->stack_a), &(data->stack_b), data->len, data);
	else
		ft_sort_big(&(data->stack_a), &(data->stack_b), data->len, data);
	if (argc == 2 || (argc == 3 && data->fd != 1))
		ft_free_elem(data->elem);
	close(data->fd);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
	{
		data = ft_init(data);
		ft_push_swap(data, argc, argv);
		free_data(data);
	}
	return (0);
}
