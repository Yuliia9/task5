/*
* @file			task5.cpp
* @brief		Project includes developed string library

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include <string.h>
#include "my_string.h"
#include <stdlib.h>


int main(void)
{
	/*strcpy test*/
	char test[] = "123\x23";
	char* d = NULL;
	d = my_strcpy(d, test);
	puts("strcpy test");
	my_strprintf(d);
	puts("\n");

	/*strcat test*/
	char a[] = "123\x23";
	char* b = "ab\x23";
	b = my_strcat(b, a);
	puts("strcat test");
	my_strprintf(b);
	puts("\n");

	/*strncmp test*/
	char c[] = "173\x23";
	char* e = "123\x23";
	printf("strncmp test: %d\n", my_strncmp(c, e, 4));

	/*strchr test*/
	char* testchr1 = "rtbsrgas\x23";
	char testchr2 = 's';
	puts("strchr test: ");
	my_strprintf(my_strchr(testchr1, testchr2));
	puts("\n");

	/*strrchr test*/
	char* testrchr1 = "rtbsrgasuiousyu\x23";
	char testrchr2 = 's';
	puts("strrchr test");
	my_strprintf(my_strrchr(testrchr1, testrchr2));
	puts("\n");


	/*strcspn test*/
	char* cspn1 = "qwers\x23";
	char* cspn2 = "sui\x23";
	printf("strcspn test: %d\n", my_strcspn(cspn1, cspn2));

	/*strstr test*/
	char* strs1 = "qwers\x23";
	char* strs2 = "er\x23";
	puts("strstr test");
	my_strprintf(my_strstr(strs1, strs2));
	puts("\n");

	/*strtok test*/
	char str[] = "abcd de ab\x23";
	const char* delimiters = " \x23";
	char* token;
	puts("strtok test");
	token = my_strtok(str, delimiters);
	while (token != NULL)
	{
		my_strprintf(token);
		token = my_strtok(NULL, delimiters);
	}
	return 0;
}

