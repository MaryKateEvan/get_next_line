/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:34 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/12 19:08:57 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
I must check that it works as expected both when reading a file and when reading from standard input.

the returned line should include the \n character (except for the end if it doesn't exist)

I will compile with the call: -D BUFFER_SIZE=n. Example: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

external functions that can be used: read, malloc, free

syntax of read: 
ssize_t read(int fd, void *buffer, size_t count);
	it returns one of: the number of bytes read on success, or
						0 if the end of the file or input source has been reached
						-1 if an error occurs

For the bonus: multiple file descriptors

MAIN IDEA/LOGIC
----------------
1. I'm reading BUFFER_SIZE bytes and saving them in the cumulative static variable `stash`
2. I'm retrieving/restricting from stash the "line context" (all the characters until '\n') and save it to `line`, which i return
3. I'm returning `line`

*/

#include <unistd.h> //for the read function 
#include "get_next_line.h"

size_t	ft_length(char *str, char end)
{
	size_t	i;

	i = 0;
	while (str[i] != end)
		i++;
	return (i);
}

char	*ft_strjoin_alt(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1 || !s2)
		return(NULL);
	joined = (char *)malloc(ft_length(s1, '\0') + ft_length(s2, '\0') + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i++] != '\0')
		joined[i] = s1[i];
	while (s2[j++] != '\0')
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	free(s1);
	free(s2);
	// ft_strlcpy(joined, cp_s1, ft_strlen(cp_s1) + 1);
	// ft_strlcat(joined, s2, join_len);
	return (joined);
}

char	ft_read_line(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	read_bytes = 1;
	if (!stash) //to initialize stash for the first call since it's null initially
	{
		stash = (char *)malloc(1 * (sizeof(char)));
		stash[0] = '\0';
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes = -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_alt(stash, buffer);
	}
	//free(buffer);
	return (stash);
}

char	*ft_restrict_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(ft_length(str, '\n') + 2);
	if (!line)
		return(NULL);
	while (str[i] && str[i] != '\n')
		line[i++] = str[i++];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*get_next_line(int fd)
{
	static char	*stash; //it is initialized to null if I don't assign anything
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_restrict_line(stash);
	return (line);
} 



/*
what my get_next_line must return:
- a string with the full line ending in a line break when there is one. Or
- NULL, if an error occurs, or there's nothing more to read.
*/

// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     long max_fd = sysconf(_SC_OPEN_MAX);
//     printf("Maximum file descriptor value: %ld\n", max_fd);
//     return 0;
// }
