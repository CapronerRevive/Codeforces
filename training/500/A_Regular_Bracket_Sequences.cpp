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
        for (int i = 0; i < n; ++i) {
            cout << "()";
        }
        cout << endl;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (j == i) {
                    cout << "(())";
                } else {
                    cout << "()";
                }
            }
            cout << endl;
        }
    }
}