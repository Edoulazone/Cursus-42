/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:41:28 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:41:29 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(long num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->nbr = num;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_last_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_before_last_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_add_back(t_stack **stack, t_stack *new_node, int *index)
{
	if (!stack)
		return ;
	if (!(*stack))
	{
		*stack = new_node;
		(*stack)->index = *index;
	}
	else
	{
		(ft_last_stack(*stack))->next = new_node;
		(ft_last_stack(*stack))->index = *index;
	}
	(*index)++;
}

int	ft_my_atoi(const char *str)
{
	long long int	result;
	int				sign;

	sign = 1;
	result = 0;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error("Number is not a digit!");
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		ft_error("integer limit overloaded!");
	return (result * sign);
}