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


int main(void)
{
	char a[] = "abcd\x23";
	char b[10];
	my_strcpy(a, b);
	my_strprintf(b);
	return 0;
}

