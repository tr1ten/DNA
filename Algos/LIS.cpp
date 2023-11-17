// longest non decreasing subsequence
int lengthOfLIS(vector<int>& nums) {
        multiset<int> st; // set for strictly
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x<0) continue;
            if(!st.empty()){
                auto it = st.upper_bound(x); // lower bound for strictly
                if(it!=st.end()) st.erase(it);
            }
            st.insert(x);
            if(i==nums.size()-1) return distance(st.begin(),st.upper_bound(x));

        }
        return st.size();
    }