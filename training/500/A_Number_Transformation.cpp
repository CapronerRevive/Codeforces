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
        int x, y;
        cin >> x >> y;
        if (y % x > 0) {
            cout << 0 << " " << 0 << endl;
        } else {
            int b = y / x;
            int a = 1;
            cout << a << " " << b << endl;
        }
    }
}