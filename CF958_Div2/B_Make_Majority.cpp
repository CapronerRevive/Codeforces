#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0;
        int b = 0;
        bool zero_flag = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (zero_flag) {
                    continue;
                } else {
                    zero_flag = true;
                }
            } else {
                if (zero_flag) {
                    b += 1;
                    zero_flag = false;
                }
                a += 1;
            }
        }
        if (zero_flag) {
            b += 1;
        }
        if (a > b) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}