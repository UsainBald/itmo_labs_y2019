#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int W, n;
    std::cin >> n >> W;
    std::pair<int, int> *w = new std::pair<int, int>[n];
    for (int i = 0; i < n; i++) {
        std::cin >> w[i].first;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> w[i].second;
    }
    // for (int i = 0; i < n + 1; i++) {
    //     std::cout << w[i].first << " " << w[i].second << "    ";
    // }
    // std::cout << std::endl;
    int **d = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        d[i] = new int[W + 1];
    }
    int **from = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        from[i] = new int[W + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            d[i][j] = 0;
            from[i][j] = -1;
        }
    }

    std::sort(w, &w[n]);
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (j - w[i - 1].first >= 0) {
                if (d[i - 1][j] > (d[i - 1][j - w[i - 1].first] + w[i - 1].second)) {
                    d[i][j] = d[i - 1][j];
                    from[i][j] = j;
                }
                else {
                    d[i][j] = d[i - 1][j - w[i - 1].first] + w[i - 1].second;
                    from[i][j] = j - w[i - 1].first;
                }
            }
            else {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            std::cout << from[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int max_cost = 0;
    for (int i = 0; i < W + 1; i++) {
        if(d[n][i] > max_cost) {
            max_cost = d[n][i];
        }
    }
    std::cout << max_cost;
}