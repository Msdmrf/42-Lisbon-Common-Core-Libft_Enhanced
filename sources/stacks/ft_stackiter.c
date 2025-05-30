/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:19:33 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:20:47 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stackiter(t_stack *stack, void (*f)(void *))
{
	if (!f)
		return ;
	while (stack)
	{
		f(stack->content);
		stack = stack->next;
	}
}
