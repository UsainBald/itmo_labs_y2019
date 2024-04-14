#include <iostream>

#define int unsigned int

int rmq(int** st, int* logs, int l, int r) {
    int t = logs[r - l];
    return std::min(st[t][l], st[t][r - (1 << t)]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, a1;
    std::cin >> n >> m >> a1;
    int *a = new int[n];
    a[0] = a1;
    for (int i = 1; i < n; i++) {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
    }
    int *logs = new int[n + 1];
    logs[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        logs[i] = logs[i >> 1] + 1;
    }
    int **st = new int*[logs[n] + 1];
    for (int i = 0; i < logs[n] + 1; i++) {
        st[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }
    for (int l = 1; l < logs[n] + 1; l++) {
        for (int i = 0; i + (1 << l) - 1 < n; i++) {
            st[l][i] = std::min(st[l - 1][i], st[l - 1][i + (1 << (l - 1))]);
        }
    }
    int u, v, r;
    std::cin >> u >> v;
    r = rmq(st, logs, (std::min(u, v) - 1), std::max(u, v));
    for (int i = 1; i < m; i++) {
        u = (17 * u + 751 + r + 2 * (i)) % n + 1;
        v = (13 * v + 593 + r + 5 * (i)) % n + 1;
        r = rmq(st, logs, (std::min(u, v) - 1), std::max(u, v));
    }
    std::cout << u << " " << v << " " << r << std::endl;
}