/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:41 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:19:28 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stackdelone(t_stack *stack, void (*del)(void *))
{
	if (!stack || !del)
		return ;
	del(stack->content);
	free(stack);
}
