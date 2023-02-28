#pragma once

namespace hash
{
    template <typename T>
    class tHashing
    {
    public:
        tHashing(unsigned size) : _size(size)
        {
            _pool = new T[_size];
        }
    private:
        T* _pool;
        const unsigned _size;
    };

    class cHashing
    {
    public:
        cHashing(unsigned size) : _table_size(size)
        {
            _pool = new int[size];
        }

    private:
        int* _pool;
        const unsigned _table_size;
    };
}