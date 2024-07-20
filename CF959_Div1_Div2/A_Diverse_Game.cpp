#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 100000 + 10;

int a[15][15];

int main() {
    int t;
    cin >> t;
    while (t--) {
        // enter code
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        if (n == 1 && m == 1) {
            cout << -1 << endl;
        } else {
            int tmp = a[0][0];
            for (int k = 1; k < n * m; ++k) {
                int i = k / m;
                int j = k % m;
                int ppi = (k-1) / m;
                int ppj = (k-1) % m;
                // cout << ppi << " " << ppj << " " << i << " " << j << endl;
                a[ppi][ppj] = a[i][j];
            }
            a[n-1][m-1] = tmp;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (j) {
                        cout << " ";
                    }
                    cout << a[i][j];
                }
                cout << endl;
            }
        }

    }
}