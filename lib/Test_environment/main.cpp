#include <iostream>
#define DEBUG
#include <cmath>

using namespace std;

class point
{
private:
    int _x;
    int _y;
public:
    explicit point(const int x,const int y) : _x(x), _y(y)
    {
        #ifdef DEBUG
        std::cout << "Initializer is called\n";
        #endif
    }
    point(const point& p)
    {
        #ifdef DEBUG
        std::cout << "Copy constructor is called\n";
        #endif
        _x = p._x * 2;
        _y = p._y * 2;
    }
    point(point&&) = default;
    ~point() = default;
	point& operator=(const point&) = default;
    point& operator=(point&&) = default;

    void Print() const
    {
        std::cout << _x << "," << _y << std::endl;
    }
};

void func(point p)
{
    p.Print();
}

constexpr struct funcObj{
    template <typename Arg,typename Ret = Arg >
    Ret operator()(Arg &arg1, Arg &arg2) const {
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

int main() noexcept
{
    int a = 1, b = 2;
    short s = 10;
    cout << funcAdd(a,b) << endl << &funcAdd << endl << personal_cast<int>(s);
    return 0;   
}