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
        LL u, v;
        cin >> u >> v;
        LL x = u * u;
        x *= -1;
        LL y = v * v;
        cout << x << " " << y << endl;
    }
}