#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 2000 + 10;

struct DSU {
    int p[N];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int get_p(int idx) {
        if (p[idx] == idx) {
            return idx;
        }
        return p[idx] = get_p(p[idx]);
    }

    void unite(int x, int y) {
        x = get_p(x);
        y = get_p(y);
        if (x == y) {
            return;
        }
        if (x > y) {
            swap(x, y);
        }
        p[y] = x;
    }

    bool check(int x, int y) {
#ifndef ONLINE_JUDGE
        cout << "check " << x << " " << y << " " << (get_p(x) == get_p(y)) << endl;
#endif
        return get_p(x) == get_p(y);
    }
};

DSU D;

int div_num[N][N];
int mp[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            for (int j = 1; j < n; ++j) {
                div_num[j][i] = a % j;
            }
        }
#ifndef ONLINE_JUDGE
        for (int d = 1; d < n; ++d) {
            cout << "div " << d << endl;
            for (int i = 0; i < n; ++i) {
                cout << div_num[d][i] << " ";
            }
            cout << endl;
        }
#endif

        D.init(n);
        bool flag = true;
        vector< pair<int, int> > ans;
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 0; j < i; ++j) {
                mp[j] = -1;
            }
#ifndef ONLINE_JUDGE
            cout << "i " << i << endl;
#endif
            bool p_flag = false;
            for (int j = 0; j < n; ++j) {
#ifndef ONLINE_JUDGE
                cout << "j " << j << endl;
#endif
                if (mp[div_num[i][j]] == -1) {
                    mp[div_num[i][j]] = j;
                } else {
                    if (!D.check(j, mp[div_num[i][j]])) {
                        ans.push_back(make_pair(j, mp[div_num[i][j]]));
                        D.unite(j, mp[div_num[i][j]]);
                        p_flag = true;
                        break;
                    }
                }
            }
            if (!p_flag) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
            for (int i = ans.size() - 1; i >= 0; --i) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}