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
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if (k > 0) {
            ans = 1;
            k -= n;
        }
        int d = 1;
        while (k > 0) {
            for (int i = 0; i < 2; ++i) {
                if (k >= n - d) {
                    ans += 1;
                    k -= (n - d);
                } else {
                    if (k > 0) {
                        ans += 1;
                        k = 0;
                    }
                    break;
                }
            }
            d += 1;
        }
        cout << ans << endl;
    }
}