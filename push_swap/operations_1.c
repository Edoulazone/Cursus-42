/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:39:20 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:39:22 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!(*a) || !a)
		return ;
	tmp = *a;
	tmp_next = (*a)->next->next;
	(*a) = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = tmp_next;
	ft_in(a);
}

void	swap_b(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!(*b) || !b)
		return ;
	tmp = *b;
	tmp_next = (*b)->next->next;
	(*b) = (*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = tmp_next;
	(*b) = ft_assign_index((*b));
}

void	swap_ab(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	if (!(*b) || !b)
		return ;
	tmp_b = *b;
	tmp_a = *a;
	(*b) = (*b)->next;
	(*a) = tmp_b;
	(*a)->next = tmp_a;
	ft_in(a);
	ft_in(b);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	if (!(*a) || !a)
		return ;
	tmp_b = *b;
	tmp_a = *a;
	(*a) = (*a)->next;
	(*b) = tmp_a;
	(*b)->next = tmp_b;
	ft_in(a);
	ft_in(b);
}