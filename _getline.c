#include shell.h

/**
 * get_line - stores into malloced buffer the user's command into shell
 * @str: buffer
 * Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* read while there's stdin greater than buffsize; -1 to add a ' ' */
	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1) /* check if read errored */
			return (-1);

		buff[i] = ' '; /* terminate buff with  to use with _strcat */

		n = 0; /* last loop if 
 is found in the stdin read */
		while (buff[n] != ' ')
		{
			if (buff[n] == '
')
				t2 = 1;
			n++;
		}

		/* copy what's read to buff into get_line's buffer */
		if (t == 0) /* malloc the first time */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else /* _realloc via _strcat with each loop */
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
