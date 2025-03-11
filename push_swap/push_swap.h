/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:41:19 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/10 14:49:49 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

void	push(t_stack **a, t_stack **b, int c);

void	reverse_rotate(t_stack **stack, int b);

void	rrrotate(t_stack **a, t_stack **b);

void	rotate(t_stack **stack, int b);

void	rrotate(t_stack **a, t_stack **b);

void	swap(t_stack **stack, int b);

void	sswap(t_stack **a, t_stack **b);

void	check_int(char *argv);

void	check_duplicate(t_stack *a, char *argv);
#endif
