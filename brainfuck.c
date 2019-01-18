#include "brainfuck.h"
#define BUF_SIZE 30000

void	brainfuck(int fd)
{
	char	array[30000] = {0};
	char	*ptr;
	char	buffer[BUF_SIZE + 1];
	int		ret;
	int		i;
	int		nested;

	ptr = array;
	while ((ret = read(fd, buffer, 400)))
	{
		i = 0;
		while (buffer[i] && i < ret)
		{
			switch (buffer[i])
			{
				case '>':
					++ptr;
					break;
				case '<':
					--ptr;
					break;
				case '+':
					++*ptr;
					break;
				case '-':
					--*ptr;
					break;
				case '.':
					putchar(*ptr);
					break;
				case ',':
					read(0, ptr, 1);
					break;
				case '[':
					if (!*ptr)
					{
						nested = 0;
						while (buffer[++i] != ']' || nested)
						{
							if (buffer[i] == '[')
							{
								nested++;
							}
							else if (buffer[i] == ']')
							{
								nested--;
							}
						}
					}
					break;
				case ']':
					if (*ptr)
					{
						nested = 0;
						while (buffer[--i] != '[' || nested)
						{
							if (buffer[i] == ']')
							{
								nested++;
							}
							else if (buffer[i] == '[')
							{
								nested--;
							}
						}
					}
					break;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
	{
		brainfuck(0);
	}
	else
	{
		while (--argc)
		{
			fd = open(*(++argv), O_RDONLY);
			if (fd > 0)
			{
				brainfuck(fd);
				close(fd);
			}
		}
	}
	return (0);
}
