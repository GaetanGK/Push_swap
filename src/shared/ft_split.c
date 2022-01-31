/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkatounk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:20:33 by gkatounk          #+#    #+#             */
/*   Updated: 2021/12/21 16:20:35 by gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static char	**ft_free_ptr(char **ptr)
{
	size_t	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
			free(ptr[i++]);
		free(ptr);
	}
	return (0);
}

static size_t	ft_strllen(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

static	size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res++;
		while (s[i] != c && s[i])
			i++;
	}
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = NULL;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(&s[start]);
	if (i > len)
		i = len;
	res = malloc((i + 1) * sizeof(char));
	if (!(res == NULL))
		ft_strlcpy(res, &s[start], i + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	words;

	words = ft_countword(s, c);
	i = -1;
	j = 0;
	k = 0;
	res = malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (ft_free_ptr(res));
	while (++i < words)
	{
		k += j;
		while (s[k] == c)
			k++;
		j = ft_strllen(s, k, c);
		res[i] = ft_substr(s, k, j);
		if (!res[i])
			return (ft_free_ptr(res));
	}
	res[words] = 0;
	return (res);
}
