#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

double euclidean_distance(const pair<int,int>& p1, const pair<int,int>& p2) {
    
    return (double)sqrt(pow(p1.second-p2.second,2) + pow(p2.first-p1.first,2));
}
/*
 * posK is the position of the starting retailer.
retailerXCord is a list representing the X-coordinates of retailers.
headXCord is the X-coordinate of the head retailer.
headYCord is the Y-coordinate of the head retailer.
 */
double minPossLen (int posK, vector<int> retailerXCord, int headXCord, int headYCord)
{
    // Write your code here
    vector<pair<int,int>> pos;
    for(auto x:retailerXCord){
        pos.push_back({x,0});
    }
    pos.push_back({headXCord,headYCord});
    double res= 1e9f;
    pair<int,int> f1 = pos[posK-1];
    while (next_permutation(pos.begin(),pos.end()))
    {  
        double dist = 0.0;
        if(pos[0]!=f1) continue;
        for(auto x:pos){
            dist += euclidean_distance(x,f1);
        }
        res= min(res,dist);

    }
    return res;
}

int main()
{
    //input for posK
  int posK;
  cin >> posK;
  
  
  //input for retailerXCord
  int retailerXCord_size;
  cin >> retailerXCord_size;
  vector<int> retailerXCord;
  for ( int idx = 0; idx < retailerXCord_size; idx++ )
  {
    int temp;
    cin >> temp;
    retailerXCord.push_back(temp);
  }
  //input for headXCord
  int headXCord;
  cin >> headXCord;
  
  //input for headYCord
  int headYCord;
  cin >> headYCord;
  
  
    double result = minPossLen(posK, retailerXCord, headXCord, headYCord);
  cout << result;
  
  
    return 0;
}