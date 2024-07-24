#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0] == s[3]) {
            cout << -1 << endl;
        } else if (s[1] == s[3] || s[0] == s[2]) {
            cout << 6 << endl;
        } else {
            cout << 4 << endl;
        }
    }
}