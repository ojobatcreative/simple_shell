#include "oboshell.h"

/**
 *atoi_obo - converts a string to an integer
 *@str: string is inputed here
 *
 *Return: integer number
*/

int atoi_obo(char *str)
{
	char tc;
	unsigned int ti, n = 0, tj = strlen_obo(str) - 1, null = -1;
	int flag = 0, sign = 1;

	for (ti = 0; ti <= tj; ti++)
	{
		tc = str[ti];
		if (tc == '-')
			sign *= -1;
		if (tc >= 48 && tc <= 57)
		{
			n = n * 10 + (tc - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(tc >= 48 && tc <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (tj == null)
		return (0);
	return (n);
}
