#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

LL a[N];
double l[N];
LL two_power[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            l[i] = log(a[i]);
            two_power[i] = 0;
        }
#ifndef ONLINE_JUDGE
        for (int i = 0; i < n; ++i) {
            cout << l[i] << " ";
        }
        cout << endl;
#endif
        LL ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 1) {
                if (a[i-1] != 1) {
                    ans = -1;
                    break;
                }
            } if (a[i-1] == 1) {
                continue;
            }
            double d = l[i-1] / l[i];
            d = log(d) / log(2);
            d = d + two_power[i-1];
            two_power[i] = ceil(d);
            if (two_power[i] < 0) {
                two_power[i] = 0;
            }
            ans += two_power[i];
        }
#ifndef ONLINE_JUDGE
        for (int i = 0; i < n; ++i) {
            cout << two_power[i] << " ";
        }
        cout << endl;
#endif
        cout << ans << endl;
    }
}