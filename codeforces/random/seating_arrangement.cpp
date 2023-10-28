#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t-->0){
        int n;
        cin >> n;
        int base = ((n-1)/12)*12;
        int c=n-base;
        int opp = base + 13-c;
        string s[6] = {"WS","MS","AS","AS","MS","WS"};
        cout << opp << " " << s[(c-1)%6] << endl;
        cout << c << " " << base << " " << endl;
    }
	return 0;
}
