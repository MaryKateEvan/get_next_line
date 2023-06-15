/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:34 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/15 20:19:04 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
// I must check that it works as expected both when reading a file and when reading from standard input.

// the returned line should include the \n character (except for the end if it doesn't exist)

// I will compile with the call: -D BUFFER_SIZE=n. Example: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

// external functions that can be used: read, malloc, free

// syntax of read: 
// ssize_t read(int fd, void *buffer, size_t count);
// 	it returns one of: the number of bytes read on success, or
// 						0 if the end of the file or input source has been reached
// 						-1 if an error occurs

// For the bonus: multiple file descriptors

// MAIN IDEA/LOGIC
// ----------------
// 1. I'm reading BUFFER_SIZE bytes and saving them in the cumulative static variable `stash`
// 2. I'm retrieving/restricting from stash the "line context" (all the characters until '\n') and save it to `line`, which i return
// 3. I'm returning `line`
// 

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_read_line(int fd, char *stash)
{
	int		read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(stash, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		//printf("read_bytes is %d\n", read_bytes);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_alt(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_restrict_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if ((ft_length(str, '\0') % BUFFER_SIZE) != 0)
		line = (char *)malloc(ft_length(str, '\0') + 1);
	else
		line = (char *)malloc(ft_length(str, '\n') + 2);
	//line = (char *)malloc(ft_length(str, '\n') + 2);
	if (!line)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	printf("test_in_restrict_line\n");
	return (line);
}

char	*ft_renew_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	new = (char *)malloc((ft_length(stash, '\0') - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	while (stash[i] != '\0')
	{
		new[j] = stash[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(stash);
	//printf("test\n");
	return (new);
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
	stash = ft_renew_stash(stash);
	return (line);
}

// int    main(void)
// {
//     char    *line;
//     int        i;
//     int        fd1;
//     int        fd2;
//     int        fd3;
//     fd1 = open("test.txt", O_RDONLY);
//     fd2 = open("test2.txt", O_RDONLY);
//     fd3 = open("test3.txt", O_RDONLY);
//     i = 1;
//     while (i < 10)
//     {
//         line = get_next_line(fd1);
//         printf("line [%02d]: %s", i, line);
//         free(line);
//         // line = get_next_line(fd2);
//         // printf("line [%02d]: %s", i, line);
//         // free(line);
//         // line = get_next_line(fd3);
//         // printf("line [%02d]: %s", i, line);
//         // free(line);
//         i++;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }


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
