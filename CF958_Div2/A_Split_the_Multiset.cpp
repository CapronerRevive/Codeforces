#include "bits/stdc++.h"

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        while (n > 0) {
            if (n > k * k) {
                n -= k * k;
                ans += k + 1;
                n += 1;
            } else {
                n = n + (k - 3);
                ans += n / (k - 1);
                n = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}