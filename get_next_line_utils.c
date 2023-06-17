/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/17 18:29:48 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_alt(char *stash, char *buffer)
{
	char	*joined;
	int		i;
	int		j;

	joined = (char *)malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!joined)
		return (NULL);
	i = -1;
	j = -1;
	while (stash[++i] != '\0')
		joined[i] = stash[i];
	while (buffer[++j] != '\0')
		joined[i + j] = buffer[j];
	joined[i + j] = '\0';
	free(stash);
	return (joined);
}
