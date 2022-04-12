#include "basic_variable.h"
#include <iostream>
#include <type_traits>

void show_size()
{
    using std::cout;
}

void test_of_convert()
{
    bool b = 42;
    int i = b;
    i = 3.14;
    double pi = i;
    float p = 3.14;
    p = 3.14;
    p = 3.14f;
    pi = 3.14f;
    pi = 3.14;
    unsigned char uc = -256;
    signed char sc = -256;
    unsigned int un = 256;
    signed int sn = -256;
    uc = un;
    sc = sn;
}

extern "C" void test_of_convert_C(void)
{
    bool b = 42;
    int i = b;
    i = 3.14;
    double pi = i;
    float p = 3.14;
    p = 3.14;
    p = 3.14f;
    pi = 3.14f;
    pi = 3.14;
    unsigned char uc = -256;
    signed char sc = -256;
    unsigned int un = 256;
    signed int sn = -256;
    uc = un;
    sc = sn;
}

void test_of_as_init()
{
	// internal type
    int i = 1, j = i;
    int k = i;
    j = i = 2;
    
    // A user defined structure
	struct test_struct
	{
        int i;
        int j;
        char c1;
        char c2;
	};
    test_struct ts;     // none-initialized variable
    ts.i = i;           // direct assign element
    ts.j = j;
    ts = { 1,2,'a','b'};    // list temp assign
    test_struct ts0{ 3,4,'c','d'}, ts1 = {5,6,'e','f'};
	// list initialization in two written style
    ts = ts0;           // assigned structure

    // A user defined class
    class test_class
    {
    private:                
        int _i = 0;
        int _j = 0;
        char _c1 = '\0';
        char _c2 = '\0';
    public:
        test_class(int i, int j, char c1, char c2) : _i(i), _j(j), _c1(c1), _c2(c2){}
        test_class(const test_class&) = default;
        test_class(test_class&&) = default;
        ~test_class() noexcept { std::cout << "test class deleted\n"; }
        test_class& operator=(const test_class& t) = default;
        test_class& operator=(test_class&& t) noexcept
    	{ _i = t._i; _j = t._j; _c1 = t._c1; _c2 = t._c2; return *this; }
    };
    test_class tc{ 1,2,'a','b' };       // direct_list_initialization
    test_class tc0 = { 1,2,'a','b' };   // copy_list_initialization
    tc = tc0;   // copy assignment
    tc0 = { 3,4,'c','d' };  // move assignment
}

template <typename T>
void check_class()
{
    std::cout << "Type name " << typeid(T) << std::endl
        << "Is POD: " << std::is_pod_v<T>() << std::endl
		<< "Is trivial type" << std::is_pod_v<T>()
		<< "./tIs trivial constructor" << std::is_trivially_constructible_v<T>() << std::endl;
}

void test_of_init_list()
{
    /*
	**	Requirement of trivial class
	**	Pod - plain old data
	**	No reference member
	**	No member with user-defined constructor
	**	No member with user-defined destructor
	*/

    // An POD example
	// Also it is an aggregate type
	class AggregateExample
	{
	public:
        int a;
        int b;
	};
    check_class<AggregateExample>();
}

void test_of_variables()
{
    test_of_convert();
    test_of_convert_C();
}