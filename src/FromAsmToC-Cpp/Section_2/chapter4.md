# Core buffer and memory

## String modification

### String structure

The common use of string among c programmer is actually not really safe. The usage as below can easily cause buffer overflow.

```c++
char *str = {"Ansi style string"};
wchar_t *wstr = {L"Unicode style string"};
size_t len = strlen(str);
size_t wlen = wcslen(wstr);
printf("%s,%ls,%ull,%ull", str, wstr, len, wlen);
```

```c++
typedef struct _UNICODE_STRING{
    USHORT  Length;
    USHORT  MaximumLength;
    PWSTR   Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _ANSI_STRING{
    USHORT  Length;
    USHORT  MaximumLength;
    PSTR    Buffer;
} ANSI_STRING, *PANSI_STRING;
```

### String initialization

From the definition of string structure above, it is important to highlight that the initialization of these strings are significantly different form the classic C strings.

```c++
// General initialization of C string
typedef char* STR;
STR str = "Hello";

/*
    Although there are "Length" and "MaximumLength" elements exist in UNICODE_STRING structure, but the Buffer is not initialized by default.
*/
UNICODE_STRING wstr;
// Incorrect string initialization
wcscpy(wstr.Buffer, L"Hello");  // wstr.Buffer is an uninitialized pointer(NULL/0).
wstr.Length = wstr.MaximumLength = wcslen(L"Hello"); 

// Correct string initialization
wstr.Buffer = L"Hello";
wstr.Length = wstr.MaximumLength = wcslen(L"Hello");
// Actually, while the string no longer needs to end with '\0', the 'Length' can be "wcslen(L"Hello")-sizeof(L'\0');".

// Another correct form
UNICODE_STRING wstr = {
    sizeof(L"Hello") - sizeof((L"Hello")[0]),
    sizeof(L"Hello"),
    L"Hello"
}

// With marco
#include "ntdef.h"
UNICODE_STRING wstr = RTL_CONSTANT_STRING(L"Hello")
```

### String Copy

## Memory and chain
