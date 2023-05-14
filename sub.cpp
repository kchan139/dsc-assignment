#include "library.h"

//<<<<<<<<<<<<<<<<<<<<<<<<<< Problem 1 >>>>>>>>>>>>>>>>>>>>>>>>>>//
//============================== A ===============================//
string Infix2Postfix(const string & expression) 
{
    checkInfixValidity(expression);

    stack <char> operatorStack; string postfix = "";
    for (size_t i = 0; i < expression.length(); i++) 
    {
        char c = expression[i];
        if (isdigit(c))
        {
            postfix += c;
            while (i+1 < expression.length() && isdigit(expression[i+1])) 
                { postfix += expression[i+1]; i++; }
            postfix += " ";
        } 
        else if (isOperator(c)) 
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) 
            {
                postfix += operatorStack.top();
                operatorStack.pop();
                postfix += " ";
            }
            operatorStack.push(c);
        }
        else if (c == '(') 
            operatorStack.push(c);
        else if (c == ')') 
        {
            while (!operatorStack.empty() && operatorStack.top() != '(') 
            {
                postfix += operatorStack.top();
                operatorStack.pop();
                postfix += " ";
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        }
    }
    while (!operatorStack.empty()) 
    {
        postfix += operatorStack.top();
        operatorStack.pop();
        postfix += " ";
    }
    return postfix;
}

//============================== B ===============================//
string Infix2Prefix(const string & expression) 
{
    checkInfixValidity(expression);

    stack <char> operatorStack;
    string prefix = "";
    string reversedExpr = expression;
    reverse(reversedExpr.begin(), reversedExpr.end());

    for (size_t i = 0; i < reversedExpr.length(); i++) 
    {
        char c = reversedExpr[i];
        if (isdigit(c)) 
        {
            prefix += c;
            while (i+1 < reversedExpr.length() && isdigit(reversedExpr[i+1])) 
                { prefix += reversedExpr[i+1]; i++; }
            prefix += " ";
        }
        else if (isOperator(c)) 
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) > getPrecedence(c)) 
            {
                prefix += operatorStack.top();
                operatorStack.pop();
                prefix += " ";
            }
            operatorStack.push(c);
        }
        else if (c == ')')
            operatorStack.push(c);
        else if (c == '(') 
        {
            while (!operatorStack.empty() && operatorStack.top() != ')') 
            {
                prefix += operatorStack.top();
                operatorStack.pop();
                prefix += " ";
            }
            operatorStack.pop();
        }
    }

    while (!operatorStack.empty()) 
    {
        prefix += operatorStack.top();
        operatorStack.pop();
        prefix += " ";
    }
    reverse(prefix.begin(), prefix.end());
    prefix.erase(prefix.begin());
    
    return prefix;
}


//============================== C ===============================//
double performOperation(double op1, double op2, char op) 
{
    switch (op) 
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0)
                throw std::runtime_error("Divided-by-0");
            return op1 / op2;
        case '^':
            if (op1 == 0 && op2 == 0)
                throw std::runtime_error("Undefined");
            return pow(op1, op2);
    }
    return -1;
}

double evaluatePostfix(const string & postfix) 
{
    stack <double> operands;
    stringstream   ss(postfix);
    string         token;

    while (ss >> token) 
    {
        if (isOperator(token[0])&&(!token[1]&&!isdigit(token[1]))) 
        {
            double op2 = operands.top(); operands.pop();
            double op1 = operands.top(); operands.pop();
            double result = performOperation(op1, op2, token[0]);
            operands.push(result);
        } 
        else operands.push(stod(token));
    }
    return operands.top();
}

double evaluatePrefix(const string & prefix) 
{
    stack<double> operands;
    stringstream ss(prefix);

    istream_iterator <string> begin(ss), end;
    vector <string> tokens(begin, end);

    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) 
    {
        if (isOperator((*it)[0]) && !(*it)[1]) 
        {
            double op1 = operands.top(); operands.pop();
            double op2 = operands.top(); operands.pop();
            double result = performOperation(op1, op2, (*it)[0]);
            operands.push(result);
        }
        else operands.push(stod(*it));
    }
    return operands.top();
}


bool isPrefixExpression(const string & expression) {
    for (size_t i = 0; i < expression.size(); i++) 
    {
        if (isspace(expression[i])) 
            continue;
        if (isOperator(expression[i]) && isspace(expression[i+1]))
            return true;
        if (isdigit(expression[i]))
            return false;
    }
    return false;
}

string PostfixPrefixCalculator(string expression) 
{
    double result = isPrefixExpression(expression) ? 
                    evaluatePrefix(expression) : evaluatePostfix(expression);
    stringstream ss;
    ss << fixed << setprecision(4) << result;
    string FinalResult = ss.str();

    for (size_t i = FinalResult.size()-1;i>=0;i--)
    {
        if (FinalResult[i]!='0' && FinalResult[i]!='.')
            break;
        if (FinalResult[i]=='.')
        {
            FinalResult.pop_back();
            break;
        }
        FinalResult.pop_back();
    }
    return FinalResult;
}





//<<<<<<<<<<<<<<<<<<<<<<<<<< Problem 2 >>>>>>>>>>>>>>>>>>>>>>>>>>//
//============================== A ===============================//


//============================== B ===============================//


//============================== C ===============================//
