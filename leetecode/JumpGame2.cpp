#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    int jc = 0;
    int cj = nums[0];
    int i = 0;
    while (i < (n - 1))
    {
        int maxEl = nums[i + 1];
        int mi = i + 1;
        for (int j = i + 2; ((j < n) && (j <= (i + cj))); j++)
        {
            int temp=(nums[j] + (j - i - 1));
            // std::cout << "got val is " <<  temp<< std::endl;
            if(temp > maxEl)
            {
                maxEl = temp;
                mi = j;
            }
        }
        if (cj < n - (i + 1))
        {
            cj = nums[mi];
        }
        else
        {
            mi = cj + i;
            cj = nums[cj + i];
        }
        // std::cout << "max idnex "<< mi << " i is "<< i << " cj  is "<< cj<< std::endl;
        jc++;
        i = mi;
    }

    return jc;
}
int main()
{
    vector<int> a = {1,2,1,1,1};
    std::cout << "jup count is " << jump(a) << std::endl;
    return 0;
}