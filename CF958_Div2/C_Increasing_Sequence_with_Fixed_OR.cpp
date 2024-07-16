#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        vector<unsigned long long> ans;
        ans.push_back(n);
        unsigned long long p = 1;
        while (p > 0) {
            if (((n & p) > 0) && (n != p)) {
                ans.push_back(n ^ p);
            }
            p <<= 1;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}