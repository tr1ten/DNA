class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        std::vector<std::vector<int>> Rows;
        std::vector<int> arr1 = {1};
        Rows.push_back(arr1);
        if (n == 1)
        {
            return Rows;
        }
        std::vector<int> arr2 = {1, 1};
        Rows.push_back(arr2);
        if (n == 2)
        {
            return Rows;
        }
        for (int i = 2; i < n; i++)
        {
            std::vector<int> row;
            row.push_back(1);
            int j = 0;
            int z = 1;
            while (z < Rows[i - 1].size())
            {
                row.push_back(Rows[i - 1][j] + Rows[i - 1][z]);
                j++;
                z++;
            }
            row.push_back(1);
            Rows.push_back(row);
        }
        return Rows;
    }
};