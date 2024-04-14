#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, x, size = 2, count = 0, cur = -1, sum = 0;
    std::cin >> n;
    int *a = new int[n + 2];
    a[0] = -2;
    a[1] = -3;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (count >= 3 && x != cur) {
            size -= count;
            sum += count;
            if (a[size - 1] == a[size - 2]) {
                count = 2;
            }
            else {
                count = 1;
            }
            cur = a[size - 1];
        }
        a[size++] = x;
        if (cur == x) {
            count++;
        }
        else {
            cur = x;
            count = 1;
        }
    }
    if (count >= 3) {
        size -= count;
        sum += count;
        if (a[size - 1] == a[size - 2]) {
            count = 2;
        }
        else {
            count = 1;
        }
        cur = a[size - 1];
    }
    std::cout << sum;
}