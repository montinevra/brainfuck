#include "brainfuck.h"
#include <stdio.h>

void	brainfuck(int fd)
{
	char			*ptr;
	char			buffer[BUF_SIZE + 1];
	unsigned int	ret;
	unsigned int	i;
	unsigned int	nested;

	ptr = ft_memalloc(30000);
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		i = 0;
		while (buffer[i] && i < ret)
		{
			if (buffer[i] == '>')
				++ptr;
			else if (buffer[i] == '<')
				--ptr;
			else if (buffer[i] == '+')
				++*ptr;
			else if (buffer[i] == '-')
				--*ptr;
			else if (buffer[i] == '.')
				ft_putchar(*ptr);
			else if (buffer[i] == ',')
				read(0, ptr, 1);
			else if (buffer[i] == '[')
			{
				if (!*ptr)
				{
					nested = 0;
					while (buffer[++i] != ']' || nested)
					{
						if (buffer[i] == '[')
							nested++;
						else if (buffer[i] == ']')
							nested--;
					}
				}
			}
			else if (buffer[i] == ']')
			{
				if (*ptr)
				{
					nested = 0;
					while (buffer[--i] != '[' || nested)
					{
						if (buffer[i] == ']')
							nested++;
						else if (buffer[i] == '[')
							nested--;
					}
				}
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		brainfuck(0);
	else
		while (--argc)
		{
			fd = open(*(++argv), O_RDONLY);
			if (fd > 0)
			{
				brainfuck(fd);
				close(fd);
			}
		}
	return (0);
}
