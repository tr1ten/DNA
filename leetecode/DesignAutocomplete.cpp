#include <bits/stdc++.h> 
using namespace std;
class AutocompleteSystem {
public:
    int cur = 0;
    string cw;
    unordered_map<string,int> cnt;
    vector<string> words;
    AutocompleteSystem(vector<string> &A, vector<int> &B) {
        for(int i=0;i<A.size();i++){
            cnt[A[i]] = B[i];
        }
        reset();
        
    }
    void reset(){
            cur = 0;
            cw = "";
            words.clear();
            for(auto it:cnt){
                words.push_back(it.first);
            }
            auto cmp = [&](string &a,string &b){
                return cnt[a] == cnt[b] ? a<b : cnt[a]>cnt[b];
            };
            sort(words.begin(),words.end(),cmp);
    }
    vector<string> input(char c) {
        if(c=='#'){
            cnt[cw]++;
            reset();
            return vector<string>();
        }
        cw +=c;
        vector<string> nw;
        for(auto v:words){
            if(cur<v.size() && v.at(cur)==c) nw.push_back(v);
        }
        cur++;
        words = nw;
        if (words.size()<3) return words;
        return vector<string>(words.begin(),words.begin()+3);
        
    }
};
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t-->0)
    {
        vector<string> words;
    vector<int> times;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string w;
        cin >> w;
        words.push_back(w);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>> x;
        times.push_back(x);
    }
    
    AutocompleteSystem ac(words,times);
    string q;
    cin >> q;
    for(auto x:q)
    {
        for(auto v:ac.input(x)) cout << v << " ";
        cout << endl;
    }
    }
    
    
    return 0;
}
