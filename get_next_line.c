/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:34 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/17 19:33:10 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *stash)
{
	int		read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(stash), NULL);
		buffer[read_bytes] = '\0';
		if (!stash)
		{
			stash = (char *)malloc(1 * (sizeof(char)));
			if (!stash)
				return (NULL);
			stash[0] = '\0';
		}
		stash = ft_strjoin_alt(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*ft_restrict_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_renew_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	new = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!new)
		return (free(stash), NULL);
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_restrict_line(stash);
	stash = ft_renew_stash(stash);
	return (line);
}
