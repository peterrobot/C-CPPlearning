#pragma once
#include <map>
#include <string>

template <class T>
class Sing
{
protected:
    Sing(){};
public:
    Sing(Sing&) = delete;
    Sing& operator=(Sing&) = delete;

    static T& getInstance()
    {
        static T instance;
        return instance;
    }
};

class computer : public Sing<computer>
{
    friend Sing<computer>;
public:
    enum Token_value
    {
        NAME,NUMBER,END,
        PLUS='+', MINUS='-', MUL='*', DIV='/',
        PRINT=';',ASSIGN='=',LP='(',RP=')'
    };
    int active();

private:
    computer();
    double expr(bool get);
    double term(bool get);
    double prim(bool get);
    Token_value get_token();
    double error(const std::string& s);
private:
    std::map<std::string,double> table;
    Token_value curr_tok = PRINT;
    double number_value;
    std::string string_value;

    int no_of_errors;
};