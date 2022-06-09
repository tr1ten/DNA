#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;
int evalRPN(vector<string> tokens)
{
    unordered_set<char> hm = {'+', '-', '/', '*'};
    stack<int> q;
    for (auto token : tokens)
    {
        if (token.size()==1 && hm.count(token.at(0)))
        {
            int second = q.top();
            q.pop();
            int first = q.top();
            q.pop();
            int result;
            switch (token.at(0))
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
            q.push(result);
        }
        else
        {
            q.push(atoi(token.c_str()));
        }
    }
    return q.top();
}
int main()
{
    cout << evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"});
    return 0;
}
