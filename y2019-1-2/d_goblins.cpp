#include <iostream>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n;
    int size = 0;
    std::deque<int> left;
    std::deque<int> right;

    char s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (s == '+') {
            std::cin >> x;
            right.push_back(x);
            if (size % 2 == 0) {
                left.push_back(right.front());
                right.pop_front();
            }
            size++;
        }
        else if (s == '*') {
            std::cin >> x;
            if (size % 2 == 0) {
                left.push_back(x);
            }
            else {
                right.push_front(x);
            }
            size++;
        }
        else if (s == '-') {
            std::cout << left.front() << std::endl;
            left.pop_front();
            if (size % 2 == 0) {
                left.push_back(right.front());
                right.pop_front();
            }
            size--;
        }
    }   
}
