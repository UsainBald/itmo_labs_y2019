#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int w, h, n, a;
    std::cin >> w >> h >> n;
    a = std::max(w, h);
    int l = 0, r = 1000000000, mid;
    while ((r - l) > 0) {
        mid = (r + l) / 2;
        if (((mid / h) / (double) n * (mid / w)) >= 1) {
            r = mid;
        } 
        else {
            l = mid + 1;
        }
    }
    std::cout << r;
}