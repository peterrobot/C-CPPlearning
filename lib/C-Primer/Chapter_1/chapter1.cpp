#include "chapter1.h"

void test1::log() const
{
	cout << "LOG: The local of content: " << &this->content << endl;
}
