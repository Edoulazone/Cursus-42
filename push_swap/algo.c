/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:38:38 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:38:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_bigger(long num, t_stack *b)
{
	int	i;

	if (!b)
		return (0);
	while (b->next)
	{
		if (num > b->nbr)
			b = b->next;
	}
	
}

t_stack	*ft_start_process(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	// first push two numbers 
	push_b(a, b);
	push_b(a, b);
	// then check the large number 
	if (ft_is_bigger((*a)->nbr, *b))
}