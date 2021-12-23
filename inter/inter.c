#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int string_check1(char *str, char c, int index)
{
	int i;
	
	i = 0;
	while(i < index)
	{
		if(str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(argc == 3)
	{
		while(argv[1][j])
		{
			i = 0;
			while(argv[2][i])
			{	
				if(string_check1(argv[1], argv[2][i], j) == 0)
				{
					if (argv[1][j] == argv[2][i])
					{
						ft_putchar(argv[2][i]);
						break;
					}
					
				}
				
				i++;
			}
			j++;
		}
	}
	ft_putchar('\n');
	return (0);
}
