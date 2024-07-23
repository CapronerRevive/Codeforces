#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[100];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            a[b] += 1;
        }
        bool flag = false;
        for (int i = 0; i < 100; ++i) {
            if (a[i] & 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}