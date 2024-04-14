#include <iostream>

using namespace std;

const int t_size = 2097152;
pair<int, int> tree[t_size];
int set[t_size];

void propagate(int);

void build_tree(int v, int tl, int tr, int n) {
    if (tl == tr) {
        tree[v].second = tl + 1;
        // cout << tree[v].second << endl;
        if (tl < n) {
            tree[v].first = 0;
        }
    }
    else {
        int tmid = (tl + tr) / 2;
        build_tree(v * 2, tl, tmid, n);
        build_tree(v * 2 + 1, tmid + 1, tr, n);
        tree[v].second = min(tree[v * 2].second, tree[v * 2 + 1].second);
        tree[v].first = min(tree[v * 2].first, tree[v * 2 + 1].first);
    }
}

void propagate(int v) {
    if (v < t_size) {
        tree[v].first = max(set[v], tree[v].first);
        set[v * 2] = max(set[v], set[v * 2]);
        set[v * 2 + 1] = max(set[v], set[v * 2 + 1]);
        set[v] = -1;
    }
}

void raise_wall(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        if (set[v] < val) {
            set[v] = val;
        }
    }
    else {
        propagate(v);
        int tmid = (tl + tr) / 2;
        raise_wall(v * 2, tl, tmid, l, min(tmid, r), val);
        raise_wall(v * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r, val);

        int min1, min2;
        if (v < t_size) {
            if (set[v * 2] > tree[v * 2].first) {
                min1 = set[v * 2];
            }
            else {
                min1 = tree[v * 2].first;
            }
            if (set[v * 2 + 1] > tree[v * 2 + 1].first) {
                min2 = set[v * 2 + 1];
            }
            else {
                min2 = tree[v * 2 + 1].first;
            }
            if (min1 < min2) {
                tree[v].first = min1;
                tree[v].second = tree[v * 2].second;
            }
            else {
                tree[v].first = min2;
                tree[v].second = tree[v * 2 + 1].second;
            }
        }
    }
}

pair<int, int> get_lowest_point(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        pair<int, int> bad;
        bad.first = 2000000000;
        bad.second = -1;
        return bad;
    }
    propagate(v);
    if (tl == l && tr == r) {
        pair<int, int> good;
        good.first = tree[v].first;
        good.second = tree[v].second;
        return good;
    }
    int tmid = (tl + tr) / 2;
    return min(get_lowest_point(v * 2, tl, tmid, l, min(tmid, r)),
     get_lowest_point(v * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < t_size; i++) {
        set[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    build_tree(1, 0, t_size / 2 - 1, n);
    string req;
    int left, right, height;
    for (int i = 0; i < m; i++) {
        cin >> req;
        if (req == "defend") {
            cin >> left >> right >> height;
            raise_wall(1, 0, t_size / 2 - 1, left - 1, right - 1, height);
        }
        else if (req == "attack") {
            pair<int, int> ans;
            cin >> left >> right;
            ans = get_lowest_point(1, 0, t_size / 2 - 1, left - 1, right - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}