#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
struct Data
{
    int timestamp;
    string value;
    Data(int t, string s) : timestamp(t), value(s) {}
};
class TimeMap
{
public:
    unordered_map<string, vector<Data>> hm;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        auto data = Data(timestamp, value);
        if (!hm.count(key))
        {
            hm[key] = {data};
        }
        else
        {
            hm[key].push_back(data);
        }
    }

    string get(string key, int timestamp)
    {
        if (!hm.count(key))
        {
            return "";
        }
        auto arr = hm[key];
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid].timestamp == timestamp)
            {
                return arr[mid].value;
            }
            else if (arr[mid].timestamp > timestamp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return arr[mid].timestamp <= timestamp ? arr[mid].value : arr[mid].value;
    }
};
int main()
{

    return 0;
}
