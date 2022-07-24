#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct Data
{
    int start;
    int val;
    Data(int s, int v) : start(s), val(v) {}
};

int largestRectangleArea(vector<int> &heights)
{
    stack<Data> st;
    int i = 0;
    int n = heights.size();
    int maxArea = 0;
    while (i < heights.size())
    {
        int j = i - 1;
        while (!st.empty() && st.top().val > heights[i])
        {
            int area = st.top().val * (i - st.top().start);
            j = st.top().start-1;
            st.pop();
            maxArea = max(maxArea, area);
        }
        st.push({j + 1, heights[i]});
        i++;
    }
    while (!st.empty())
    {
        maxArea = max(st.top().val*(n-st.top().start),maxArea);
        st.pop();
    }
    
    return maxArea;
}
int main()
{
    vector<int> some = {1, 8, 9, 6, 3, 8};
    cout << largestRectangleArea(some);
    return 0;
}
