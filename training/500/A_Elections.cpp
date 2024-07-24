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
        LL a, b, c;
        cin >> a >> b >> c;
        LL A = max(max(0LL, b - a + 1), max(0LL, c - a + 1));
        LL B = max(max(0LL, a - b + 1), max(0LL, c - b + 1));
        LL C = max(max(0LL, a - c + 1), max(0LL, b - c + 1));
        cout << A << " " << B << " " << C << endl;
    }
}