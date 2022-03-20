#include <stdio.h>
#include "chapter1.h"

void test_of_func(void)
{
	char c = 0;
	scanf_s("%c", &c, 1);
	printf_s("%s %c", "Hello World!", c);
}