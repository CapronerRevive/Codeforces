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
        int n, m;
        cin >> n >> m;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            s += a;
        }
        if (s == m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}