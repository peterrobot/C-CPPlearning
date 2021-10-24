#include "sort.h"
#include <random>
#include <stdio.h>

void bubble_sort(int *array, const unsigned size)
{
    int temp;
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j < size - i - 1; j++)
        {
            if(array[j] < array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void random_init(int *array, const unsigned size)
{
    for(unsigned i = 0; i < size; i++) array[i] = rand();
}

void print(int *array, const unsigned size)
{
    for(unsigned i = 0; i < size; i++) printf("%d\n",array[i]);
}

void sort_test(const unsigned size)
{
    int *a = new int[size];
    random_init(a, size);
    print(a, size);
    printf("Star sorting!\n");
    bubble_sort(a, size);
    print(a, size);
}