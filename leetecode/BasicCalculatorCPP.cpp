#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
// To-Do : Fix Bug in this code
class Solution {
public:
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
    int findCloseParanthesis(const string exp,int start)
    {
    stack<char> st;
    st.push('(');
    for (int i = start; i < exp.size(); i++)
    {
        char c = exp.at(i);
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            st.pop();
            if (st.empty())
            {
                return i;
            }
        }
    }
    return 0;
}
string infix2Postfix(string exp)
{
    stack<char> st;
    string postfixExp;
    unordered_map<char, int> ops;
    unordered_set<char> L2R = {'+', '-', '*', '/'};
    ops['('] = 4;
    ops[')'] = 4;
    ops['^'] = 3;
    ops[')'] = 4;
    ops['*'] = 2;
    ops['/'] = 2;
    ops['+'] = 1;
    ops['-'] = 1;
    for (int i=0;i<exp.size();i++)
    {
        char c = exp.at(i);
        if (ops.count(c))
        {

            if (c == '(')
            {
                int j = findCloseParanthesis(exp,i+1);
                int size = j-i-1;
                string newString = infix2Postfix(exp.substr(i+1,size));
                postfixExp = postfixExp + newString;
                i = j;
                continue;
            }
            if (st.empty() || ops[c] > ops[st.top()])
            {
                st.push(c);
            }
            else if (ops[c] == ops[st.top()])
            {
                if (L2R.count(c))
                {
                    while (ops[st.top()] == ops[c])
                    {
                        postfixExp.push_back(st.top());
                        st.pop();
                    }
                    st.push(c);
                }
                else
                {
                    st.push(c);
                }
            }
            else
            {
                while (!st.empty() && ops[st.top()] >= ops[c])
                {
                    postfixExp.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }

        else
        {
            postfixExp.push_back(c);
        }
    }
    while (!st.empty())
    {
        postfixExp.push_back(st.top());
        st.pop();
    }
    return postfixExp;
}

    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        string ps = infix2Postfix(s);
        ps.erase(remove(ps.begin(), ps.end(), ' '), ps.end());
        vector<string> v;
        // push string character to vector
        for (int i = 0; i < ps.size(); i++)
        {
            string s(1, ps[i]);
            v.push_back(s);
        }
        return evalRPN(v);
    }
};