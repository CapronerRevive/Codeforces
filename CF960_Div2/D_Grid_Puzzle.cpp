#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

int a[N];

// 0: 0000
// 1: 0011
// 2: 1100
int dp[N][5];

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
        if (a[0] == 0) {
            dp[0][0] = 0;
            dp[0][1] = 1;
            dp[0][2] = 1;
        } else if (a[0] < 3) {
            dp[0][0] = 1;
            dp[0][1] = 2;
            dp[0][2] = 1;
        } else {
            dp[0][0] = 1;
            dp[0][1] = 2;
            dp[0][2] = 2;
        }

        for (int i = 1; i < n; ++i) {
            int p;
            p = dp[i-1][0] + 1;
            if (a[i] == 0) {
                p = min(p, dp[i-1][0]);
            }
            
            p = min(p, dp[i-1][1] + 1);
            if (a[i] == 0) {
                p = min(p, dp[i-1][1]);
            }

            p = min(p, dp[i-1][2] + 1);
            if (a[i] < 3) {
                p = min(p, dp[i-1][2]);
            }

            dp[i][0] = p;

            p = dp[i-1][0] + 2;
            if (a[i] == 0) {
                p = min(p, dp[i-1][0] + 1);
            }
            
            p = min(p, dp[i-1][1] + 2);
            if (a[i] == 0) {
                p = min(p, dp[i-1][1] + 1);
            }

            p = min(p, dp[i-1][2] + 2);
            if (a[i] < 5) {
                p = min(p, dp[i-1][2] + 1);
            }

            dp[i][1] = p;

            p = dp[i-1][0] + 2;
            if (a[i] < 3) {
                p = min(p, dp[i-1][0] + 1);
            }
            
            p = min(p, dp[i-1][1] + 2);
            if (a[i] < 5) {
                p = min(p, dp[i-1][1] + 1);
            }

            p = min(p, dp[i-1][2] + 2);
            if (a[i] < 3) {
                p = min(p, dp[i-1][2] + 1);
            }

            dp[i][2] = p;

#ifndef ONLINE_JUDGE
            cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
#endif

        }
        int ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
        cout << ans << endl;
    }
}