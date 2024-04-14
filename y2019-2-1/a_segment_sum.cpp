#include <iostream>

int main() {
    #define int long long
    int n, x, y, a0;
    std::cin >> n >> x >> y >> a0;
    int* a = new int[n];
    a[0] = a0;
    for (int i = 1; i < n; i++) {
        a[i] = (x * a[i - 1] + y) < 0 ? (x * a[i - 1] + y) % (1 << 16) + (1 << 16) : (x * a[i - 1] + y) % (1 << 16);
    }

    int m, z, t, b0;
    std::cin >> m >> z >> t >> b0;
    int *b = new int[2 * m];
    b[0] = b0;
    for (int i = 1; i < 2 * m; i++) {
        b[i] = (z * b[i - 1] + t) < 0 ? (z * b[i - 1] + t) % (1 << 30) + (1 << 30) : (z * b[i - 1] + t) % (1 << 30);
    }

    int *c = new int[2 * m];
    for (int i = 0; i < 2 * m; i++) {
        c[i] = b[i] % n;
    }

    int *sums = new int[n];
    sums[0] = a[0];
    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + a[i];
    }

    int sus = 0;
    int l, r;
    for (int i = 0; i < m; i++) {
        l = std::min(c[2 * i], c[2 * i + 1]);
        r = std::max(c[2 * i], c[2 * i + 1]);
        if (l == 0) {
            sus += sums[r];
        }
        else {
            sus += (sums[r] - sums[l - 1]);
        }
    }

    // for (int i = 0; i < 2 * m; i++) {
    //     std::cout << b[i] << " ";
    // }
    // std::cout << std::endl;

    std::cout << sus;
}