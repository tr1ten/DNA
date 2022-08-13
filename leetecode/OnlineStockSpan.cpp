#include <iostream>
#include <vector>
#include <string>
using namespace std;
class StockSpanner
{
public:
    vector<int> umap;
    vector<int> vec;
    StockSpanner()
    {
        umap.push_back(1);
    }

    int next(int price)
    {
        if (vec.empty())
        {
            vec.push_back(price);
            return 1;
        }
        int res = 1;
        int j = vec.size() - 1;
        while (j>=0 && vec[j] <= price)
        {
            res =res + umap[j];
            j -= umap[j];   
        }
        umap.push_back(res);
                    vec.push_back(price);

        return res;
    }
};


int main()
{

    return 0;
}
