#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 200000 + 10;

LL A[N], B[N];

unordered_map<LL, LL> mp;

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        LL n, m;
        cin >> n >> m;
        mp.clear();
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
            mp[A[i]] = B[i];
        }
        LL ans = 0;
        for (auto d : mp) {
            if (d.first == 0) {
                continue;
            }
            LL cnt = m / d.first;
            cnt = min(cnt, d.second);
            LL k = d.first * cnt;
            ans = max(ans, k);
        }
        for (auto d : mp) {
            if (mp.find(d.first-1) == mp.end()) {
                continue;
            }
            LL a = d.second;
            LL b = mp[d.first-1];
            LL begin = 1, end = a + b;
            bool flag = false;
            while (begin <= end) {
                if (begin == end) {
                    flag = true;
                }
                LL mid = (begin + end) / 2;
                LL amin = 0;
                if (mid > b) {
                    amin = b * (d.first - 1) + (mid - b) * d.first;
                } else {
                    amin = mid * (d.first - 1);
                }
                LL amax = 0;
                if (mid > a) {
                    amax = a * d.first + (mid - a) * (d.first - 1);
                } else {
                    amax = mid * d.first;
                }
                if (m > amax) {
                    ans = max(ans, amax);
                    if (begin == mid) {
                        begin = mid + 1;
                    } else {
                        begin = mid;
                    }
                } else if (m < amin) {
                    if (end == mid) {
                        end = mid - 1;
                    } else {
                        end = mid;
                    }
                } else {
                    ans = m;
                    break;
                }
                if (flag) {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}