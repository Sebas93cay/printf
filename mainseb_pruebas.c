#include "holberton.h"

int main(void)
{
	int len = 0, len2 = 0, i = 0;
	/* char *s1 = "B", *s2 = "C"; */
	/* char *format = "A%s%s%%%c%s%s%s\n"; */
	char largo[2000];

	for (i = 0; i < 1025; i++)
	{
		largo[i] = 'r';
	}
	largo[i] = 0;

	len2 = printf("%s\n", largo);
	len = _printf("%s\n", largo);
	printf("len = %d | len2 = %i\n", len, len2);
	return (0);
}
