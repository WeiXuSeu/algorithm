/*
Compare string: 
= 0
> 1
< -1
*/

#include<stdio.h>
#include<stdlib.h>

#define EQUAL 0
#define BIG   1
#define SMALL -1

int StringCompare(char *str1, char *str2)
{
	if(NULL == str1 && NULL == str2)
		return EQUAL;
	if(NULL == str1)
		return SMALL;
	if(NULL == str2)
		return BIG;
	int index=0;
	while('\0'!=str1[index]&&'\0'!=str2[index])
	{
		if(str1[index]>str2[index])
			return BIG;
		else if(str1[index]<str2[index])
			return SMALL;
		else
			index++;
	}
	if('\0'==str1[index]&&'\0'==str2[index])
		return EQUAL;
	if('\0'==str1[index])
		return SMALL;
	if('\0'==str2[index])
		return BIG;
}

void testStringEqual()
{
	char str1[]="abc";
	char str2[]="abc";
	int result = 0;
	result = StringCompare(str1,str2);
	
	char* str3=NULL;
	char* str4=NULL;
	result = StringCompare(str3,str4);
}

void testStringBig()
{
	char str1[] = "abcd";
	char str2[] = "abc";
	int result = 0;
	result = StringCompare(str1,str2);

	char str3[] = "abc";
	char str4[] = "abb";
	result = StringCompare(str3,str4);

	char str5[] = "a";
	char* str6 = NULL;
	result = StringCompare(str5,str6);
}

void testStringSmall()
{
	char str1[] = "abc";
	char str2[] = "abcd";
	int result = 0;
	result = StringCompare(str1,str2);

	char str3[] = "abb";
	char str4[] = "abc";
	result = StringCompare(str3,str4);

	char* str5 = NULL;
	char str6[] = "a";
	result = StringCompare(str5,str6);
}

int main()
{
	testStringEqual();
	testStringBig();
	testStringSmall();
}

