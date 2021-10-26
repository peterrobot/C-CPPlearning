#include "chapter2.h"

inline bool IsOdd(long int X)
{
    return X & 1;
}

long int Pow(long int X, unsigned int N)
{
    if (N == 0)
        return 1;
    if (N == 1)
        return X;
    if (IsOdd(N))
        return Pow(X * X, N / 2) * X;
    else
        return Pow(X * X, N / 2);
}