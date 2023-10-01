#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
     int n;
     cin>>n;
     vector<int>arr(n);
     for(int i=0;i<n;i++)cin>>arr[i];
     vector<int>presum(n);
     presum[0]=arr[0];
     for(int i=1;i<n;i++)presum[i]=presum[i-1]+arr[i];
     vector<int>dp(n); // denoting maximum length of array we can achieve
     vector<int>val(n);
     dp[0]=1;
     val[0]=arr[0];

     for(int i=1;i<n;i++){
        
        int l=0,h=i;
        int ind=0;
        while(h>=l){
          int mid=(l+h)/2;
          int sum= presum[i]- (mid>0?presum[mid-1]:0);
          int prev = (mid>0?val[mid-1]:0);
          if(sum>=prev){
            ind=mid;
            l=mid+1;
          }
          else h=mid-1;
        }
        if(ind==0){
          dp[i]=1;
          val[i]=presum[i];
        }
        else{
          dp[i]=dp[ind-1]+1;
          val[i]=presum[i]-presum[ind-1];
        }
     }
     cout<<dp.back();
}