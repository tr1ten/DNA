#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
typedef pair<int, int> pi;

// actual solutions 
void nonsgf(vector<vector<int>> process){
    int n = process.size();
    vector<int> completion(n,0);
    vector<int> turnaround(n,0);
    vector<int> waiting(n,0);

    sort(process.begin(),process.end());
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    int time = process[0][0];
    int i =0;
    while (i<n) {
        time = max(time,process[i][0]);
        while(i<n && process[i][0]<=time){
            pq.push(make_pair(process[i][1],i));
            i++;
        }
        cout << pq.top().first << " " << pq.top().second << endl;
        if(!pq.empty()){
            time += pq.top().first;
            completion[process[pq.top().second][2]] = time;
            pq.pop();
        }
    }
    while (!pq.empty()) {
        time += pq.top().first;
        completion[process[pq.top().second][2]] = time;
        pq.pop();
    }
    return;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<int>> process(N,vector<int>(3,0));
    int i=0;
    for(vector<int> &p:process){
        cin >> p[0] >> p[1];
        p[2] = i++;
    }
    nonsgf(process);
    return 0;
}
