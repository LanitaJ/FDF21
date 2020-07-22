/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:20:38 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/20 18:19:57 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_countword(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char		*ft_addstr(char const *s, int len)
{
	char	*str;
	char	*start;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str || !s)
		return (NULL);
	start = str;
	while (len--)
	{
		*str = *s;
		s++;
		str++;
	}
	*str = '\0';
	return (start);
}

static void		ft_word(char **out, const char *s, char c)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			out[i] = ft_addstr(s - len, len);
			if (out[i] == NULL)
				ft_freestrarr(out, i);
			i++;
		}
		if (*s)
			s++;
	}
	out[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	size_t	cw;

	cw = ft_countword(s, c);
	out = (char**)malloc(sizeof(char*) * cw + 1);
	if (!s || !c || !out)
	{
		free(out);
		return (NULL);
	}
	if (cw == 0)
	{
		out[0] = NULL;
		return (out);
	}
	ft_word(out, s, c);
	return (out);
}
