#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 500000 + 10;

struct TreeNode {
    ULL val;
    int par;
    int left, right;
    ULL count, left_count, right_count;
    TreeNode(ULL _val = 0){
        val = _val;
        par = -1;
        left = -1;
        right = -1;
    }
} tree[N];

int root;

void Build(vector<ULL> &val) {
    root = 0;
    tree[0] = TreeNode(val[0]);
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i < val.size(); ++i) {
        int left_idx = -1;
        while (!stk.empty()) {
            if (val[i] > tree[stk.top()].val) {
                break;
            }
            left_idx = stk.top();
            stk.pop();
        }
        tree[i] = TreeNode(val[i]);
        tree[i].left = left_idx;
        if (left_idx != -1) {
            if (left_idx != root) {
                int par = tree[left_idx].par;
                tree[par].right = i;
                tree[i].par = par;
            } else {
                root = i;
            }
            tree[left_idx].par = i;
        } else {
            tree[stk.top()].right = i;
            tree[i].par = stk.top();
        }
        stk.push(i);
    }
}

ULL InitCount(int idx) {
    tree[idx].left_count = 0;
    tree[idx].right_count = 0;
    if (tree[idx].left != -1) {
        tree[idx].left_count = InitCount(tree[idx].left);
    }
    if (tree[idx].right != -1) {
        tree[idx].right_count = InitCount(tree[idx].right);
    }
    tree[idx].count = 1 + tree[idx].left_count + tree[idx].right_count;
    return tree[idx].count;
}

vector<ULL> val;
vector<ULL> ans;
ULL sum;

void GetAns(int idx) {
    int sons[2];
    ULL plus = 0;
    sons[0] = tree[idx].left;
    sons[1] = tree[idx].right;
    while (sons[0] >= 0 && sons[1] >= 0) {
        if (sons[0] == -1) {
            plus += tree[sons[1]].val * (tree[sons[1]].right_count + 1);
            sons[1] = tree[sons[1]].left;
        } else if (sons[1] == -1) {
            plus += tree[sons[0]].val * (tree[sons[0]].left_count + 1);
            sons[0] = tree[sons[0]].right;
        } else if (tree[sons[0]].val < tree[sons[1]].val) {
            plus += tree[sons[0]].val * tree[sons[1]].count * (tree[sons[0]].left_count + 1);
            sons[0] = tree[sons[0]].right;
        } else {
            plus += tree[sons[1]].val * tree[sons[0]].count * (tree[sons[1]].right_count + 1);
            sons[1] = tree[sons[1]].left;
        }
    }
    ULL self_sum = tree[idx].val * (tree[idx].left_count + 1) * (tree[idx].right_count + 1);
#ifndef ONLINE_JUDGE
    cout << "---\t" << sum << " " << self_sum << " " << plus << endl;
#endif
    ans[idx] = sum - self_sum + plus;
    if (tree[idx].left != -1) {
        sum -= tree[idx].val * (tree[idx].right_count + 1);
        GetAns(tree[idx].left);
        sum += tree[idx].val * (tree[idx].right_count + 1);
    }
    if (tree[idx].right != -1) {
        sum -= tree[idx].val * (tree[idx].left_count + 1);
        GetAns(tree[idx].right);
        sum += tree[idx].val * (tree[idx].left_count + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        val.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> val[i];
        }
#ifndef ONLINE_JUDGE
        cout << "Build!" << endl;
#endif
        Build(val);
#ifndef ONLINE_JUDGE
        cout << "Init Count!" << endl;
#endif
        InitCount(root);

#ifndef ONLINE_JUDGE
        for (int i = 0; i < n; ++i) {
            cout << i << " " << tree[i].val 
                      << " " << tree[i].left
                      << " " << tree[i].right
                      << " " << tree[i].count
                      << " " << tree[i].left_count
                      << " " << tree[i].right_count << endl;
        }
#endif

        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += tree[i].val * (tree[i].left_count + 1) * (tree[i].right_count + 1);
        }
#ifndef ONLINE_JUDGE
        cout << sum << endl;
#endif

        ans.resize(n);
        GetAns(root);
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }
}