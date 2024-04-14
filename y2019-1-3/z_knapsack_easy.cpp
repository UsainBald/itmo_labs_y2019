#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int w, n;
    std::cin >> w >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int **d = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        d[i] = new int[w + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        d[i][0] = 1;
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            d[i][j] = 0;
        }
    }
    std::sort(a, &a[n]);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            if (j - a[i - 1] >= 0) {
                d[i][j] = d[i - 1][j] || d[i - 1][j - a[i - 1]];
            }
            else {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    for (int i = w; i > -1; i--) {
        if(d[n][i]) {
            std::cout << i;
            break;
        }
    }
}