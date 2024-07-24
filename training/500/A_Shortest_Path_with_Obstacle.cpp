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
        int x[5], y[5];
        for (int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }
        int ans = abs(x[0] - x[1]) + abs(y[0] - y[1]);
        if (x[0] == x[1]) {
            if (x[0] == x[2]) {
                if (y[0] < y[2] && y[2] < y[1]) {
                    ans += 2;
                } else if (y[1] < y[2] && y[2] < y[0]) {
                    ans += 2;
                }
            }
        }
        if (y[0] == y[1]) {
            if (y[0] == y[2]) {
                if (x[0] < x[2] && x[2] < x[1]) {
                    ans += 2;
                } else if (x[1] < x[2] && x[2] < x[0]) {
                    ans += 2;
                }
            }
        }
        cout << ans << endl;
    }
}