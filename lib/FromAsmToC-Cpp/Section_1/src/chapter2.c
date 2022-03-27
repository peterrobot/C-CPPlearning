#include "stdio.h"
#include "chapter2.h"

void my_function_2(void)
{
    int a = 0, i = 0;
    char c = 'a';
    scanf_s("%d,%c", &i, &c,1);
    switch(c)
    {
        case 0:
            i = 0;
            break;
        case 'a':
            i = 'a';
            break;
        default:
            i = -1;
    }
    while(c > 0)
    {
        --c;
    }
    puts("Finished");
}