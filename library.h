#ifndef library_h
#define library_h

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <unordered_map>

using namespace std;

bool isOperator(char c)
{ return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }

int getPrecedence(char op) 
{
    switch (op) 
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default : return 0;
    }
}

// bool isLogicOperator(char c) 
// { return c == '&' || c == '|' || c == '!'; }

// int getLogicPrecedence(char op) 
// {
//     switch (op) 
//     {
//         case '|': return 1;
//         case '&': return 2;
//         case '!': return 3;
//         default : return 0;
//     }
// }

void checkInfixValidity(string expression) 
{
    // Check for consecutive operators
    for (size_t i = 0; i < expression.length() - 1; i++)
        if (isOperator(expression[i]) && isOperator(expression[i+1]) && expression[i] != '-' && expression[i+1] != '-')
            throw std::runtime_error("Undefined error");


    // Check for precedence order
    for (size_t i = 0; i < expression.length() - 1; i++)
        if (isOperator(expression[i]) && isOperator(expression[i+1]) && expression[i] != '-' && expression[i+1] != '-')
            if (getPrecedence(expression[i]) < getPrecedence(expression[i+1])) 
                throw std::runtime_error("Multiple-output error");


    // Check for parenthesis
    int openCount = 0, closeCount = 0;
    for (size_t i = 0; i < expression.length(); i++) 
    {
        if (expression[i] == '(')       
            openCount++;
        else if (expression[i] == ')')  
            closeCount++;
        if (closeCount > openCount)
            throw std::runtime_error("Syntax error");
    }
    if (openCount != closeCount)
        throw std::runtime_error("Syntax error");

    // Check for floating point errors
    for (size_t i = 0; i < expression.length() - 1; i++) 
    {
        if (expression[i] == '.' && expression[i+1] == '.')
            throw std::runtime_error("Syntax error");
        
        if (expression[i] == '+' && expression[i+1] == '.')
            throw std::runtime_error("Syntax error");
    }
    return;
}

#endif