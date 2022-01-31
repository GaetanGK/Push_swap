/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:36:58 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/22 02:37:38 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_line(t_data *data, char *tmp)
{
	char	*str;

	str = NULL;
	data->line = malloc(sizeof(char) * BUFFER_SIZE);
	ft_bzero(data->line, BUFFER_SIZE);
	while (read(0, data->line, BUFFER_SIZE))
	{
		tmp = str;
		if (str == NULL)
			str = ft_strdup(data->line);
		else
			str = ft_strjoin(str, data->line);
		if (data->argc >= 2 && !ft_strchr(data->argv[1], ' '))
			ft_ope_check(data->line);
		if (tmp)
			free(tmp);
		free_str(&data->line);
		data->line = malloc(sizeof(char) * BUFFER_SIZE);
		ft_bzero(data->line, BUFFER_SIZE);
	}
	return (str);
}

void	ft_do_ope(t_data *data, char **line, int i)
{
	while (line[i])
	{
		if (data->argc <= 2)
		{
			ft_select_op(&data->stack_a, &data->stack_b, line[i]);
			i++;
		}
		else
		{
			if (ft_intruction_check(line[i]) == 1)
			{
				ft_select_op(&data->stack_a, &data->stack_b, line[i]);
				i++;
			}
			else
			{
				ft_free_elem(line);
				free_stack(&data->stack_a);
				free_stack(&data->stack_b);
				ft_putstr_fd("Error\n", 2);
				free(data);
				exit(1);
			}
		}
	}
}

char	**ft_checker_ope(t_data *data, char **line, char *tmp)
{
	char	*str;

	str = NULL;
	str = ft_line(data, tmp);
	if (str)
	{
		line = ft_split(str, '\n');
		free_str(&str);
	}
	else
		ft_sort_check(data, &str);
	return (line);
}

void	ft_checker(t_data *data, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	line = ft_checker_ope(data, line, tmp);
	ft_do_ope(data, line, i);
	ft_sort_check(data, line);
	ft_free_elem(line);
}

int	main(int argc, char	**argv)
{
	t_data	*data;
	char	**line;

	data = NULL;
	line = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		data = ft_init(data);
		data->argc = argc;
		data->argv = argv;
		data->elem = ft_split_fill(data, argc, argv);
		data = ft_data_fill(data);
		ft_checker(data, line);
	}
	return (0);
}
