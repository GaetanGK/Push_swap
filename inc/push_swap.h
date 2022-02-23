/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:19:07 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/12/18 17:19:09 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 100000

typedef struct s_stack
{
	long long		nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct s_data
{
	char			**elem;
	char			**argv;
	char			*line;
	int				print;
	int				color;
	int				len;
	int				argc;
	int				fd;
	int				split;
	t_stack			*stack_a;
	t_stack			*stack_b;
}			t_data;

t_data		*ft_init(t_data *data);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
int			ft_duplicate_check(char **elem);
void		free_str(char **str);
void		free_data(t_data *data);
int			ft_alpha_num_check(char **elem);
int			ft_isalpha(int c);
void		ft_free_elem(char **elem);
t_stack		*ft_stack_insert(t_data *data, char **elem, t_stack *new);
long long	my_atoi(const char *str, t_data *data, t_stack *tmp);
void		ft_add_back(t_stack **head, t_stack *new);
void		ft_sort_check(t_data *data);
int			ft_issorted(t_stack **a, int len);
int			ft_stack_size(t_stack *a);
void		free_stack(t_stack **stack);
char		**ft_split_fill(t_data *data, int argc, char **argv);
t_data		*ft_data_fill(t_data *data);
void		ft_bzero(void *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *s, int c);
int			ft_ope_check(char *elem);
int			ft_intruction_check(char *line);
void		ft_sort(t_stack **a, t_stack **b, int len, t_data *data);
char		*ft_strchr(const char *s, int c);
char		**ft_checker_ope(t_data *data, char **line, char *tmp);
char		*ft_line(t_data *data, char *tmp);
void		ft_select_op(t_stack **a, t_stack **b, char *line);
void		ft_swap(t_stack **head);
void		ft_rotate(t_stack **head);
void		ft_add_back_stack(t_stack **head);
void		ft_reverse_rototate(t_stack **head, t_stack *tmp);
void		ft_push(t_stack **a, t_stack **b, t_stack *tmp);
void		ft_double_reverse_rotate(t_stack **a, t_stack **b);
void		ft_double_rotate(t_stack **a, t_stack **b);
void		ft_double_swap(t_stack **a, t_stack **b);
void		ft_add_front(t_stack **head, t_stack *tmp);
void		ft_sort_min(t_stack **a, t_stack **b, int i, t_data *data);
void		ft_shift_print(t_stack **a, t_stack **b, int i, t_data *data);
int			ft_min(t_stack *a);
t_stack		*ft_last(t_stack *a);
void		ft_shift_3(t_stack **a, t_stack **b, int len, t_data *data);
void		ft_min_print1(t_stack **a, t_stack **b, t_data *data, int k);
int			ft_get_index(t_stack *a, int k);
void		ft_sort1(t_stack **a, t_stack **b, int k, t_data *data);
int			ft_ronded_int(float i);
t_stack		*ft_stackdup(t_stack *head);
int			ft_get_pivot(t_stack *tmp);
t_stack		*ft_swap_sort(t_stack *head);
int			ft_check_under_pivot(t_stack *a, int i);
int			ft_nbr_select(t_stack **head, int i);
int			ft_get_min(t_stack *a);
int			ft_get_max(t_stack *b);
int			ft_check_upper_pivot(t_stack *a, int i);
void		ft_sort_print(t_stack **a, t_stack **b, int k, t_data *data);
int			ft_get_index_max(t_stack *a, int k);
void		ft_sort_big(t_stack **a, t_stack **b, int k, t_data *data);
void		ft_error(t_data *data, t_stack *tmp);
void		ft_error2(t_data *data, t_stack *tmp);

#endif