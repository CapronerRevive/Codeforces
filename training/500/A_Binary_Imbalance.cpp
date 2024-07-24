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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt[3] = {0};
        for (auto c : s) {
            cnt[c-'0']++;
        }
        if (cnt[0] > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}