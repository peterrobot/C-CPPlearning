#include "generic_algorithm.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>

// Answer for P337-Practice10.1
void CaptureIntToVector(std::istream &inStream, std::vector<int> &v, int key)
{
    int temp;
    while (inStream >> temp && temp != 0)
    {
        v.push_back(temp);
    }
    std::cout << std::count(begin(v),end(v),key);
}
// Answer for P337-Practice10.2
void ChaptureStringToVector(std::istream &inStream, std::vector<std::string> &v, std::string &key)
{
    std::string temp;
    while (inStream >> temp && temp != "end")
    {
        v.push_back(temp);
    }
    std::cout << std::count(begin(v),end(v),key);
}
// Answer for P339-Practice10.3
int AccumulateVectorInt(std::vector<int> &v)
{
    return std::accumulate(begin(v),end(v),0);
}
// Answer for P342-Practice10.6
void SetSequenceZero(std::vector<int> &v)
{
    std::fill_n(v.begin(),v.size(),0);
}
//

void PrintVectorInt(std::vector<int> &vec)
{
    for (auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;
}

void PrintVectorInt(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    while(begin != end)
    {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

void generic_algorithm_test()
{
    using namespace std;
    vector<int> vecint1;
    //for(int i = 0; i < 10; i++) vecint1.push_back(rand()%100);
    vector<int> vecint2 = {50,30,45,8,6,8,5,5,30,50,50,50,10,13,9,6,2};
    //PrintVectorInt(vecint1);
    //sort(vecint1.begin(),vecint1.end());
    //PrintVectorInt(vecint1);
    PrintVectorInt(vecint2);
    sort(vecint2.begin(),vecint2.end());
    auto end_unique = unique(vecint2.begin(), vecint2.end());
    PrintVectorInt(vecint2);
    PrintVectorInt(end_unique, vecint2.cend());
    vecint2.erase(end_unique,vecint2.end());
    PrintVectorInt(vecint2);
}