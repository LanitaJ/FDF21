/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:33:11 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/19 21:54:28 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size + 1 < size)
		return (NULL);
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	else
		return (ft_memset(mem, 0, size));
}
