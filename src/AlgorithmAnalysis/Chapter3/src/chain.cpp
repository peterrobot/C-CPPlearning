#include "chain.h"

using namespace chain;

void testChain(int input)
{
    Chain_single<int>* ch = new Chain_single<int>;
    ch->Add(input);
    ch->PrintList();
    std::cout << "Has 10 " << ch->Find(10);
}