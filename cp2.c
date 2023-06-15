/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/15 20:03:50 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_length(char *str, char end)
{
	size_t	i;

	i = 0;
	while (str[i] != end)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_alt(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * (sizeof(char)));
		s1[0] = '\0'; 
	}
	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(ft_length(s1, '\0') + ft_length(s2, '\0') + 1);
	if (!joined)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	//if (s1)
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	while (s2[++j] != '\0')
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	//free(s1);
	return (joined);
}
