#include <iostream>

#define int long long

void build(int*, int*, int, int, int);
void propagate(int*, int*, int*, int, int);
void change(int*, int*, int*, int, int, int, int, int, int, int);
void segment_add(int*, int*, int*, int, int, int, int, int, int, int);
int segment_min(int*, int*, int*, int, int, int, int, int, int);

void build(int* tree, int* a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl]; 
    }
    else {
        int tmid = (tl + tr) / 2;
        build(tree, a, v * 2, tl, tmid);
        build(tree, a, v * 2 + 1, tmid + 1, tr);
        tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
    }
}

void propagate(int* tree, int* set, int* add, int v, int size) {
    if (v < size) {
        if (set[v] != -4000000000000000000) {
            tree[v] = set[v];
            set[v * 2] = set[v];
            add[v * 2] = 0;
            set[v * 2 + 1] = set[v];
            add[v * 2 + 1] = 0;
            set[v] = -4000000000000000000;
        }
        else {
            tree[v] += add[v];
            if (set[v * 2] != -4000000000000000000) {
                set[v * 2] += add[v];
            }
            else {
                add[v * 2] += add[v];
            }
            if (set[v * 2 + 1] != -4000000000000000000) {
                set[v * 2 + 1] += add[v];
            }
            else {
                add[v * 2 + 1] += add[v];
            }
            add[v] = 0;
        }
    }
}

void change(int* tree, int* set, int* add, int v, int tl, int tr, int l, int r, int val, int size) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        std::cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << size << " " << std::endl;
        set[v] = val;
        add[v] = 0;
    }
    else {
        propagate(tree, set, add, v, size);
        int tmid = (tl + tr) / 2;
        change(tree, set, add, v * 2, tl, tmid, l, std::min(r, tmid), val, size);
        change(tree, set, add, v * 2 + 1, tmid + 1, tr, std::max(l, tmid + 1), r, val, size);
        if (set[v * 2] == -4000000000000000000) {
            if (set[v * 2 + 1] == -4000000000000000000) {
                tree[v] = std::min(tree[v * 2] + add[v * 2], tree[v * 2 + 1] + add[v * 2 + 1]);
            }
            else {
                tree[v] = std::min(tree[v * 2] + add[v * 2], set[v * 2 + 1]);
            }
        }
        else {
            if (set[v * 2 + 1] == -4000000000000000000) {
                tree[v] = std::min(set[v * 2], tree[v * 2 + 1] + add[v * 2 + 1]);
            }
            else {
                tree[v] = std::min(set[v * 2], set[v * 2 + 1]);
            }
        }
    }
}

void segment_add(int* tree, int* set, int* add, int v, int tl, int tr, int l, int r, int val, int size) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        if (set[v] != -4000000000000000000) {
            set[v] += val;
        }
        else {
            add[v] += val;
        }
    }
    else {
        propagate(tree, set, add, v, size);
        int tmid = (tl + tr) / 2;
        segment_add(tree, set, add, v * 2, tl, tmid, l, std::min(r, tmid), val, size);
        segment_add(tree, set, add, v * 2 + 1, tmid + 1, tr, std::max(l, tmid + 1), r, val, size);
        if (set[v * 2] == -4000000000000000000) {
            if (set[v * 2 + 1] == -4000000000000000000) {
                tree[v] = std::min(tree[v * 2] + add[v * 2], tree[v * 2 + 1] + add[v * 2 + 1]);
            }
            else {
                tree[v] = std::min(tree[v * 2] + add[v * 2], set[v * 2 + 1] + add[v * 2 + 1]);
            }
        }
        else {
            if (set[v * 2 + 1] == -4000000000000000000) {
                tree[v] = std::min(set[v * 2] + add[v * 2], tree[v * 2 + 1] + add[v * 2 + 1]);
            }
            else {
                tree[v] = std::min(set[v * 2] + add[v * 2], set[v * 2 + 1] + add[v * 2 + 1]);
            }
        }
    }
}

int segment_min(int* tree, int* set, int* add, int v, int tl, int tr, int l, int r, int size) {
    // std::cout << 1;
    if (l > r) {
        return 4000000000000000000;
    }
    if (l == tl && r == tr) {
        if (set[v] == -4000000000000000000) {
            return tree[v] + add[v];
        }
        else {
            return set[v];
        }
    }
    propagate(tree, set, add, v, size);
    int tmid = (tl + tr) / 2;
    return std::min(segment_min(tree, set, add, v * 2, tl, tmid, l, std::min(tmid, r), size),
     segment_min(tree, set, add, v * 2 + 1, tmid + 1, tr, std::max(l, tmid + 1), r, size));
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    int x = n - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x++;
    int *a = new int[x];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = n; i < x; i++) {
        a[i] = 4000000000000000000;
    }
    int* tree = new int[2 * x];
    int* add = new int[2 * x];
    int* set = new int[2 * x];
    for (int i = 0; i < 2 * x; i++) {
        add[i] = 0;
        set[i] = -4000000000000000000;
    }
    tree[0] = -4000000000000000000;
    build(tree, a, 1, 0, x - 1);
    // for (int i = 0; i < 2 * x; i++) {
    //     std::cout << tree[i] << " ";
    // }
    std::string req;
    int left, right, val;
    while (std::cin >> req) {
        if (req == "min") {
            std::cin >> left >> right;
            std::cout << segment_min(tree, set, add, 1, 0, x - 1, left - 1, right - 1, x) << std::endl;
        }
        else if (req == "set") {
            std::cin >> left >> right >> val;
            change(tree, set, add, 1, 0, x - 1, left - 1, right - 1, val, x);
            // for (int i = 0; i < 2 * x; i++) {
            //     std::cout << tree[i] << " " << set[i] << std::endl;
            // }
        }
        else if (req == "add") {
            std::cin >> left >> right >> val;
            segment_add(tree, set, add, 1, 0, x - 1, left - 1, right - 1, val, x);
            // for (int i = 0; i < 2 * x; i++) {
            //     std::cout << tree[i] << " " << set[i] << " " << add[i] << std::endl;
            // }
        }
    }
}
