#include "bits/stdc++.h"

using namespace std;

#define ULL unsigned long long

struct Node {
    ULL a;
    int d;
    vector<int> conn;
};

Node tree[300005];

void GetDepth(int idx, int d) {
    tree[idx].d = d;
    for (auto nxt : tree[idx].conn) {
        if (tree[nxt].d != -1) {
            continue;
        }
        GetDepth(nxt, d+1);
    }
}

ULL dp[300005][22];

void GetAns(int idx) {
    for (auto nxt : tree[idx].conn) {
        if (tree[nxt].d <= tree[idx].d) {
            continue;
        }
        GetAns(nxt);
    }
    for (int i = 0; i < 22; ++i) {
        dp[idx][i] = tree[idx].a * i;
        for (auto nxt : tree[idx].conn) {
            if (tree[nxt].d <= tree[idx].d) {
                continue;
            }
            ULL p;
            bool flag = false;
            for (int j = 0; j < 22; ++j) {
                if (i == j) {
                    continue;
                }
                if (flag) {
                    p = min(p, dp[nxt][j]);
                } else {
                    p = dp[nxt][j];
                    flag = true;
                }
            }
            dp[idx][i] += p;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ULL s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tree[i].a;
            tree[i].d = -1;
            tree[i].conn.clear();
            s += tree[i].a;
        }
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            tree[x-1].conn.push_back(y-1);
            tree[y-1].conn.push_back(x-1);
        }
        GetDepth(0, 0);
        GetAns(0);
        ULL ans = dp[0][0];
        for (int i = 1; i < 22; ++i) {
            ans = min(ans, dp[0][i]);
        }
        ans += s;
        cout << ans << endl;
    }
}