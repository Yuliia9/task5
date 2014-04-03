/*
*@file		functions.cpp
*@brief		implements functions for working with C string defined in file my_string.h 
*/
#include "stdafx.h"
#include "my_string.h"
#include <stdlib.h>
#include <string.h>



unsigned int my_strprintf(const char* str)
{
	if (str == NULL)
	{
		puts("printf(): Parameter  is a null pointer.");
		return 0;
	}
	const char* temp = str;
	while (*temp != STREND)
	{
		++temp;
	}
	puts(temp);
	return 1;
}

/********************************************************************************/
size_t my_strlen(const char* str)
{
	size_t len = 0;
	if (str == NULL)
	{
		puts("strlen(): Parameter  is a null pointer.");
		return ERROR;
	}
	while (str[len] != STREND)
	{
		++len;
	}
	return len;
}

/********************************************************************************/
char* my_strcpy(char* destination, const char* source) 
{
	unsigned int len;
	if (destination == NULL || source == NULL)
	{
		puts("strcpy(): Destination or source pointer is a null pointer.");
		return NULL;
	}
	len = my_strlen(source);
	memcpy(destination, source, len);
	destination[len] = STREND;
	return destination;
}

/********************************************************************************/
char* my_strncpy_s(char* destination, const char* source, size_t num)
{
	unsigned int len;
	if (destination == NULL || source == NULL)
	{
		puts("strncpy_s(): Destination or source pointer is a null pointer.");
		return NULL;
	}
	len = my_strlen(source);
	if (len < num)
	{
		num = len;
	}
	memcpy(destination, source, num);
	destination[num] = STREND;
	return destination;
}

/********************************************************************************/
char* my_strncpy(char* destination, const char* source, size_t num)
{
	unsigned int len;
	if (destination == NULL || source == NULL)
	{
		puts("strncpy(): Destination or source pointer is a null pointer.");
		return NULL;
	}
	len = my_strlen(source);
	if (len < num)
	{
		memcpy(destination, source, num + 1);
		while (num - len)
		{
			destination[len] = 0;
			++len;
		}
	}
	else
	{
		memcpy(destination, source, num);
	}
	return destination;
}

/********************************************************************************/
char* my_strcat(char* destination, const char* source) 
{
	unsigned int len_d, len_s;
	if (destination == NULL || source == NULL)
	{
		puts("strcat(): Destination or source pointer is a null pointer.");
		return NULL;
	}
	len_d = my_strlen(destination);
	len_s = my_strlen(source);
	memcpy(destination + len_d, source, len_s);
	len_d += len_s;
	destination[len_d] = STREND;
	return destination;
}

/*******************************************************************************/
char* my_strncat(char* destination, const char* source, size_t num)
{
	unsigned int len_d, len_s;
	if (destination == NULL || source == NULL)
	{
		puts("strncat(): Destination or source pointer is a null pointer.");
		return NULL;
	}
	len_d = my_strlen(destination);
	len_s = my_strlen(source);
	if (len_s < num)
	{
		num = len_s;
	}
	memcpy(destination + len_d, source, num);
	len_d += num;
	destination[len_d] = STREND;
	return destination;
}

/******************************************************************************/
int my_strcmp(const char* str1, const char* str2)
{
	unsigned int len1, len2;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strcmp(): One of parameters is a null pointer.");
		return NULL;
	}
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	if (len1 > len2)
	{
		return 1;
	}
	else if (len1 < len2)
	{
		return -1;
	}
	else
	{
		return memcmp(str1, str2, len1);
	}
}

/******************************************************************************/
int my_strncmp(const char* str1, const char* str2, size_t num)
{
	unsigned int len1, len2;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strncmp(): One of parameters is null pointer.");
		return NULL;
	}
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	if (len1 < num || len2 < num)
	{
		if (len1 > len2)
		{
			return 1;
		}
		else if (len2 > len1)
		{
			return -1;
		}
		else
		{
			return memcmp(str1, str2, num);
		}
	}
	else
	{
		return memcmp(str1, str2, num);
	}
}

/******************************************************************************/
char* my_strchr(const char* str, int character)
{
	if (str == NULL)
	{
		puts("strchr(): Parameter is a null pointer.");
		return NULL;
	}
	return (char*) memchr(str, character, my_strlen(str));
}

/*****************************************************************************/
char* my_strrchr(char* str, int character)
{
	unsigned int len;
	if (str == NULL)
	{
		puts("strrchr(): Parameter is a null pointer.");
		return NULL;
	}
	len = my_strlen(str);
	while (len)
	{
		if (str[len-1] == character)
		{
			return (str + len - 1);
		}
		else
		{
			--len;
		}
	}
	return NULL;
}

/*****************************************************************************/
size_t my_strcspn(const char * str1, const char * str2)
{
	unsigned int len1, len2, i;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strcspn(): One of parameters is a null pointer.");
		return NULL;
	}
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	for (i = 0; i < len1; ++i)
	{
		if (memchr(str2, str1[i], len2) != NULL)
		{
			return i;
		}
	}
	return len1;
}

/*****************************************************************************/
size_t my_strspn(const char* str1, const char* str2)
{
	unsigned int len2, i;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strspn(): One of parameters is a null pointer.");
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i = 0; str1[i] != STREND; ++i)
	{
		if (memchr(str2, str1[i], len2) == NULL)
		{
			break;
		}
	}
	return i;
}

/****************************************************************************/
char* my_strpbrk(char* str1, const char* str2)
{
	unsigned int i, len2;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strpbkr(): One of the parameters is a null pointer.");
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i  = 0; str1[i] != STREND; ++i)
	{
		if ((char*) memchr(str2, str1[i], len2) != NULL)
		{
			return (str1 + i);
		}
	}
	return NULL;
}

/****************************************************************************/
char* my_strstr(char* str1, const char* str2)
{
	unsigned int i, len2;
	if (str1 == NULL || str2 == NULL)
	{
		puts("strstr(): One of the parameters is a null pointer.");
		return NULL;
	}
	len2 = my_strlen(str2);
	for (i = 0; str1[i] != STREND; ++i)
	{
		if (str1[i] == str2[0])
		{
			if (memcmp((str1 + i), str2, len2) == 0)
			{
				return (str1 + i);
			}
		}
	}
	return NULL;
}

/****************************************************************************/
char* my_strtok(char* str, const char* delimiters)
{
	static char* last = NULL;
	char* tokenbeg;
	char* tokenend;
	unsigned int i = 0;
	if (delimiters == NULL)
	{
		puts("strtok(): Delimiters cannot be a null pointer.");
		return NULL;
	}
	if (str[0] != STREND)
	{
		last = str;
	}
	if ((last[0] == STREND) && (str[0] == STREND))
	{
		return NULL;
	}
	tokenbeg = last;
	tokenend = my_strpbrk(tokenbeg, delimiters);
	if (tokenend == NULL)
	{
		last += my_strlen(last);
		return tokenbeg;
	}
	while ((tokenend - tokenbeg) <= 1)
	{
		tokenbeg = tokenend + 1;
		tokenend = my_strpbrk(tokenend + 1, delimiters);

	}
	*tokenend = STREND;
	last = tokenend + 1;
	return tokenbeg;
}