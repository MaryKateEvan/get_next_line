/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:30 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/17 15:06:48 by mevangel         ###   ########.fr       */
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

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == (unsigned char)c)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

// size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
// {
// 	size_t	d;
// 	size_t	s;
// 	size_t	in_len;

// 	in_len = ft_strlen(dst);
// 	if (in_len > dstsize || dstsize == 0)
// 		return (dstsize + ft_strlen(src));
// 	d = ft_strlen(dst);
// 	s = 0;
// 	while (d < (dstsize - 1) && src[s])
// 	{
// 		dst[d] = src[s];
// 		d++;
// 		s++;
// 	}
// 	dst[d] = '\0';
// 	return (in_len + ft_strlen(src));
// }

char	*ft_strjoin_alt(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * (sizeof(char)));
		if (!s1)
			return (free(s1), NULL);
		s1[0] = '\0'; 
	}
	if (!s2)
		return (s1);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (free(s1), free(joined), NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	while (s2[++j] != '\0')
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}
