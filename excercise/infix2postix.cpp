#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
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
                while (!st.empty() && ops[st.top()] > ops[c])
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

int main()
{
    cout << infix2Postfix("A+(B+C*(D+E))") << endl;
    return 0;
}
