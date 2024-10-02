/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:20:31 by eschmitz          #+#    #+#             */
/*   Updated: 2024/10/02 14:37:03 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libraries.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_shell
{
	t_list	*env;
	char	*home;
	t_list	*allocated_pointers[3];
	t_list	*temporary_files;
	char	*parsing_error;
	bool	in_main_process;
	int		last_status;	
}	t_shell;

typedef enum e_prompt_mode
{
	MAIN_PROMPT,
	HEREDOC_PROMPT
}	t_prompt_mode;

typedef struct s_node
{
	char			*command;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef enum e_ast_type
{
	AST_COMMAND,
	AST_SUBSHELL,
	AST_LOGICAL,
	AST_PIPELINE,
	AST_REDIRECTION,
	AST_SYNTAX_ERROR
}	t_ast_type;

typedef enum e_token_type
{
	TK_ERROR,
	TK_WORD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_REDIRECT_IN,
	TK_REDIRECT_OUT,
	TK_APPEND_OUT,
	TK_HEREDOC,
	TK_SUBSHELL_OPEN,
	TK_SUBSHELL_CLOSE
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

typedef struct s_ast_command
{
	char	**args;
}	t_ast_command;

typedef struct s_ast_pipeline
{
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast_pipeline;

typedef struct s_ast_logical
{
	t_token_type	operator;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast_logical;

typedef struct s_ast_redirection
{
	t_token_type	direction;
	struct s_ast	*child;
	char			*file;
}	t_ast_redirection;

typedef struct s_ast_subshell
{
	struct s_ast	*child;
}	t_ast_subshell;

typedef struct s_ast_syntax_error
{
	char	*unusual_token;
}	t_ast_syntax_error;

typedef struct s_ast
{
	t_ast_type				type;
	union
	{
		t_ast_command		command;
		t_ast_pipeline		pipeline;
		t_ast_logical		logical;
		t_ast_redirection	redirection;
		t_ast_subshell		subshell;
		t_ast_syntax_error	s_error;
	}	u_data;
}	t_ast;

typedef enum e_tracking_error
{
	ONLY_CHECK,
	SH,
	PROMPT
}	t_tracking_error;

#endif