#define _X86_
#include "chapter4.h"
#include "string.h"
#include "stdio.h"
#include "ntdef.h"

void use_of_string(void)
{
	// Unsafe use of string. Could easily case buffer overflow.
	char* str = { "Ansi style string" };
	wchar_t* wstr = { L"Unicode style string" };
	size_t len = strlen(str);
	size_t wlen = wcslen(wstr);
	printf("%s %llu",str,len);
	wprintf(L"%ls, %llu", wstr, wlen);
    UNICODE_STRING k_rtl_str = RTL_CONSTANT_STRING(L"Hello World");
}

void my_function_4(void)
{
    use_of_string();
}