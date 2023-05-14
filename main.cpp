#include "sub.cpp"

int main ()
{
    try
    {
        string expression;
        cout << "Enter an infix expression: ";
        getline(cin, expression);
        string postfix = Infix2Postfix(expression);
        string prefix  = Infix2Prefix(expression);
        cout << "Postfix: "    << postfix << endl;
        cout << "Prefix: "     << prefix << endl;
        cout << "Evaluation: " << PostfixPrefixCalculator("1 +2 +") << endl;
        cout << "Evaluation: " << PostfixPrefixCalculator(prefix) << endl;
    }
    catch (const runtime_error & error) 
    {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}