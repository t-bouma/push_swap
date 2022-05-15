/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:22:33 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/15 17:55:05 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	rotate(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*last;
	int		len;

	temp = *list;
	len = ft_node_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	last = ft_last_node(list);
	*list = (*list)->n;
	(*list)->p = NULL;
	last->n = temp;
	temp->p = last;
	temp->n = NULL;
	if (op)
		print_operation(op);
}

void	rotate_rr(t_lists_a_b *lists)
{
	rotate(&lists->a, NULL);
	rotate(&lists->b, NULL);
	print_operation(RR);
}

// seg fault in r _rotate, rotate gaat goed
void	r_rotate(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*last;
	int		len;

	len = ft_node_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	last = ft_last_node(list);
	last->p->n = NULL;
	last->p = NULL;
	temp = *list;
	*list = last;
	(*list)->n = temp;
	temp->p = *list;
	if (op)
		print_operation(op);
}

void	r_rotate_rr(t_lists_a_b *lists)
{
	r_rotate(&lists->a, NULL);
	r_rotate(&lists->b, NULL);
	print_operation(RRR);
}

	// printf("test\n");
	// printf("test\n");