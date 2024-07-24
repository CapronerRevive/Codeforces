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
        string s;
        cin >> s;
        int cnt = 0;
        for (auto c : s) {
            if (c == 'B') {
                cnt ++;
            }
        }
        if (cnt == k) {
            cout << 0 << endl;
        } else if (cnt < k) {
            int d = k - cnt;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'A') {
                    d -= 1;
                }
                if (d == 0) {
                    cout << 1 << endl;
                    cout << i + 1 << " B" << endl;
                    break;
                }
            }
        } else {
            int d = cnt - k;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'B') {
                    d -= 1;
                }
                if (d == 0) {
                    cout << 1 << endl;
                    cout << i + 1 << " A" << endl;
                    break;
                }
            }
        }
    }
}