#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1000000 + 10;
const int INF = 1048576 * 16;

priority_queue<int> pq;

int f[30];

void full(int a) {
    int p[30];
    memset(p, 0, sizeof(p));
    for (int i = 0; i < 30; ++i) {
        if (a & 1) {
            p[i] = 1;
        }
        a >>= 1;
    }
    for (int i = 29; i >= 0; --i) {
        if (p[i] == 1) {
            if (f[i] == 0) {
                f[i] = 1;
            } else {
                for (int j = i - 1; j >= 0; --j) {
                    if (f[j] == 0) {
                        f[j] = 1;
                    }
                }
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int k;
        cin >> k;

        while (!pq.empty()) {
            pq.pop();
        }

        for (int i = 0; i < k; ++i) {
            int n;
            cin >> n;
            for (int j = 1; j < n; ++j) {
                int p;
                cin >> p;
            }
            pq.push(n);
        }

        memset(f, 0, sizeof(f));
        
        while (!pq.empty()) {
            int qn = pq.top();
            pq.pop();
            full(qn);
        }

        int ans = 0;

        for (int i = 29; i >= 0; --i) {
            ans <<= 1;
            ans += f[i];
        }

        cout << ans << endl;
    }
}