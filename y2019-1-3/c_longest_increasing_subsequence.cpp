#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a[i] = x;
    }
    std::pair<int, int> *d = new std::pair<int, int>[n];
    int *from = new int[n];
    from[0] = -1;
    d[0].first = a[0];
    d[0].second = 0;
    for (int i = 1; i < n; i++) {
        d[i].first = 1000000007;
    }

    int to_find, l, r, m;
    for (int i = 1; i < n; i++) {
        l = -1;
        r = n;
        to_find = a[i];
        while (r - l > 1) {
            m = (l + r) / 2;
            if (d[m].first >= to_find) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (d[l + 1].first > to_find) {
            d[l + 1].first = to_find;
            d[l + 1].second = i;
            if (l == -1) {
                from[i] = -1;
            }
            else {
                from[i] = d[l].second;
            }
        }
    }
    l = -1;
    r = n;
    to_find = 1000000006;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (d[m].first > to_find) {
            r = m;
        }
        else {
            l = m;
        }
    }
    std::cout << l + 1 << std::endl;
    int len = l + 1;
    int *f = new int[len];
    int j = 0;
    l = d[l].second;
    while (l != -1) {
        f[j++] = l;
        l = from[l];
    }
    for (int i = 0; i < len; i++) {
        std::cout << a[f[len - i - 1]] << " ";
    }
}