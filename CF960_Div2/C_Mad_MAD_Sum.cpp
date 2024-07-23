#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

ULL a[N], b[N], cnt[N];

ULL Foo(int n) {
    ULL ans = 0;
    memset(cnt, 0, sizeof(ULL) * (n + 10));
    ULL mx = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
        cnt[a[i]] += 1;
        if (cnt[a[i]] > 1 && a[i] > mx) {
            mx = a[i];
        }
        b[i] = mx;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
    return ans;
}

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
        ULL ans = 0;
        ans += Foo(n);
        ans += Foo(n);
        for (int i = n - 1; i >= 0; --i) {
            ULL p = a[i];
            p *= (n - i);
            ans += p;
        }
        cout << ans << endl;
    }
}