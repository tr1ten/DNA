#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
typedef pair<int, int> pi;

void printTurnaroundTime(vector<vector<int>> &process, int n, vector<int> &completion)
{
    vector<int> turnaround(n,0);
    vector<int> waiting(n,0);
    // calculate turnaround and waiting time
    for(int i=0;i<n;i++){
        turnaround[i] = completion[i] - process[i][0];
        waiting[i] = turnaround[i] - process[i][1];
    }
    // print
    cout << endl;
    cout << "Completion Time " << endl;
    for(int i=0;i<n;i++){
        cout << completion[i] << " ";
    }
    cout << endl;
    cout << "Turnaround Time " << endl;
    for(int i=0;i<n;i++){
        cout << turnaround[i] << " ";
    }
    cout << endl;
    cout << "Waiting Time " << endl;
    for(int i=0;i<n;i++){
        cout << waiting[i] << " ";
    }
    cout << endl;

}
// actual solutions 
void nonsgf(vector<vector<int>> process){
    vector<vector<int>> process2 = process;
    int n = process.size();
    vector<int> completion(n,0);

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
        // cout << pq.top().first << " " << pq.top().second << endl;
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
    printTurnaroundTime(process2,n,completion);
    
    return;
}
void premsgf(vector<vector<int>> process){
    vector<vector<int>> process2 = process;
    int n = process.size();
    vector<int> completion(n,-1);
    int cnt=0; // count completed process
    int t = 0; // timer
    int cur=-1; // currently running process
    while (cnt<n)
    {
        for (int j = 0; j < n; j++) { // check if smaller remaining time exist
            if(completion[j]!=-1 || process[j][0]>t) continue;
            if(cur==-1 || process[cur][1]>process[j][1]){ // if such process exist then context switch
                cur = j;
            }
            
        }
        process[cur][1]--; // decrease execution time of running process
        t++; // increase the timer
        if(process[cur][1]==0) { // if completed
            completion[cur] = t;
            cur =-1;
            cnt++;
        }
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
    premsgf(process);
    return 0;
}
