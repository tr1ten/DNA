#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int findCloseParanthesis(const string exp, int start)
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
    return -1;
}
int calculate(string s)
{
    stack<int> st;
    int plus = '+';
    int minus = '-';
    int space = ' ';
    int opBracked = '(';
    int clBracked = ')';
    bool isPrev = false;
    int ex = 1;
    for (int i = 0; i < s.size(); i++)
    {
        long long c = s.at(i);
        if (c == space)
        {
            continue;
        }
        if(!isPrev && c==minus)
        {
            ex = -1;
            continue;
        }
        if (c == opBracked)
        {
            int j = findCloseParanthesis(s, i + 1);
            int size = j - i - 1;
            c = (ex*calculate(s.substr(i + 1, size))) + '0';
            ex = ex*ex;
            i = j;
        }
        if (c != plus && c != minus && (c-'0')<10 && c>='0')
        {
            string p;
            p.push_back(c);
            while (i < s.size() - 1 && (s.at(i + 1) != plus && s.at(i + 1) != minus))
            {
                i++;
                p.push_back(s.at(i));
            }
            c = ex*atoi(p.c_str()) + '0';
        }
        isPrev = true;
        ex = 1;
        if (st.size() < 2)
        {
            st.push(c);
        }
        else
        {
            char op = st.top();
            st.pop();
            int a = st.top() - '0';
            st.pop();
            int b = c - '0';
            int res;
            switch (op)
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
            default:
                break;
            }
            st.push(res + '0');
        }
    }
    return ex*(st.top() - '0');
}
int main()
{
    cout << calculate("-(48+10)+2");
    return 0;
}
