#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i%k] = max(a[i%k], a[i]);
        }
        LL ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }
        cout << ans << endl;
    }
}