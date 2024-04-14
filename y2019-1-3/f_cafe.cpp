#include <iostream>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n;
    std::pair<int, int> **d = new std::pair<int, int>*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new std::pair<int, int>[n];
    }
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j].first = 1000000000;
            d[i][j].second = -1;
        }
    }
    if (a[0] > 100) {
        d[0][1].first = a[0];
    }
    else {
        d[0][0].first = a[0];
    }
    d[0][1].second = -1;
    d[0][0].second = -1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i - 1][j].first != 1000000000) {
                if (j != 0) {
                    if (d[i - 1][j].first < d[i][j - 1].first) {
                        d[i][j - 1].first = d[i - 1][j].first;
                        d[i][j - 1].second = j;
                    }
                }

                if (a[i] > 100) {
                    if (d[i - 1][j].first + a[i] < d[i][j + 1].first) {
                        d[i][j + 1].first = d[i - 1][j].first + a[i];
                        d[i][j + 1].second = j;
                    }
                }
                else {
                    if (d[i - 1][j].first + a[i] < d[i][j].first) {
                        d[i][j].first = d[i - 1][j].first + a[i];
                        d[i][j].second = j;
                    }
                }
            }
        }
    }
    int best = 1000000000, coupons_left = 0;
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            if (d[n - 1][i].first <= best) {
                best = d[n - 1][i].first;
                coupons_left = i;
            }
        }
        std::cout << best << std::endl;
        int coupons_used = 0, b_size = 0;
        int *b = new int[n + 1];
        int i = coupons_left, day = n - 1;
        // for (int i1 = 0; i1 < n; i1++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cout << std::setw(10) << d[i1][j].first << " " << d[i1][j].second << "   ";
        //     }
        //     std::cout << std::endl;
        // } 
        while (d[day][i].second != -1) {
            if (d[day][i].second > i) {
                b[b_size++] = day + 1;
            }
            i = d[day][i].second;
            day--;
        }
    
        std::cout << coupons_left << " " << b_size << std::endl;
        for (int j = 0; j < b_size; j++) {
            std::cout << b[b_size - j - 1] << std::endl;
        }
    } 
    else if (n == 1) {
        std::cout << a[0] << std::endl; 
        if (a[0] > 100) {
            std::cout << 1 << " " << 0 << std::endl;
        }
        else {  
            std::cout << 0 << " " << 0 << std::endl;
        }
    }
    else {
        std::cout << 0 << std::endl;
        std::cout << 0 << " " << 0 << std::endl;
    }
}