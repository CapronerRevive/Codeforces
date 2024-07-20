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
        string t;
        cin >> t;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (t[i] != '0') {
                    flag = false;
                    break;
                }
            } else {
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