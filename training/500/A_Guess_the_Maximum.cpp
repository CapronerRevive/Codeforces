#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

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
        LL ans = max(a[0], a[1]);
        for (int i = 1; i < n - 1; ++i) {
            ans = min(ans, max(a[i], a[i + 1]));
        }
        cout << ans - 1 << endl;
    }
}