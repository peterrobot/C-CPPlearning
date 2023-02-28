#include <iostream>
#define DEBUG
#include <cmath>

using namespace std;

class Point
{
private:
    int _x;
    int _y;
public:
    explicit Point(int x, int y) : _x(x), _y(y)
    {
        #ifdef DEBUG
        std::cout << "Initializer is called\n";
        #endif
    }
    Point(const Point& P)
    {
        #ifdef DEBUG
        std::cout << "Copy constructor is called\n";
        #endif
        _x = P._x * 2;
        _y = P._y * 2;
    }
    void Print()
    {
        std::cout << _x << "," << _y << std::endl;
    }
};

void func(Point p)
{
    p.Print();
}

constexpr struct funcObj{
    template <typename _Arg,typename _Ret = _Arg >
    _Ret operator()(_Arg &arg1, _Arg &arg2) const {
        return arg1+arg2;
    }
}funcAdd{};

template <typename U>
struct personal_cast_fn{
    template <typename T>
    U operator()(T &&arg) const
    {
        return static_cast<U>(arg);
    }
};

template <typename T>
constexpr personal_cast_fn<T> personal_cast{};

int main()
{
    int a = 1, b = 2;
    short s = 10;
    cout << funcAdd(a,b) << endl << &funcAdd << endl << personal_cast<int>(s);
    return 0;   
}