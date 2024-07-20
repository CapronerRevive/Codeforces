#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

ULL a[N];
ULL r[N];
int cnt[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        ULL n;
        ULL x;
        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int pr = 0;
        ULL sum = 0;
        for (int l = 0; l < n; ++l) {
            while (pr < n) {
                if (sum > x) {
                    break;
                }
                sum += a[pr];
                pr += 1;
            }
            if (sum > x) {
                r[l] = pr - 1;
#ifndef ONLINE_JUDGE
                cout << l << " " << r[l] << " " << sum << endl;
#endif
            } else {
                r[l] = -1;
            }
            sum -= a[l];
        }
        ULL ans = n * (n + 1);
        ans /= 2;
        for (int i = 0; i < n; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (r[i] == -1) {
                continue;
            }
            ans--;
            ans -= cnt[i];
#ifndef ONLINE_JUDGE
            cout << i << " " << ans << " " << r[i] + 1 << endl;
#endif
            cnt[r[i] + 1] += cnt[i] + 1;
        }
        cout << ans << endl;
    }
}