/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:39:47 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:39:49 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rt_a(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	ft_last_stack((*a))->next = tmp;
	tmp->next = NULL;
	ft_in(a);
}

void	rt_b(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !b)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_last_stack((*b))->next = tmp;
	tmp->next = NULL;
	ft_in(b);
}

void	rt_ab(t_stack **a, t_stack **b)
{
	rt_a(a);
	rt_b(b);
}