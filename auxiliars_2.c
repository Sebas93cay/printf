#include "holberton.h"

/**
 * place_x - write the first number in the argument list
 * in format HEX format lowercase
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * @flags: structure with flags activated to have into account
 * Return: return number of new buffers needed to print string
 */
int place_x(va_list args, char *buff, int *b_cnt,
	    flag *flags)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len;
	char num_holder[10], *num_s;

	num_holder[10] = 0;
	if (flags[2].value == 1)
		new_buffs += putInBuffer(buff, b_cnt, "0x", 2);
	num_s = base_convert(num_holder, 10, num, 16, 87);
	len = _strlen(num_s);

	new_buffs += putInBuffer(buff, b_cnt, num_s, len);
	return (new_buffs);
}

/**
 * place_X - write the first number in the argument list
 * in format HEX format uppercase
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * @flags: structure with flags activated to have into account
 * Return: return number of new buffers needed to print string
 */

int place_X(va_list args, char *buff, int *b_cnt,
	    flag *flags)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[10], *num_s;

	num_holder[10] = 0;
	if (flags[2].value == 1)
		new_buffs += putInBuffer(buff, b_cnt, "0x", 2);

	num_s = base_convert(num_holder, 10, num, 16, 55);
	len = _strlen(num_s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, num_s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, num_s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, num_s + available,
							len - available,
							BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}

/**
 * place_o - write the first number in the argument list
 * in format OCTAL format
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * @flags: structure with flags activated to have into account
 * Return: return number of new buffers needed to print string
 */

int place_o(va_list args, char *buff, int *b_cnt,
	    __attribute__ ((unused)) flag *flags)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[13], *num_s;

	num_holder[13] = 0;

	num_s = base_convert(num_holder, 13, num, 8, 0);
	len = _strlen(num_s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, num_s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, num_s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, num_s + available,
							len - available,
							BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}


/**
 * place_u - write the first number in the argument list
 * in format UNSIGNED format
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * @flags: structure with flags activated to have into account
 * Return: return number of new buffers needed to print string
 */
int place_u(va_list args, char *buff, int *b_cnt,
	    __attribute__ ((unused)) flag *flags)
{

	int num = va_arg(args, int);
	unsigned int number;
	int new_buffs = 0, len, available;
	char num_holder[12], *num_s;

	if (num < 0)
		number = UINT_MAX + (num + 1);
	else
		number = num;

	num_s = _itoa('+', number, num_holder);
	len = _strlen(num_s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, num_s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, num_s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, num_s + available, len - available,
					BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}

int place_p(va_list args, char *buff, int *b_cnt,
	    __attribute__ ((unused)) flag *flags)
{
	char *s;
	void *ptr = va_arg(args, void*);
	int new_buffs = 0, len;
	char snull[] = "(nil)";
	char buffer[20];

	if (!ptr)
		s = snull;
	else
		s = getAddress_p(ptr, buffer, 20);

	len = _strlen(s);

	new_buffs = putInBuffer(buff, b_cnt, s, len);

	return (new_buffs);
}
