#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = 1; i < y; ++i) {
            if ((i - y) & 1) {
                a[i] = -1;
            } else {
                a[i] = 1;
            }
        }
        for (int i = y; i <= x; ++i) {
            a[i] = 1;
        }
        for (int i = x + 1; i <= n; ++i) {
            if ((x - i) & 1) {
                a[i] = -1;
            } else {
                a[i] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i > 1) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << endl;
    }
}