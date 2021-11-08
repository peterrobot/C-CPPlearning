#include "computer.h"
#include <iostream>
#include <cctype>

computer::computer()
{
    no_of_errors = 0;
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
}

double computer::error(const std::string& s)
{
    no_of_errors++;
    std::cerr << "error: " << s << '\n';
    return 1;
}

double computer::expr(bool get)
{
    double left = term(get);

    while(1)
    {
        switch(curr_tok)
        {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            case END:
                return 1;
            default:
                return left;
        }
    }
}

double computer::term(bool get)
{
    double left = prim(get);

    while(1)
    {
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true);
            break;
        case DIV:
            if(double d = prim(true))
            {
                left /= d;
                break;
            }
            return error("divide by 0");
        case END:
            return 1;
        default:
            return left;
        }
    }
}

double computer::prim(bool get)
{
    if(get) get_token();

    switch(curr_tok)
    {
        case NUMBER:
        {
            double v = number_value;
            get_token();
            return v;
        }
        case NAME:
        {
            double& v = table[string_value];
            if(get_token()==ASSIGN) v = expr(true);
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP:
        {
            double e = expr(true);
            if(curr_tok != RP) return error(") expected");
            get_token();
            return e;
        }
        case END:
            return 1;
        default:
            return error("primary expected");;
    }
}

computer::Token_value computer::get_token()
{
    char ch = 0;
    do{
        if(!std::cin.get(ch)) return curr_tok = END;
    }while(ch!='\n'&&isspace(ch));
    switch(ch)
    {
        case ';':
        case '\n':
            return curr_tok=PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok=Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            std::cin.putback(ch);
            std::cin >> number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch))
            {
                string_value = ch;
                while(std::cin.get(ch)&&isalnum(ch)) string_value.push_back(ch);
                std::cin.putback(ch);
                if(string_value == "EXIT") return curr_tok=END;
                return curr_tok=NAME;
            }
            error("bad token");
            return curr_tok=PRINT;
    }
}

int computer::active()
{
    while(std::cin)
    {
        get_token();
        if(curr_tok==END) break;
        if(curr_tok==PRINT) continue;
        std::cout << expr(false) << std::endl;
    }

    return no_of_errors;
}