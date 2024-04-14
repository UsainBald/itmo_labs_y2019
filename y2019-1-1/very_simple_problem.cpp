#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, y, sum = 0;
    std::cin >> n >> x >> y;
    int a = std::min(x, y);
    int b = std::max(x, y);
    sum += a;
    n--;
    double z;
    z = (n * b) / (double) (a + b);
    int z1 = (int) z;
    int z2 = (int) z + 1;
    if (std::max(a * z1, b * (n - z1)) < std::max(a * z2, b * (n - z2))) {
        sum += std::max(a * z1, b * (n - z1));
    }
    else {
        sum += std::max(a * z2, b * (n - z2));
    }

    std::cout << sum;
}