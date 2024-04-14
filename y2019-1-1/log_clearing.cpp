#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double v1, v2, a;
    std::cin >> v1 >> v2 >> a;
    double t1, t2, midl, midr, l = 0, r = 1;
    for (int i = 0; i < 100; i++) {
        midl = (l + r) / 2 - (r - l) / 6;
        midr = (l + r) / 2 + (r - l) / 6;
        t1 = sqrt(midl * midl + (1 - a) * (1 - a)) / v1 + sqrt((1 - midl) * (1 - midl) + a * a) / v2;
        t2 = sqrt(midr * midr + (1 - a) * (1 - a)) / v1 + sqrt((1 - midr) * (1 - midr) + a * a) / v2;
        if (t1 < t2) {
            r = midr;
        }
        else {
            l = midl;
        }
    }
    std::cout << std::setprecision(10) << l;
}