#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        int l1=sqrt(l),r1 = sqrt(r);
        int a= max(0,(r1-l1+1)*3);
        int d1 = l-l1*l1;
        int d2 = (r1+1)*(r1+1) -r -1;
        a -= ceil(d1*1.0/l1);
        a -= ceil(d2*1.0/r1);
        cout << a << endl;
    }
    return 0;
}
