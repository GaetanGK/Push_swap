/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:10:08 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/22 15:10:13 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	**ft_split_fill(t_data *data, int argc, char **argv)
{
	if (argc == 2)
		data->elem = ft_split(argv[1], ' ');
	else
		data->elem = &argv[1];
	return (data->elem);
}

t_data	*ft_data_fill(t_data *data)
{
	t_stack	*new;

	new = NULL;
	if (ft_duplicate_check(data->elem))
		ft_error(data, new);
	if (ft_alpha_num_check(data->elem))
		ft_error2(data, new);
	data->stack_a = ft_stack_insert(data, data->elem, new);
	data->len = ft_stack_size(data->stack_a);
	return (data);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = NULL;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (res);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	while (s >= str)
		if (*s-- == (char)c)
			return ((char *)s + 1);
	return (NULL);
}

int	ft_intruction_check(char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "ra"))
		return (1);
	if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "sb"))
		return (1);
	if (!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
		return (1);
	if (!ft_strcmp(line, "pb") || !ft_strcmp(line, "pa"))
		return (1);
	if (!ft_strcmp(line, "ss"))
		return (1);
	if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
		return (1);
	else
		return (0);
}
