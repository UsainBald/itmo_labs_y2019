#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    struct stack {
        std::pair<int, int> *a = new std::pair<int, int>[1000001];
        int n = 1;
        stack() {
            a[0].first = 0;
            a[0].second = 2000000000;
        }
        void put(int x) {
            a[n].first = x;
            if (a[n].first < a[n - 1].second) {
                a[n].second = a[n].first;
            }
            else {
                a[n].second = a[n - 1].second;
            }
            n++;
        }

        void pop() {
            n--;
        }

        int get_min() {
            return a[n - 1].second;
        }
    };

    stack a;
    int n, k, x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        if (k == 1) {
            std::cin >> x;
            a.put(x);
        }
        else if (k == 2) {
            a.pop();
        }
        else if (k == 3) {
            std::cout << a.get_min() << std::endl;
        }
    }
}