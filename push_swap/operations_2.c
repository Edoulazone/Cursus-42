/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:39:34 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:39:38 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrt_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a) || !a)
		return ;
	tmp = (*a);
	last = ft_last_stack((*a));
	ft_before_last_stack((*a))->next = NULL;
	(*a) = last;
	(*a)->next = tmp;
	ft_in(a);
}

void	rrt_b(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b) || !b)
		return ;
	tmp = (*b);
	last = ft_last_stack((*b));
	ft_before_last_stack((*b))->next = NULL;
	(*b) = last;
	(*b)->next = tmp;
	ft_in(b);
}

void	rrt_ab(t_stack **a, t_stack **b)
{
	rrt_a(a);
	rrt_b(b);
}