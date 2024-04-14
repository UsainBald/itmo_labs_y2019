#include <iostream>

int split(int l, int r, int* a) {
    std::swap(a[l + rand() % (r - l)], a[r]);
    int x = a[r];
    int i = l;
    for (int j = l; j <= r; j++) {
        if (a[j] <= x) {
            std::swap(a[i++], a[j]);
        }
    }
    return i - 1;
}

int kth(int* a, int k, int a_size) {
    int l = 0, r = a_size - 1;
    while (true) {
        int pos = split(l, r, a);
        if (k == pos) {
            return a[pos];
        }
        else if (k > pos) {
            l = pos + 1;
        }
        else {
            r = pos - 1;
        }
        
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    srand(time(0));
    int n, x;
    std::cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a[i] = x;
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << kth(a, 3, n) << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

}