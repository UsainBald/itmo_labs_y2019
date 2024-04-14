#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double x, c, l = 0, r = 10e9, mid;
    std::cin >> c;
    for (int i = 0; i < 50; i++) {
        mid = (l + r) / 2;
        x = (mid * mid) + sqrt(mid);
        if (x > c) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    std::cout << std::setprecision(10) << r;
}