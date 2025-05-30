/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:19:57 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:21:21 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack	*ft_stackmap(t_stack *stack, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new_stack;
	t_stack	*new_elem;
	void	*content;

	if (!stack || !f)
		return (NULL);
	new_stack = NULL;
	while (stack)
	{
		content = f(stack->content);
		new_elem = ft_stacknew(content);
		if (!new_elem)
		{
			ft_stackclear(&new_stack, del);
			del(content);
			return (NULL);
		}
		ft_stackadd_back(&new_stack, new_elem);
		stack = stack->next;
	}
	return (new_stack);
}
