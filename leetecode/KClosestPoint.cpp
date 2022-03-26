#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <unordered_map>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<double> pqueue;
    unordered_map<double,vector<int>> hashmap;
    for (int i=0;i<points.size();i++)
    {
        vector<int> point = points[i];
        double ed = sqrt(pow(point[0],2) + pow(point[1],2));
        pqueue.push(-1*ed);
        if(hashmap.count(ed))
        {
            hashmap[ed].push_back(i);
        }
        else{
        hashmap[ed] = {i};
    }
        
    }
    int j=k;
    vector<vector<int>> out;
    while (j>0)
    {
        double ed = pqueue.top();
        pqueue.pop();
        vector<int> ponts = hashmap[-1*ed];
        for (int index:ponts)
        {
            out.push_back(points[index]);
            j--;
        }
    
    }
    return out;

}
int main()
{
    vector<vector<int>> a =  {{3,3},{5,-1},{-2,4}};
    kClosest(a,1);
    return 0;
}
