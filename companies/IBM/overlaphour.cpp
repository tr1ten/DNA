#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;

    int hh = stoi(input.substr(0, 2));
    int mm = stoi(input.substr(3, 2));

    int time_until_overlap = 0;

    while (true) {
        mm++;
        if (mm == 60) {
            mm = 0;
            hh = (hh + 1) % 12;
        }
        time_until_overlap++;

        if ((mm * 6) == (hh * 30 + mm / 2)) {
            break;
        }
    }

    cout << time_until_overlap << endl;

    return 0;
}