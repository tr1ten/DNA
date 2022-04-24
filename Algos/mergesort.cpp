#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> merge(vector<int> left,vector<int> right)
{

    vector<int> res;
    int nl= left.size();
    int nr = right.size();
    int i=0;
    int j=0;
    while (i<nl && j<nr)
    {
        if(left[i]<right[j])
        {
            res.push_back(left[i]);
            i++;
        }
        else{
            res.push_back(right[j]);
            j++;
        }
    }
    while (i<nl)
    {
        res.push_back(left[i]);
        i++;
    }
    while (j<nr)
    {
        res.push_back(right[j]);
        j++;
    }
    return res;
    
    
}
vector<int> mergeSort(vector<int> arr)
{
    int n = arr.size();
    if (n<2)
    {
        return arr;
    }
    
    int mid = n/2;
    vector<int> l = vector<int>(arr.begin() , arr.begin()+mid);
    vector<int> r = vector<int>(arr.begin() + mid, arr.end());
    vector<int> left = mergeSort(l);
    vector<int> right = mergeSort(r);
    return merge( left,right);

}
int main()
{
    vector<int> arr = {5,4,3,2,1};
    vector<int> svec = mergeSort(arr);
    for (auto i:svec)
    {
        cout << i << " ";
    }
    
    return 0;
}
