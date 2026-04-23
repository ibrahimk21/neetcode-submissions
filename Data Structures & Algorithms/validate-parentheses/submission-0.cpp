#include <stack>

bool isOpen(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool closes(char c1, char c2)
{
    return  (c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}');
}

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        stack<char> charStack;
        for(char c: s)
        {
            if(isOpen(c))
            {
                charStack.push(c);
                continue;
            }
            else
            {
                if(!charStack.empty() && closes(charStack.top(), c))
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return charStack.empty();
    }
};