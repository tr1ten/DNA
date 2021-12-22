// 121. Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
#include <unordered_map>
int main()
{
    std::vector<int> prices = {9};
    std::unordered_map<int, int> cacheMax;
    int localMax = -1;
    for (int i = prices.size() - 1; i > 0; i--)
    {
        if (prices[i] > localMax)
        {
            cacheMax[i] = prices[i];
            localMax = prices[i];
        }
        else
        {
            cacheMax[i] = localMax;
        }
        /* code */
    }
    std::cout << "max at 1 is " << cacheMax[1];
    int maxProfit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        maxProfit = std::max(cacheMax[i+1] - prices[i],maxProfit);
    }
    std::cout << "Max  profit is " << maxProfit;

    return 0;
}
