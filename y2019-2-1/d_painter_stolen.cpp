#include <iostream>

const int t_size = 2097152;

int tree[t_size];
int set[t_size];
int segments[t_size];

void propagate(int v, int l, int r) {
    if (set[v] != -1) {
        segments[v] = set[v];
    }
    if (v < 1000000) {
        if (set[v] != -1) {
            if (set[v] == 1) {
                tree[v] = r - l + 1;
            }
            else {
                tree[v] = 0;
            }
            set[v * 2] = set[v];
            set[v * 2 + 1] = set[v];
            set[v] = -1;
        }
    }
}

bool leftisblack(int v, int l, int r) {
    propagate(v, l, r);

    if (tree[v * 2] == tree[v * 2 + 1])
        return (tree[v] == 1);

    return leftisblack(v * 2, l, (l + r) / 2);
}

bool rightisblack(int v, int l, int r) {
    propagate(v, l, r);

    if (tree[v * 2] == tree[v * 2 + 1])
        return (tree[v] == 1);

    return rightisblack(v * 2 + 1, (l + r) / 2 + 1, r);
}

void change(int color, int v, int tl, int tr, int l, int r) {
    // std::cout << 1;
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        // std::cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << std::endl;
        set[v] = color;
    }
    else {
        propagate(v, tl, tr);
        int tmid = (tl + tr) / 2;
        change(color, v * 2, tl, tmid, l, std::min(tmid, r));
        change(color, v * 2 + 1, tmid + 1, tr, std::max(l, tmid + 1), r);
        if (v < 1000000) {
            if (set[v * 2] == -1) {
                if (set[v * 2 + 1] == -1) {
                    tree[v] = tree[v * 2] + tree[v * 2 + 1];
                }
                else if (set[v * 2 + 1] == 0) {
                    tree[v] = tree[v * 2];
                }
                else if (set[v * 2 + 1] == 1) {
                    tree[v] = tree[v * 2] + tr - tmid;
                }
            }
            else if (set[v * 2] == 0) {
                if (set[v * 2 + 1] == -1) {
                    tree[v] = tree[v * 2 + 1];
                }
                else if (set[v * 2 + 1] == 0) {
                    tree[v] = 0;
                }
                else if (set[v * 2 + 1] == 1) {
                    tree[v] = tr - tmid;
                }
            }
            else if (set[v * 2] == 1) {
                if (set[v * 2 + 1] == -1) {
                    tree[v] = tmid - tl + 1 + tree[v * 2 + 1];
                }
                else if (set[v * 2 + 1] == 0) {
                    tree[v] = tmid - tl + 1;
                }
                else if (set[v * 2 + 1] == 1) {
                    tree[v] = tmid - tl + 1 + tr - tmid;
                }
            }
        }
        bool left = rightisblack(v * 2, l, (l + r) / 2);
        bool right = leftisblack(v * 2 + 1, (l + r) / 2 + 1, r) ;

        segments[v] = segments[v * 2 + 1] + segments[v * 2];

        if (left && right) {
            segments[v]--;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    for (int i = 0; i < t_size; i++) {
        tree[i] = 0;
        set[i] = -1;
    }

    int n, left, length;
    std::cin >> n;
    char x;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> left >> length;
        if (x == 'W') {
            change(0, 1, 0, t_size / 2 - 1, left + 500000, left + 500000 + length - 1);
        }
        else if (x == 'B') {
            change(1, 1, 0, t_size / 2 - 1, left + 500000, left + 500000 + length - 1);
        }
        std::cout << segments[1] << " " << tree[1] << std::endl;
    }
}