/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:40:53 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:40:54 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "../Libft/libft.h"

// the structure used to define a stack in m program

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}t_stack;

// Main function which is processing the recieved 
// arguments and parsing them into numbers to be added to stack a
t_stack	*ft_conversion_stack(int argc, char **argv, int *index);

// push_swap stack manupulation functions
t_stack	*ft_new_stack(long num);
int	ft_stack_size(t_stack *stack);
t_stack	*ft_last_stack(t_stack *stack);
t_stack	*ft_before_last_stack(t_stack *stack);
void	ft_add_back(t_stack **stack, t_stack *new_node, int *index);
int		ft_my_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*my_ft_strjoin(char *my_stash, char *buffer);

// functions that help with index modification
t_stack	*ft_assign_index(t_stack *a);
void	ft_in(t_stack **a);
t_stack	*ft_create_sum(void);
void	ft_display_stack(t_stack *a);
void	ft_display_both(t_stack *a, t_stack *b);

// Instructions funcitons 
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_ab(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rt_a(t_stack **a);
void	rt_b(t_stack **b);
void	rt_ab(t_stack **a, t_stack **b);
void	rrt_a(t_stack **a);
void	rrt_b(t_stack **b);
void	rrt_ab(t_stack **a, t_stack **b);

// additional functions in utensils to deal with stacks and errors
void	ft_error(char *str);
int		ft_isdigit(int c);

#endif