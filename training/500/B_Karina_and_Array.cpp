#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

LL a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        LL ans = max(a[0]*a[1], a[n-2]*a[n-1]);
        cout << ans << endl;
    }
}