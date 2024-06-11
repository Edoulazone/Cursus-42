/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:44:39 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:38:18 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*ft_process(t_stack *a, t_stack *b)
// {
// 	int	i;
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		index;

	index = 0;
	a = NULL; 
	b = NULL;
	a = ft_conversion_stack(argc, argv, &index);
	b = ft_create_sum();
	printf("Before operation:\n");
	printf("size: %d\n", ft_stack_size(a));
	ft_display_both(a, b);
	swap_a(&a);
	rt_a(&a);
	printf("After operation:\n");
	ft_display_both(a, b);
	return (0);
}

// int	main(void)
// {
// 	t_stack	*s1;
// 	t_stack	*s2;
// 	t_stack	*new;

// 	s1 = ft_new_stack(11);
// 	s2 = ft_new_stack(22);
// 	s1->next = s2;
// 	s2 = ft_new_stack(33);
// 	s1->next->next = s2;
// 	new = ft_new_stack(42);
// 	ft_add_back(&s1, new);
// 	printf("%ld\n", ft_last_stack(s1)->nbr);
// }