/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:02:26 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/21 13:02:29 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_data	*ft_init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		exit(0);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->line = NULL;
	data->elem = NULL;
	data->len = 0;
	data->print = 0;
	data->color = 0;
	data->split = 0;
	return (data);
}
