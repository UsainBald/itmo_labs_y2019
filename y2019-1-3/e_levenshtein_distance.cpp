#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;
    int **d = new int*[a.size() + 1];
    for (int i = 0; i < a.size() + 1; i++) {
        d[i] = new int[b.size() + 1];
    }
    d[0][0] = 0;
    for (int i = 1; i < a.size() + 1; i++) {
        d[i][0] = i;
    }
    for (int i = 1; i < b.size() + 1; i++) {
        d[0][i] = i;
    }
    int add = 0;
    for (int i = 1; i < a.size() + 1; i++) {
        for (int j = 1; j < b.size() + 1; j++) {
            if (a[i - 1] == b[j - 1]) {
                add = 0;
            }
            else {
                add = 1;
            }
            d[i][j] = std::min(std::min(d[i][j - 1] + 1, d[i - 1][j - 1] + add), d[i - 1][j] + 1);
        }
    }
    std::cout << d[a.size()][b.size()];
}