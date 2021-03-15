#include "holberton.h"

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;

	return (i);
}

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; i < n && *(src + i) != 0; i++)
		*(dest + i) = *(src + i);
	for (; i < n; i++)
		*(dest + i) = 0;

	return (dest);
}

int fillnewbuff(char *buff, char *src, int to_write, int buff_size, int *b_cnt)
{
	int used_buff;

	if (buff_size >= to_write)
	{
		_strncpy(buff, src, to_write);
		*(b_cnt) = to_write;
		return (1);
	}

	write(1, src, buff_size);
	used_buff = fillnewbuff(buff, src + buff_size, to_write - buff_size,
				buff_size, b_cnt);
	return (used_buff + 1);
}

char *_itoa(int num, char *nums)
{
	int i = 10, negative = 0, digit;

	nums[11] = 0;
	if (num < 0)
	{
		negative = 1;
	}
	do {
		digit = num % 10;
		digit = (digit < 0) ? -digit : digit;
		nums[i] = digit + '0';
		num = num / 10;
		i--;
	} while (num);
	if (negative)
	{
		nums[i] = '-';
		return (nums + i);
	}
	return (nums + i + 1);
}

char *convert_non_printable_characters(char *s)
{
	int len, i;
	char *s_converted;

	len = _strlen(s);
	s_converted = malloc(sizeof(*s_converted) * len);
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 32 && s[i] <= 126)
			s_converted[i] = s[i];
		else
		{
			
		}
	}
}


/**
 * _realloc - eallocates a memory block using malloc and free
 * The contents will be copied to the newly allocated space,
 * in the range from the start of ptr up to the minimum of
 * the old and new sizes
 * Description: If new_size > old_size, the “added” memory
 * should not be initialized.
 * If new_size == old_size do not do anything and return ptr
 * If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 * If new_size is equal to zero, and ptr is not NULL, then the
 * call is equivalent to free(ptr). Return NULL
 * @ptr: ointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 * Return: pointer to allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr, *temp_ptr;
	unsigned int i;

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	temp_ptr = (char *) ptr;
	for (i = 0; i < new_size; i++)
	{
		if (i >= old_size)
			break;
		*(nptr + i) = *(temp_ptr + i);
	}
	free(ptr);
	return ((void *)nptr);
}
