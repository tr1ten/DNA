#include <iostream>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;
int evalPrefix(const string exp)
{
    unordered_set<char> hm = {'+', '-', '/', '*'};
    stack<char> sk;
    int lastOpC = 0;
    for (auto c : exp)
    {
        if (hm.count(c))
        {
            sk.push(c);
        }
        else
        {
            sk.push(c);
            lastOpC++;
        }
        if (lastOpC >= 2)
        {
            int second = sk.top() - '0';
            sk.pop();
            int first = sk.top() - '0';
            sk.pop();
            char op = sk.top();
            sk.pop();
            int result = 0;
            switch (op)
            {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;

            default:
                break;
            }
            sk.push(result + '0');
            lastOpC=1;
        }
    }
    return sk.top() - '0';
}
int main()
{
    cout << evalPrefix("+5*32");
    return 0;
}
