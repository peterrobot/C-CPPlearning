#pragma once
#include <iostream>

using std::cout;
using std::endl;

class test1
{
public:
	test1(int in = 0) : content(in)
	{ cout << "The local of content: " << &content << endl; }

	test1(test1& other) : content(other.content) {};

	void log() const;
private:
	int content;
};
