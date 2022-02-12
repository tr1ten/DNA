#include <iostream>
#include <vector>
#include <string>
using namespace std;
void rec(string str, vector<string> &result, int op, vector<int> stack)
{
    if (op == 0 && stack.size() == 0)
    {
        result.push_back(str);
        return;
    }
    else{

    if (op > 0)
    {
        stack.push_back(1);
        rec(str + "(", result, op - 1, stack);
        stack.pop_back();
    }
    if(stack.size()>0)
    {
    stack.pop_back();
    rec(str+')',result,op,stack);
    return;

    }
    }
}
vector<string> generateParenthesis(int n)
{
    vector<int> stack = {1};
    vector<string> result;
    rec("(", result, n-1, stack);
    return result;
}
int main()
{
    for (string v : generateParenthesis(10))
    {
        cout << v << endl;
    }

    return 0;
}
