#include <iostream>

#define int long long

using namespace std;

int neutral = 100000000000;
const int t_size = 262144;
int tree[t_size];
int cur_min[t_size];

bool rmq_request(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) {
        return false;
    }
    bool temp = false;
    if (tl == l && tr == r) {
        if (val > cur_min[v]) {
            temp = true;
        }
        if (tree[v] == neutral) {
            tree[v] = val;
            cur_min[v] = val;
        }
        else if (tree[v] != val) {
            temp = true;
        }
    }
    else {
        int tmid = (tl + tr) / 2;
        temp = (rmq_request(v * 2, tl, tmid, l, min(tmid, r), val) ||
        rmq_request(v * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r, val));
    }
    
    if (v < t_size / 2) {
        if (tree[v] != neutral && tree[v * 2] != neutral && tree[v * 2 + 1] != neutral &&
         tree[v] != min(tree[v * 2], tree[v * 2 + 1])) {
            temp = true;
         }
        if ((tree[v] != neutral && tree[v * 2] != neutral && tree[v] > tree[v * 2]) ||
         (tree[v] != neutral && tree[v * 2 + 1] != neutral && tree[v] > tree[v * 2 + 1])) {
            temp = true;
        }
        if (tree[v * 2] != neutral && tree[v * 2 + 1] != neutral) {
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
        if (cur_min[v * 2] != neutral || cur_min[v * 2 + 1] != neutral) {
            if (cur_min[v] > min(cur_min[v * 2], cur_min[v * 2 + 1])) {
                cur_min[v] = min(cur_min[v * 2], cur_min[v * 2 + 1]);   
            }
        }
        if (tree[v] != neutral && tree[v] > cur_min[v]) {
            temp = true;
        }
    }
    
    return temp;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < t_size; i++) {
        tree[i] = neutral;
        cur_min[i] = neutral;
    }

    int n, m, left, right, value;
    cin >> n >> m;
    bool consistent = true;
    for (int i = 0; i < m; i++) {
        cin >> left >> right >> value;
        bool res = rmq_request(1, 0, t_size / 2 - 1, left - 1, right - 1, value);
        if (res) {
            consistent = false;
            break;
        }
        cout << tree[t_size / 2] << " " << tree[t_size / 2 + 1] << " " << tree[t_size / 2 + 2] << " " << tree[t_size / 2 + 3] << " " << endl;
        cout << tree[t_size / 4] << " " << tree[(t_size / 2 + 2) / 2] << " " << endl;
        cout << tree[t_size / 8] << endl;
        cout << cur_min[t_size / 2] << " " << cur_min[t_size / 2 + 1] << " " << cur_min[t_size / 2 + 2] << " " << cur_min[t_size / 2 + 3] << " " << endl;
        cout << cur_min[t_size / 4] << " " << cur_min[(t_size / 2 + 2) / 2] << " " << endl;
        cout << cur_min[t_size / 8] << endl;
    }
    if (!consistent) {
        cout << "inconsistent";
    }
    else {
        cout << "consistent" << endl;
        int offset = t_size / 2;
        int *result = new int[n];
        for (int i = 0; i < n; i++) {
            int node = offset + i;
            while (tree[node] == neutral && node > 0) {
                node /= 2;
            }
            result[i] = tree[node];
            cout << min(result[i], (long long) 2147483647) << " ";
        }
    }
}