#include "associative.h"
#include <map>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

// Answer for P376-Practice11.3
void Words_Count(std::istream& is)
{
    std::map<std::string, size_t> words_count;
    std::set<std::string> expections = {"damn", "shit"}; // No dirty words
    std::string temp;
    while(is >> temp)
    {
        if(expections.find(temp) == expections.cend()) ++words_count[temp];
    }
    for(auto &w : words_count)
    {
        std::cout << "The word " << w.first << " appears " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }
}

// Answer for P376-Practice11.4
void Words_Count_Expand(std::istream& is)
{
    std::map<std::string, size_t> words_count;
    std::string temp;
    while(is >> temp)
    {
        std::transform(begin(temp), end(temp), begin(temp), ::tolower); // Lower the characters
        temp.erase(std::remove_if(begin(temp), end(temp),static_cast<int(*)(int)>(&std::ispunct)), end(temp)); // Delete the punctuations
        ++words_count[temp];
    }
    for(auto &w : words_count)
    {
        std::cout << "The word " << w.first << " appears " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }
}

// Answer for P378-Practice11.7 && P379-Practice11.11
typedef std::map<std::string, std::vector<std::string>> family;
typedef std::map<std::string, std::vector<std::string>, bool (*)(std::string&, std::string&)> family_personal;
void Family_Add_Child(family &fa, std::string surname, std::string name)
{
    fa[surname].push_back(name);
}

// Answer for P381-Practice11.12
std::vector<std::pair<std::string, int>> StoreStringInt2VectorPair(std::vector<std::string> &vecstr, std::vector<int> &vecint)
{
    std::vector<std::pair<std::string, int>> pa;
    auto itStr = cbegin(vecstr);
    auto itInt = cbegin(vecint);
    size_t size = 0;
    while(itStr != cend(vecstr) && itInt != cend(vecint))
    {
        pa.push_back({*itStr++, *itInt++});
        size++;
    }
    printf_s("%llu %s is added.\n", size, size > 1 ? "elements" : "element");
    return pa;
}

// Answer for P381-Practice11.14
// Extension of Prac11.7
struct date
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
};
typedef std::map<std::string, std::vector<std::pair<std::string, date>>> family_birth;
void Family_Add_Child_Birth(family_birth &fa, std::string surname, std::string name, date birthday)
{
    fa[surname].push_back({surname, birthday});
}
// Answer for P391-Practice11.31
typedef std::string author;
typedef std::string book_name;
size_t Erase_Author(std::multimap<author, book_name> &set, author key)
{
    auto res = set.find(key);
    size_t count = 0;
    while(res != set.cend())
    {
        count++;
        set.erase(res);
        res = set.find(key);
    }
    return count;
}
//

bool compareInt(const int &a, const int &b)
{
    return a > b;
}

void associative_container_test()
{
    std::map<std::string, size_t> words_count; // As you see std::map template needs two type.
    std::set<std::string> word_list; // By comparison, std::set template needs only one type.
    std::set<int, decltype(compareInt)*> iset(compareInt); // Initialize a set with personal comparison function.
    std::set<int, bool (*)(const int&, const int&)> iset1(compareInt); // Proform the same as the former one without decltype().
}