#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, k, x;
    std::cin >> n >> k;
    long long *a = new long long[n + 2];
    a[0] = -9000000000000000000;
    a[n + 1] = 9000000000000000000;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a[i + 1] = x;
    }
    int l = 0, r = n + 1, mid;
    for (int i = 0; i < k; i++) {
        std::cin >> x;
        while ((r - l) > 1) {
            mid = (l + r) / 2;
            if (a[mid] > x) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (x - a[l] <= a[r] - x) {
            std::cout << a[l] << std::endl;
        }
        else {
            std::cout << a[r] << std::endl;
        }
        l = 0;
        r = n + 1;
    }
}