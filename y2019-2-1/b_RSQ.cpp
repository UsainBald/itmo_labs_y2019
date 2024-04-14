#include <iostream>

#define int long long

int range_sum(int* t, int cur, int left, int right, int l, int r) {
    // std::cout << cur << "  " << left << "  " << right << std::endl;
    if (left >= r || right <= l) {
        return 0;
    }
    if (left >= l && right <= r) {
        return t[cur];
    }
    return range_sum(t, cur * 2 + 1, left, (left + right) / 2, l, r) + range_sum(t, cur * 2 + 2, (left + right) / 2, right, l, r);
}

signed main() {
    int x;
    std::cin >> x;
    int n = x;
    n = n - 1;
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    n++;
    
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < x; i++) {
        std::cin >> a[i];
    }

    int *tree = new int[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++) {
        tree[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        tree[n - 1 + i] = a[i];
    }
    for (int i = n - 2; i > -1; i--) {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    // for (int i = 0; i < 2 * n - 1; i++) {
    //     std::cout << tree[i] << " ";
    // }

    std::string s;
    int x1, y;
    while (std::cin >> s) {
        if (s == "set") {
            std::cin >> x1 >> y;
            x1 += n - 2;
            tree[x1] = y;
            while (x1 > 0) {
                x1 = (x1 - 1) / 2;
                tree[x1] = tree[2 * x1 + 1] + tree[2 * x1 + 2];
            } 
        }
        else if (s == "sum") {
            std::cin >> x1 >> y;
            x1--;
            std::cout << range_sum(tree, 0, 0, n, x1, y) << std::endl;
        }
    }
}