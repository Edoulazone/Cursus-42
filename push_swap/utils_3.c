/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:42:12 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:42:13 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_assign_index(t_stack *a)
{
	long	i;
	t_stack	*head;

	i = 0;
	head = a;
	if (!a)
		return (NULL);
	while (a)
	{
		a->index = i;
		i++;
		a = a->next;
	}
	a = head;
	return (a);
}

void	ft_in(t_stack **a)
{
	long	i;
	t_stack	*tmp;

	i = 0;
	tmp = (*a);
	if (!(*a) || !a)
		return ;
	while (*a)
	{
		(*a)->index = i;
		i++;
		(*a) = (*a)->next;
	}
	(*a) = tmp;
}

t_stack	*ft_create_sum(void)
{
	t_stack	*new;
	t_stack	*b;

	b = ft_new_stack(7);
	b->next = NULL;
	new = ft_new_stack(8);
	new->next = NULL;
	b->next = new;
	new = ft_new_stack(9);
	new->next = NULL;
	b->next->next = new;
	b = ft_assign_index(b);
	return (b);
}

void	ft_display_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (!tmp)
		printf("No node");
	while (tmp)
	{
		printf("1st: Index[%ld]: %ld\n", tmp->index, tmp->nbr);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_display_both(t_stack *a, t_stack *b)
{
	printf("Stacks a & b:\n");
	ft_display_stack(a);
	ft_display_stack(b);
}