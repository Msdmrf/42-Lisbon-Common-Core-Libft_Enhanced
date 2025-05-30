/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:19:10 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:19:59 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stackclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*temp;
	t_stack	*next;

	if (!stack || !del)
		return ;
	temp = *stack;
	while (temp)
	{
		next = temp->next;
		ft_stackdelone(temp, del);
		temp = next;
	}
	*stack = NULL;
}
