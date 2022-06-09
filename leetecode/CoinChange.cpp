#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unsigned int solve(int target, vector<int> &coins, unsigned int c, unordered_map<int, unsigned int> &hm)
{
    if (target < 0)
    {
        return INT32_MAX;
    }
    if (target == 0)
    {
        return c;
    }
    if (hm.count(target))
    {
        return c + hm[target];
    }
    unsigned int minC = INT32_MAX;
    for (auto den : coins)
    {
        minC = min(solve(target - den, coins, c + 1, hm), minC);
    }
    hm[target] = minC - c;
    return minC;
}

int coinChange(vector<int> &coins, int amount)
{
    unordered_map<int, unsigned int> hm;
    int res = solve(amount, coins, 0, hm);
    return res > 10000 ? -1 : res;
}

int coinChange2(vector<int> &coins, int amount)
{
    int D = coins.size();
    int **matrix = new int*[D + 1];
    for (int i = 0; i < amount+1; i++)
    {
        matrix[i] = new int[amount+1];
    }
    cout << "here "<< matrix[0][0];
    fill(&matrix[0][0], &matrix[amount+1][0], -1);
    for (int i = 0; i <= amount; i++)
    {
        for (int j = 1; j <= D; j++)
        {
            if (coins[j - 1] > i)
            {
                matrix[i][j] = matrix[i][j - 1];
            }
            else
            {
                if (matrix[i][j - 1] == -1)
                {
                    if (i - coins[j - 1] != 0 && matrix[i - coins[j - 1]][j] == -1)
                    {
                        matrix[i][j] = -1;
                    }
                    else
                    {

                        matrix[i][j] = 1 + (i - coins[j - 1] != 0 ? matrix[i - coins[j - 1]][j] : 0);
                    }
                }
                else
                {

                    matrix[i][j] = min(1 + (i - coins[j - 1] != 0 ? matrix[i - coins[j - 1]][j] : 0), matrix[i][j - 1]);
                }
            }
        }
    }
    return matrix[amount][D];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange2(coins, 11);
    return 0;
}
