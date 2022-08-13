#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int findOpenParanthesis(const string exp,int start)
{
    stack<char> st;
    st.push(')');
    for (int i = start; i < exp.size(); i++)
    {
        char c = exp.at(i);
        if (c == ')')
        {
            st.push(c);
        }
        else if (c == '(')
        {
            st.pop();
            if (st.empty())
            {
                return i;
            }
        }
    }
}
string infix2Prefix(string exp, bool isReverse)
{
    stack<char> st;
    if(!isReverse)
    {
        reverse(exp.begin(), exp.end());
    }
    string prefixExp;
    unordered_map<char, int> ops;
    unordered_set<char> L2R = {'+', '-', '*', '/'};
    ops['('] = 4;
    ops[')'] = 4;
    ops['^'] = 3;
    ops['*'] = 2;
    ops['/'] = 2;
    ops['+'] = 1;
    ops['-'] = 1;
    for (int i = 0; i < exp.size(); i++)
    {
        char c = exp.at(i);
        if (ops.count(c))
        {

            if (c == ')')
            {
                int j = findOpenParanthesis(exp,i+1);
                int size = j - i - 1;
                string newString = infix2Prefix(exp.substr(i + 1, size), true);
                reverse(newString.begin(), newString.end());
                prefixExp = prefixExp + newString;
                i = j;
                continue;
            }
            if (st.empty() || ops[c] > ops[st.top()])
            {
                st.push(c);
            }
            else if (ops[c] == ops[st.top()])
            {
                if (!L2R.count(c))
                {
                    while (ops[st.top()] == ops[c])
                    {
                        prefixExp.push_back(st.top());
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
                    prefixExp.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }
        else
        {
            prefixExp.push_back(c);
        }
    }
    while (!st.empty())
    {
        prefixExp.push_back(st.top());
        st.pop();
    }
    reverse(prefixExp.begin(), prefixExp.end());
    return prefixExp;
}

int main()
{
    cout << infix2Prefix("K+L-((M*N+(O^P)*W)/U/V)*T+Q", false) << endl;
    return 0;
}

// ACD+D++
// ABC*DE*+*F+
// convert following prefix to infix
// +AB -> A+B
// *AB -> A*B
// ++-+KL*MN*//*^POWUVTQ -> (K+L)*(M*N)/(U/V)*(T+Q)^POW
