#include "library.h"
#include "sub.cpp"

int main ()
{
    try
    {
        cout << "Infix: 1+2" << endl;
        cout << "Postfix: " << Infix2Postfix("1+2") << endl << endl;

        cout << "Infix: 13-15" << endl;
        cout << "Postfix: " << Infix2Postfix("13-15") << endl << endl;

        cout << "Infix: 5*6" << endl;
        cout << "Postfix: " << Infix2Postfix("5*6") << endl << endl; 

        cout << "Infix: 10/15" << endl;
        cout << "Postfix: " << Infix2Postfix("10/15") << endl << endl;

        cout << "Infix: (8/4)+(9-3)" << endl;
        cout << "Postfix: " << Infix2Postfix("(8/4)+(9-3)") << endl << endl;

        cout << "Infix: (3+4)*(5-2)/(6+1)" << endl;
        cout << "Postfix: " << Infix2Postfix("(3+4)*(5-2)/(6+1)") << endl << endl;

        cout << "Infix: 49*(41*39)-(145+78)+193+(121*135+101-88)" << endl;
        cout << "Postfix: " << Infix2Postfix("49*(41*39)-(145+78)+193+(121*135+101-88)") << endl << endl;

        cout << "Infix: 59+107*83*72*91/(27-(112*153)*(111+76))" << endl;
        cout << "Postfix: " << Infix2Postfix("59+107*83*72*91/(27-(112*153)*(111+76))") << endl << endl;

        cout << "Infix: ((123+456)*(789-321))^2/(654+321)" << endl;
        cout << "Postfix: " << Infix2Postfix("((123+456)*(789-321))^2/(654+321)") << endl << endl;

        cout << "Infix: (987+(654*(321/123)))^2-(456+789)" << endl;
        cout << "Postfix: " << Infix2Postfix("(987+(654*(321/123)))^2-(456+789)") << endl << endl;


        cout << "Infix: 1+2" << endl;
        cout << "Prefix: " << Infix2Prefix("1+2") << endl << endl;

        cout << "Infix: 13-15" << endl;
        cout << "Prefix: " << Infix2Prefix("13-15") << endl << endl;

        cout << "Infix: 5*6" << endl;
        cout << "Prefix: " << Infix2Prefix("5*6") << endl << endl; 

        cout << "Infix: 10/15" << endl;
        cout << "Prefix: " << Infix2Prefix("10/15") << endl << endl;

        cout << "Infix: (8/4)+(9-3)" << endl;
        cout << "Prefix: " << Infix2Prefix("(8/4)+(9-3)") << endl << endl;

        cout << "Infix: (3+4)*(5-2)/(6+1)" << endl;
        cout << "Prefix: " << Infix2Prefix("(3+4)*(5-2)/(6+1)") << endl << endl;

        cout << "Infix: 49*(41*39)-(145+78)+193+(121*135+101-88)" << endl;
        cout << "Prefix: " << Infix2Prefix("49*(41*39)-(145+78)+193+(121*135+101-88)") << endl << endl;

        cout << "Infix: 59+107*83*72*91/(27-(112*153)*(111+76))" << endl;
        cout << "Prefix: " << Infix2Prefix("59+107*83*72*91/(27-(112*153)*(111+76))") << endl << endl;

        cout << "Infix: ((123+456)*(789-321))^2/(654+321)" << endl;
        cout << "Prefix: " << Infix2Prefix("((123+456)*(789-321))^2/(654+321)") << endl << endl;

        cout << "Infix: (987+(654*(321/123)))^2-(456+789)" << endl;
        cout << "Prefix: " << Infix2Prefix("(987+(654*(321/123)))^2-(456+789)") << endl << endl;

        cout << "Input: 1 2 +" << endl;
        cout << "Result: " << PostfixPrefixCalculator("1 2 +") << endl << endl;

        cout << "Input: + 1 2" << endl;
        cout << "Result: " << PostfixPrefixCalculator("+ 1 2") << endl << endl;

        cout << "Input: 13 15 -" << endl;
        cout << "Result: " << PostfixPrefixCalculator("13 15 -") << endl << endl;

        cout << "Input: - 13 15" << endl;
        cout << "Result: " << PostfixPrefixCalculator("- 13 15") << endl << endl;

        cout << "Input: 5 6 *" << endl;
        cout << "Result: " << PostfixPrefixCalculator("5 6 *") << endl << endl;

        cout << "Input: * 5 6" << endl;
        cout << "Result: " << PostfixPrefixCalculator("* 5 6") << endl << endl;

        cout << "Input: 10 15 /" << endl;
        cout << "Result: " << PostfixPrefixCalculator("10 15 /") << endl << endl;

        cout << "Input: / 10 15" << endl;
        cout << "Result: " << PostfixPrefixCalculator("/ 10 15") << endl << endl;

        cout << "Input: 8 4 / 9 3 - +" << endl;
        cout << "Result: " << PostfixPrefixCalculator("8 4 / 9 3 - +") << endl << endl;

        cout << "Input: + / 8 4 - 9 3" << endl;
        cout << "Result: " << PostfixPrefixCalculator("+ / 8 4 - 9 3") << endl << endl;

        cout << "Input: 3 4 + 5 2 - * 6 1 + /" << endl;
        cout << "Result: " << PostfixPrefixCalculator("3 4 + 5 2 - * 6 1 + /") << endl << endl;

        cout << "Input: / * + 3 4 - 5 2 + 6 1" << endl;
        cout << "Result: " << PostfixPrefixCalculator("/ * + 3 4 - 5 2 + 6 1") << endl << endl;

        cout << "Input: 49 41 39 * * 145 78 + - 193 + 121 135 * 101 + 88 - +" << endl;
        cout << "Result: " << PostfixPrefixCalculator("49 41 39 * * 145 78 + - 193 + 121 135 * 101 + 88 - +") << endl << endl;

        cout << "Input: + + - * 49 * 41 39 + 145 78 193 - + * 121 135 101 88" << endl;
        cout << "Result: " << PostfixPrefixCalculator("+ + - * 49 * 41 39 + 145 78 193 - + * 121 135 101 88") << endl << endl;

        cout << "Input: 59 107 83 * 72 * 91 * 27 112 153 * 111 76 + * - / +" << endl;
        cout << "Result: " << PostfixPrefixCalculator("59 107 83 * 72 * 91 * 27 112 153 * 111 76 + * - / +") << endl << endl;

        cout << "Input: + 59 / * * * 107 83 72 91 - 27 * * 112 153 + 111 76" << endl;
        cout << "Result: " << PostfixPrefixCalculator("+ 59 / * * * 107 83 72 91 - 27 * * 112 153 + 111 76") << endl << endl;

        cout << "Input: 123 456 + 789 321 - * 2 ^ 654 321 + /" << endl;
        cout << "Result: " << PostfixPrefixCalculator("123 456 + 789 321 - * 2 ^ 654 321 + /") << endl << endl;

        cout << "Input: / ^ * + 123 456 - 789 321 2 + 654 321" << endl;
        cout << "Result: " << PostfixPrefixCalculator("/ ^ * + 123 456 - 789 321 2 + 654 321") << endl << endl;

        cout << "Input: 987 654 321 123 / * + 2 ^ 456 789 + -" << endl;
        cout << "Result: " << PostfixPrefixCalculator("987 654 321 123 / * + 2 ^ 456 789 + -") << endl << endl;

        cout << "Input: - ^ + 987 * 654 / 321 123 2 + 456 789" << endl;
        cout << "Result: " << PostfixPrefixCalculator("- ^ + 987 * 654 / 321 123 2 + 456 789") << endl << endl;

        // cout << "Input: 0 0 ^" << endl;
        // cout << "Result: " << PostfixPrefixCalculator("0 0 ^") << endl << endl;

        cout << "Input: 0 0 /" << endl;
        cout << "Result: " << PostfixPrefixCalculator("0 0 /") << endl << endl;
    }
    catch (const runtime_error& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}