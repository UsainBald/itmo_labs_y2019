#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, x;
    std::cin >> n >> k;
    n -= 2;
    int *a = new int[n + 2];
    a[0] = 0;
    a[n + 1] = 0;
    for (int i = 1; i < n + 1; i++) {
        std::cin >> x;
        a[i] = x;
    }

    std::pair<int, int> *b = new std::pair<int, int>[n + 2];
    b[0].first = 0;
    b[0].second = 0;
    b[1].first = a[1];
    b[1].second = 1;
    for (int i = 2; i < n + 2; i++) {
        b[i].first = -2000000000;
        for (int j = 1; j < k + 1; j++) {
            if (i - j >= 0) {
                if (b[i - j].first + a[i] > b[i].first) {
                    b[i].first = b[i - j].first + a[i];
                    b[i].second = i - j + 1;
                }
            }
        }
    }
    std::cout << b[n + 1].first << std::endl;
    int *c = new int[n + 1];
    int j = n + 1;
    k = 0;
    while (b[j].second != 0) {
        c[k++] = b[j].second;
        j = b[j].second - 1;
    }
    std::cout << k << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << c[k - i - 1] << " ";
    }
    std::cout << n + 2;
}