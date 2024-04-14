#include <iostream>
#include <vector>
#include <algorithm>

bool sortcol(const std::vector<double>& v1, const std::vector<double>& v2) {
    return v1[0] > v2[0];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, v, w;
    std::cin >> n >> k;
    std::vector <std::vector<double>> a;

    for (int i = 0; i < n; i++) {
        std::vector<double> temp;
        std::cin >> v >> w;
        temp.push_back(v / (double) w);
        temp.push_back(i + 1);
        a.push_back(temp);
    }

    std::sort(a.begin(), a.end(), sortcol);
    std::vector<int> b;
    for (int i = 0; i < k; i++) {
        b.push_back((int) a[i][1]);
    }
    std::sort(b.begin(), b.end());
    for (int i = 0; i < k; i++) {
        std::cout << b[i] << std::endl;
    }
}