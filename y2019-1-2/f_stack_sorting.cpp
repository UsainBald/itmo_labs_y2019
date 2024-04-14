#include <iostream>
#include <stack>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a[i] = x; 
    }
    std::stack<int> a_stack; 
    std::stack<int> b_stack;

    for (int i = 0; i < n; i++) {
        a_stack.push(a[n - i - 1]);
    }
    std::sort(a, &a[n]);
    int next = 0;
    int *operations = new int[4000];
    int op = 0;
    while (true) {
        b_stack.push(a_stack.top());
        a_stack.pop();
        operations[op++] = 0;
        int s = b_stack.size();
        for (int i = 0; i < s; i++) {
            if (!(b_stack.top() == a[next])) {
                break;
            }
            else {
                operations[op] = 1;
                b_stack.pop();
                next++;
                op++;
            }
        }
        if (a_stack.empty()) {
            break;
        }
    }
    if (!b_stack.empty()) {
        std::cout << "impossible";
    }
    else {
        for (int i = 0; i < op; i++) {
            if (operations[i] == 0) {
                std::cout << "push" << std::endl;
            }
            else {
                std::cout << "pop" << std::endl;
            }
        }
    }
}