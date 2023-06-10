/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:34 by mevangel          #+#    #+#             */
/*   Updated: 2023/06/10 20:02:14 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
I must check that it works as expected both when reading a file and when reading from standard input.

the returned line should include the \n character (except for the end if it doesn't exist)

I will compile with thet call: -D BUFFER_SIZE=n. Example: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

external functions that can be used: read, malloc, free

syntax of read: 
ssize_t read(int fd, void *buffer, size_t count);
	it returns one of: the number of bytes read on success, or
						0 if the end of the file or input source has been reached
						-1 if an error occurs

For the bonus: multiple file descriptors
*/

#include <unistd.h> //for the read function
#include "get_next_line.h"



char	*get_next_line(int fd)
{
	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}

/*
what my get_next_line must return:
- a string with the full line ending in a line break when there is one. Or
- NULL, if an error occurs, or there's nothing more to read.
*/