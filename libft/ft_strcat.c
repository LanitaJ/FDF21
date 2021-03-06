/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:53:07 by ljerk             #+#    #+#             */
/*   Updated: 2019/09/09 22:12:58 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*start;

	start = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	return (start);
}
