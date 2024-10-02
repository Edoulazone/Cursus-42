/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:51 by eschmitz          #+#    #+#             */
/*   Updated: 2024/10/02 14:04:52 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*create_node(char *command)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->command = strdup(command);
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	execute_tree(t_node *node)
{
	if (!node)
		return ;
	if (strcmp(node->command, "&&") == 0
		|| strcmp(node->command, "||") == 0
		|| strcmp(node->command, "|") == 0)
	{
		execute_tree(node->left);
		execute_tree(node->right);
	}
	else
		printf("Executing: %s\n", node->command);
}
